#ifndef __CARDTABLE_H__
#define __CARDTABLE_H__

#include <stdint.h>

class CardTable {
public:
	typedef uint8_t CardValue;
	static_assert(sizeof(CardValue) == 1);

	static uint32_t _card_shift;

public:
	static inline uint32_t card_shift();
};
#endif // __CARDTABLE_H__