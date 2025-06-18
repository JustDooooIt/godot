#ifndef __GLOBALDEFINITIONS_H__
#define __GLOBALDEFINITIONS_H__

//----------------------------------------------------------------------------------------------------
// Printf-style formatters for fixed- and variable-width types as pointers and
// integers.  These are derived from the definitions in inttypes.h.  If the platform
// doesn't provide appropriate definitions, they should be provided in
// the compiler-specific definitions file (e.g., globalDefinitions_gcc.hpp)

// Guide to the suffixes used in the format specifiers for integers:
//        - print the decimal value:                   745565
//  _X    - print as hexadecimal, without leading 0s: 0x12345
//  _X_0  - print as hexadecimal, with leading 0s: 0x00012345
//  _W(w) - prints w sized string with the given value right
//          adjusted. Use -w to print left adjusted.
//  _0    - print as hexadecimal, with leading 0s, without 0x prefix: 0012345
//
// Note that the PTR format specifiers print using 0x with leading zeros,
// just like the _X_0 version for integers.

// Format 8-bit quantities.
#define INT8_FORMAT_X_0 "0x%02" PRIx8
#define UINT8_FORMAT_X_0 "0x%02" PRIx8

// Format 16-bit quantities.
#define INT16_FORMAT_X_0 "0x%04" PRIx16
#define UINT16_FORMAT_X_0 "0x%04" PRIx16

// Format 32-bit quantities.
#define INT32_FORMAT "%" PRId32
#define INT32_FORMAT_X "0x%" PRIx32
#define INT32_FORMAT_X_0 "0x%08" PRIx32
#define INT32_FORMAT_W(width) "%" #width PRId32
#define UINT32_FORMAT "%" PRIu32
#define UINT32_FORMAT_X "0x%" PRIx32
#define UINT32_FORMAT_X_0 "0x%08" PRIx32
#define UINT32_FORMAT_W(width) "%" #width PRIu32

// Format 64-bit quantities.
#define INT64_FORMAT "%" PRId64
#define INT64_PLUS_FORMAT "%+" PRId64
#define INT64_FORMAT_X "0x%" PRIx64
#define INT64_FORMAT_X_0 "0x%016" PRIx64
#define INT64_FORMAT_W(width) "%" #width PRId64
#define UINT64_FORMAT "%" PRIu64
#define UINT64_FORMAT_X "0x%" PRIx64
#define UINT64_FORMAT_X_0 "0x%016" PRIx64
#define UINT64_FORMAT_W(width) "%" #width PRIu64
#define UINT64_FORMAT_0 "%016" PRIx64

// Format jlong, if necessary
#ifndef JLONG_FORMAT
#define JLONG_FORMAT INT64_FORMAT
#endif
#ifndef JLONG_FORMAT_W
#define JLONG_FORMAT_W(width) INT64_FORMAT_W(width)
#endif
#ifndef JULONG_FORMAT
#define JULONG_FORMAT UINT64_FORMAT
#endif
#ifndef JULONG_FORMAT_X
#define JULONG_FORMAT_X UINT64_FORMAT_X
#endif

// Format pointers and padded integral values which change size between 32- and 64-bit.
#ifdef _LP64
#define INTPTR_FORMAT "0x%016" PRIxPTR
#define PTR_FORMAT "0x%016" PRIxPTR
#define UINTX_FORMAT_X_0 "0x%016" PRIxPTR
#define SIZE_FORMAT_X_0 "0x%016" PRIxPTR
#else // !_LP64
#define INTPTR_FORMAT "0x%08" PRIxPTR
#define PTR_FORMAT "0x%08" PRIxPTR
#define UINTX_FORMAT_X_0 "0x%08" PRIxPTR
#define SIZE_FORMAT_X_0 "0x%08" PRIxPTR
#endif // _LP64

#ifdef _LP64
const int LogHeapWordSize = 3;
#else
const int LogHeapWordSize = 2;
#endif

#endif // __GLOBALDEFINITIONS_H__