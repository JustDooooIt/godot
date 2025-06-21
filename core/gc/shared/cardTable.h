#ifndef __CARDTABLE_H__
#define __CARDTABLE_H__

#include "../shared/input.h"
#include <stdint.h>

class CardTable {
private:
	static const int _card_size = 512;

protected:
	CardTable();

protected:
	unsigned char *_cards;

public:
	static int card_size() { return _card_size; }
	static int card_table_size() { return MaxHeapSize / _card_size; }
};
#endif // __CARDTABLE_H__