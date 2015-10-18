#ifndef CARD_H
#define CARD_H
#include "goods_t.h"
#include "clickablelabel.h"
#include "goods_t.h"

class Card {
public:
   Card(goods_t type = none);
   ~Card();

   goods_t getType();
   ClickableLabel * getLabel();
   void setLabel(ClickableLabel *);
   void setSelected(bool);
   bool getSelected();

private:
   goods_t type;
   ClickableLabel *label;
   bool selected;
};

#endif
