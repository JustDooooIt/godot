#ifndef __POWEROFTWO_H__
#define __POWEROFTWO_H__

#include "../memory/metaprogramming/enableif.h"
#include "core/error/error_macros.h"
#include "globalDefinitions.h"
#include <limits>
#include <type_traits>

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
constexpr T max_power_of_2() {
	T max_val = std::numeric_limits<T>::max();
	return max_val - (max_val >> 1);
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline int log2i(T value) {
	ERR_FAIL_COND_V_MSG(!(value > T(0)), 0, "value must be > 0");
	unsigned long index;
	_BitScanReverse64(&index, static_cast<uint64_t>(value));
	return 63 - index;
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline int log2i_exact(T value) {
	ERR_FAIL_COND_V_MSG(!is_power_of_2(value), static_cast<uint64_t>(value), "value must be a power of 2: " UINT64_FORMAT_X);
	unsigned long index;
	_BitScanReverse64(&index, static_cast<uint64_t>(value));
	return 63 - index;
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline T round_up_power_of_2(T value) {
	ERR_FAIL_COND_V_MSG(!(value > 0), 0, "Invalid value");
	ERR_FAIL_COND_V_MSG(!(value <= max_power_of_2<T>()), 0, "Overflowing maximum allowed power of two");
	if (is_power_of_2(value)) {
		return value;
	}
	return T(1) << (log2i(value) + 1);
}

#endif // __POWEROFTWO_H__