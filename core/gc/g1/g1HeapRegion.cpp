#include "../g1/g1HeapRegion.h"
#include "../g1/g1CardTable.h"
#include "../g1/g1HeapRegionBounds.h"
#include "../shared/input.h"
#include "../shared/utilities/globalDefinitions.h"
#include "../shared/utilities/powerOfTwo.h"
#include "core/error/error_macros.h"
#include "core/variant/variant_utility.h"
#include "g1HeapRegion.h"

// uint32_t G1HeapRegion::LogOfHRGrainBytes = 0;
// uint32_t G1HeapRegion::LogCardsPerRegion = 0;
// size_t G1HeapRegion::GrainBytes = 0;
// size_t G1HeapRegion::GrainWords = 0;
// size_t G1HeapRegion::CardsPerRegion = 0;

size_t G1HeapRegion::PerRegionSize = 0;
size_t G1HeapRegion::LogPerRegionSize = 0;
size_t G1HeapRegion::RegionCount = 0;

size_t G1HeapRegion::max_region_size() {
	return G1HeapRegionBounds::max_size();
}

size_t G1HeapRegion::max_ergonomics_size() {
	return G1HeapRegionBounds::max_ergonomics_size();
}

size_t G1HeapRegion::min_region_size_in_words() {
	return G1HeapRegionBounds::min_size() >> LogHeapWordSize;
}

void G1HeapRegion::setup_heap_region_size(size_t max_heap_size) {
	size_t region_size = VariantUtilityFunctions::clampi(
			max_heap_size / G1HeapRegionBounds::target_number(),
			G1HeapRegionBounds::min_size(),
			G1HeapRegionBounds::max_ergonomics_size());

	region_size = round_up_power_of_2(region_size);

	region_size = VariantUtilityFunctions::clampi(
			max_heap_size / G1HeapRegionBounds::target_number(),
			G1HeapRegionBounds::min_size(),
			G1HeapRegionBounds::max_ergonomics_size());
	PerRegionSize = region_size;
	LogPerRegionSize = log2i_exact(PerRegionSize);
}