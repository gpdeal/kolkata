#include "Player.h"


Player::Player(void) {
   hand = new std::list<Card *>;

   herd = 0;
   points = 0;
   victories = 0;
}


Player::~Player(void) {
   delete hand;
   hand = nullptr;
}


std::list<Card *> *Player::getHand() {
    return hand;
}


void Player::addCamels(int camels) {
    herd += camels;
}


void Player::addCard(Card *card) {
    hand->push_front(card);
}


