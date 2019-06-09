#pragma once

#ifdef box64
	#define box_t uint64_t
	#define BoxBytes 8
#else
#ifdef box32
	#define box_t uint32_t
	#define BoxBytes 4
#else
#ifdef box16
	#define box_t uint16_t
	#define BoxBytes 2
#else
#ifdef box8
	#define box_t uint8_t
	#define BoxBytes 1
#else
	#define box_t uint8_t
	#define BoxBytes 1
#endif
#endif
#endif
#endif

#ifdef field64
	#define field_t uint64_t
	#define FieldBytes 8
#else
#ifdef field32
	#define field_t uint32_t
	#define FieldBytes 4
#else
#ifdef field16
	#define field_t uint16_t
	#define FieldBytes 2
#else
#ifdef field8
	#define field_t uint8_t
	#define FieldBytes 1
#else
	#define field_t uint8_t
	#define FieldBytes 1
#endif
#endif
#endif
#endif