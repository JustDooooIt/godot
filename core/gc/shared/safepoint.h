#ifndef __SAFEPOINT_H__
#define __SAFEPOINT_H__

// #include "core/variant/variant_utility.h"
#include <atomic>
#include <condition_variable>
#include <mutex>

#define ENTER_SAFEPOINT Safepoint::get_singleton()->enter();
#define PAUSE_SAFEPOINT Safepoint::get_singleton()->begin();
#define RESUME_SAFEPOINT Safepoint::get_singleton()->end();
#define THREAD_STARTED Safepoint::get_singleton()->thread_started();
#define THREAD_STOPED Safepoint::get_singleton()->thread_stoped();

class Safepoint {

private:
	std::mutex mtx;
	std::condition_variable cv;
	std::atomic<bool> is_active{ false };
	std::atomic<int> total_threads{ 1 };
	int waiting_threads = 0;

	Safepoint() = default;

public:
	static Safepoint *get_singleton() {
		static Safepoint *instance = new Safepoint();
		return instance;
	}

	void thread_started() {
		total_threads++;
	}

	void thread_stoped() {
		total_threads--;
	}

	void enter() {
		// String msg = "entered";
		// const Variant msg_ptr = msg;
		// const Variant *msg_p = &msg_ptr;
		// Callable::CallError err;
		// VariantUtilityFunctions::print(&msg_p, 1, err);
		if (is_active.load()) {
			std::unique_lock<std::mutex> lock(mtx);
			waiting_threads++;
			cv.wait(lock);
			waiting_threads--;
		}
	}

	void begin() {
		is_active.store(true);
	}

	void end() {
		is_active.store(false);
		cv.notify_all();
	}

	bool is_all_threads_entered_safepoint() {
		return is_active.load() && waiting_threads == total_threads.load();
	}
};

#endif // __SAFEPOINT_H__