#ifndef __G1HEAPREGIONBOUNDS_H__
#define __G1HEAPREGIONBOUNDS_H__

class G1HeapRegionBounds {
public:
	static const size_t MAX_REGION_SIZE = 512 * 1024 * 1024;
	static const size_t MIN_REGION_SIZE = 1024 * 1024;
	static const size_t MAX_ERGONOMICS_SIZE = 32 * 1024 * 1024;
	static const size_t TARGET_REGION_NUMBER = 2048;

public:
	static size_t min_size() {
		return MIN_REGION_SIZE;
	}

	static size_t max_ergonomics_size() {
		return MAX_ERGONOMICS_SIZE;
	}

	static size_t max_size() {
		return MAX_REGION_SIZE;
	}

	static size_t target_number() {
		return TARGET_REGION_NUMBER;
	}
};
#endif // __G1HEAPREGIONBOUNDS_H__