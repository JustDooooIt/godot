#ifndef __G1HEAPREGIONBOUNDS.INLINE_H__
#define __G1HEAPREGIONBOUNDS.INLINE_H__


#include "g1HeapRegionBounds.h"

size_t G1HeapRegionBounds::min_size() {
  return G1HeapRegionBounds::MIN_REGION_SIZE;
}

size_t G1HeapRegionBounds::max_ergonomics_size() {
  return G1HeapRegionBounds::MAX_ERGONOMICS_SIZE;
}

size_t G1HeapRegionBounds::max_size() {
  return G1HeapRegionBounds::MAX_REGION_SIZE;
}

size_t G1HeapRegionBounds::target_number() {
  return G1HeapRegionBounds::TARGET_REGION_NUMBER;
}

#endif // __G1HEAPREGIONBOUNDS.INLINE_H__