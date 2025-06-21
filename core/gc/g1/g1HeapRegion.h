#ifndef __G1HEAPREGION_H__
#define __G1HEAPREGION_H__

#include <stdint.h>

class G1HeapRegion {
public:
	// 每个区域的大小
	// static uint32_t LogOfHRGrainBytes;
	// static uint32_t LogCardsPerRegion;
	// static size_t GrainBytes;
	// static size_t GrainWords;
	// static size_t CardsPerRegion;
	static size_t PerRegionSize;
	static size_t LogPerRegionSize;
	static size_t RegionCount;

public:
	static size_t max_region_size();
	static size_t max_ergonomics_size();
	static size_t min_region_size_in_words();
	static void setup_heap_region_size(size_t max_heap_size);
};
#endif // __G1HEAPREGION_H__