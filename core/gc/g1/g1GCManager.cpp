#include "g1GCManager.h"
#include "../shared/input.h"
#include "core/gc/shared/safepoint.h"
#include "core/os/os.h"
#include "g1HeapRegion.h"


static void exec_gc(void *ud) {
	// while (true) {
	// 	if (G1GCManager::get_singleton()->closed()){
	// 		break;
	// 	}
	// 	G1GCManager::get_singleton()->start_gc();
	// 	G1GCManager::get_singleton()->run_gc();
	// 	G1GCManager::get_singleton()->stop_gc();
	// 	OS::get_singleton()->delay_usec(1000);
	// }
	G1GCManager::get_singleton()->start_gc();
	G1GCManager::get_singleton()->run_gc();
	G1GCManager::get_singleton()->stop_gc();
}

G1GCManager::G1GCManager() {
	G1HeapRegion::setup_heap_region_size(MaxHeapSize);
}

void G1GCManager::start_gc_thread() {
	_closed.store(false);
	_thread.start(exec_gc, this);
}

void G1GCManager::stop_gc_thread() {
	_closed.store(true);
	_thread.wait_to_finish();
}

void G1GCManager::start_gc() {
	Safepoint::get_singleton()->begin();
}

void G1GCManager::run_gc() {
	G1GCManager::get_singleton()->wait_for_safepoints();
}

void G1GCManager::stop_gc() {
	Safepoint::get_singleton()->end();
}

void G1GCManager::wait_for_safepoints() {
	std::unique_lock<std::mutex> lock(_mtx);
	_cv.wait(lock, []() { return Safepoint::get_singleton()->is_all_threads_entered_safepoint(); });
}
