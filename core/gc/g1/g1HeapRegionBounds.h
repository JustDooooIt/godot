#ifndef __G1HEAPREGIONBOUNDS_H__
#define __G1HEAPREGIONBOUNDS_H__

class G1HeapRegionBounds {
public:
	static const size_t MAX_REGION_SIZE = 512 * 1024 * 1024;
	static const size_t MIN_REGION_SIZE = 1024 * 1024;
	static const size_t MAX_ERGONOMICS_SIZE = 32 * 1024 * 1024;
	static const size_t TARGET_REGION_NUMBER = 2048;

public:
	static inline size_t min_size();
	static inline size_t max_ergonomics_size();
	static inline size_t max_size();
	static inline size_t target_number();
};
#endif // __G1HEAPREGIONBOUNDS_H__