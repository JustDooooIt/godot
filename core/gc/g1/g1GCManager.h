#ifndef __G1GCMANAGER_H__
#define __G1GCMANAGER_H__

#include "core/os/thread.h"
#include <atomic>
#include <condition_variable>
#include <mutex>

void exec_gc(void *ud);

class G1GCManager {
private:
	std::mutex mtx;
	std::condition_variable cv;
	Thread thread;
	G1GCManager() = default;

public:
	static G1GCManager *get_singleton() {
		static G1GCManager *instance = new G1GCManager();
		return instance;
	}
	
	void start_gc();
	void run_gc();
	void end_gc();
	void wait_for_safepoints();
	void start_gc_thread();
};
#endif // __G1GCMANAGER_H__