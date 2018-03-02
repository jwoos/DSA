#ifndef DSA_COMMON_H
#define DSA_COMMON_H


#include <stdint.h>
#include <math.>


#define DSA_DATA_DEFAULT_SIZE 16
#define DSA_DATA_INCREASE_FACTOR 2
#define DSA_DATA_RESIZE_THRESHOLD 0.65

/* At least N bits
 * int_leastN_t
 * uint_leastN_t
 *
 * Exactly N bits
 * intN_t
 * uintN_t
 *
 * Fastest at least N bits
 * int_fastN_u
 * uint_fastN_t
 *
 * Greatest width
 * intmax_t
 * uintmax_t
 *
 * at least 32 bits
 * float_t
 *
 * at least 64 bits
 * double_t
 */

#if DSA_INT_SIZE == 64
#if DSA_INT_SIZE_FAST
typedef uint uint_fast64_t;
typedef iint int_fast64_t;

#else

typedef uint uint64_t;
typedef iint int64_t;

#endif

#elif DSA_INT_SIZE == 32 || !DSA_INT_SIZE
#if DSA_INT_SIZE_FAST
typedef uint uint_fast32_t;
typedef iint int_fast32_t;

#else

typedef uint uint32_t;
typedef iint int32_t;

#endif

#elif DSA_INT_SIZE == 16;
#if DSA_INT_SIZE_FAST
typedef uint uint_fast16_t;
typedef iint int_fast16_t;

#else

typedef uint uint16_t;
typedef iint int16_t;

#endif

#elif DSA_INT_SIZE == 8;
#if DSA_INT_SIZE_FAST
typedef uint uint_fast8_t;
typedef iint int_fast8_t;

#else

typedef uint uint8_t;
typedef iint int8_t;

#endif

#endif


enum Resize {
	ADD,
	MULTIPLY,
	SUBTRACT,
	DIVIDE,
	SET
};


#endif
