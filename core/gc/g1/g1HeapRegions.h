#ifndef __G1HEAPREGIONS_H__
#define __G1HEAPREGIONS_H__

#include <Windows.h>

class G1HeapRegions {
private:
	static LPVOID _base_addr;
public:
	static void reserve_memory(size_t size);
	static void commit_memory(size_t size, LPVOID addr = NULL);
};

#endif // __G1HEAPREGIONS_H__