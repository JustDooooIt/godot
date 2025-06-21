#ifndef __G1GCMANAGER_H__
#define __G1GCMANAGER_H__

#include "core/os/thread.h"
#include <atomic>
#include <condition_variable>
#include <mutex>

static void exec_gc(void *ud);

class G1GCManager {
private:
	std::mutex _mtx;
	std::condition_variable _cv;
	Thread _thread;
	std::atomic<bool> _closed{ true };
	G1GCManager();

public:
	static G1GCManager *get_singleton() {
		static G1GCManager *instance = new G1GCManager();
		return instance;
	}

	void start_gc();
	void run_gc();
	void stop_gc();
	void wait_for_safepoints();
	void start_gc_thread();
	void stop_gc_thread();
	bool closed() const { return _closed.load(); }
};
#endif // __G1GCMANAGER_H__