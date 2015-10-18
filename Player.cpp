#include "Player.h"


Player::Player(void) {
   hand = new std::list<goods_t>;

   herd = 0;
   points = 0;
   victories = 0;
}


Player::~Player(void) {
   delete hand;
   hand = nullptr;
}


std::list<goods_t>* Player::getHand() {
    return hand;
}
