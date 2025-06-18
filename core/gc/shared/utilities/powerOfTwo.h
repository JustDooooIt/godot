#ifndef __POWEROFTWO_H__
#define __POWEROFTWO_H__

#include "../memory/metaprogramming/enableif.h"
#include "core/error/error_macros.h"
#include <limits>
#include <type_traits>

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
constexpr T max_power_of_2() {
	T max_val = std::numeric_limits<T>::max();
	return max_val - (max_val >> 1);
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
constexpr bool is_power_of_2(T value) {
	return (value > T(0)) && ((value & (value - 1)) == T(0));
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline T round_up_power_of_2(T value) {
	ERR_FAIL_COND_V_MSG(!value > 0, 0, "Invalid value");
	ERR_FAIL_COND_V_MSG(!value <= max_power_of_2<T>(), 0,
			"Overflowing maximum allowed power of two");
	if (is_power_of_2(value)) {
		return value;
	}
	int log_value = (int64_t)godot::UtilityFunctions::log(value);
	return T(1) << (log_value + 1);
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline int log2i(T value) {
	ERR_FAIL_COND_V_MSG(!value > T(0), 0, "value must be > 0");
	return 63 - __builtin_clzll(value);
}

template <typename T, ENABLE_IF(std::is_integral<T>::value)>
inline int log2i_exact(T value) {
	ERR_FAIL_COND_V_MSG(!is_power_of_2(value),
			"value must be a power of 2: " UINT64_FORMAT_X,
			static_cast<uint64_t>(value));
	return 63 - __builtin_clzll(value);
}

#endif // __POWEROFTWO_H__