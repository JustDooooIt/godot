#ifndef __SAFEPOINT_H__
#define __SAFEPOINT_H__

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
	std::mutex _mtx;
	std::condition_variable _cv;
	std::atomic<bool> _is_active{ false };
	std::atomic<int> _total_threads{ 0 };
	int _waiting_threads = 0;

	Safepoint() = default;

public:
	static Safepoint *get_singleton() {
		static Safepoint *instance = new Safepoint();
		return instance;
	}

	void thread_started() {
		_total_threads++;
	}

	void thread_stoped() {
		_total_threads--;
	}

	void enter() {
		if (_is_active.load()) {
			std::unique_lock<std::mutex> lock(_mtx);
			_waiting_threads++;
			_cv.wait(lock, [this]() { return !this->_is_active.load(); });
			_waiting_threads--;
		}
	}

	void begin() {
		_is_active.store(true);
	}

	void end() {
		_is_active.store(false);
		_cv.notify_all();
	}

	bool is_all_threads_entered_safepoint() const {
		return _is_active.load() && _waiting_threads == _total_threads.load();
	}
};

#endif // __SAFEPOINT_H__