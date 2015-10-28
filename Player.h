#include <list>
#include "goods_t.h"
#pragma once
class Card;

class Player {
public:
   Player(void);
   ~Player(void);

   std::list<Card *> *getHand();
   void addCamels(int camels);
   void addCard(Card *card);


private:
   std::list<Card *> *hand;

   int herd;
   int points;
   int victories;
};

