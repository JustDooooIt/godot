#include "../shared/cardTable.h"
#include "cardTable.h"
#include <memory>

CardTable::CardTable() {
  _cards = (unsigned char *) malloc(sizeof(unsigned char) * card_table_size());
}
