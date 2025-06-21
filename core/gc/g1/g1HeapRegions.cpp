#include "g1HeapRegions.h"
#include "../shared/input.h"

LPVOID G1HeapRegions::_base_addr = NULL;

void G1HeapRegions::reserve_memory(size_t size) {
	_base_addr = VirtualAlloc(NULL, size, MEM_RESERVE, PAGE_NOACCESS);
}

void G1HeapRegions::commit_memory(size_t size, LPVOID addr) {
	_base_addr = VirtualAlloc(addr, size, MEM_COMMIT, PAGE_READWRITE);
}
