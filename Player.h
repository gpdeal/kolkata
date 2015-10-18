#include <list>
#include "goods_t.h"
#pragma once

class Player {
public:
   Player(void);
   ~Player(void);

   std::list<goods_t> *getHand();

private:
   std::list<goods_t> *hand;

   int herd;
   int points;
   int victories;
};

