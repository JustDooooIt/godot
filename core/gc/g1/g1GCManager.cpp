#include "g1GCManager.h"
#include "core/core_bind.h"
#include "core/gc/shared/safepoint.h"

void exec_gc(void *ud) {
	while (true) {
		G1GCManager::get_singleton()->start_gc();
		G1GCManager::get_singleton()->run_gc();
		G1GCManager::get_singleton()->end_gc();
		OS::get_singleton()->delay_usec(1000);
	}
}

void G1GCManager::start_gc_thread() {
	thread.start(exec_gc, this);
}

void G1GCManager::start_gc() {
	Safepoint::get_singleton()->begin();
}

void G1GCManager::run_gc() {
	G1GCManager::get_singleton()->wait_for_safepoints();
  int a = 1;
}

void G1GCManager::end_gc() {
	Safepoint::get_singleton()->end();
}

void G1GCManager::wait_for_safepoints() {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, Safepoint::get_singleton()->is_all_threads_entered_safepoint());
}
