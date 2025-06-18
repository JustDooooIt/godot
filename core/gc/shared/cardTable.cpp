#include "../shared/cardTable.h"
#include "cardTable.h"

uint32_t CardTable::_card_shift = 0;

inline uint32_t CardTable::card_shift()
{
  return _card_shift;
}