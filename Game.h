#include "Board.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H


class Game {
public:
    Game(QWidget *parent);

    Board *brd;
    Player *p1;
    Player *p2;



private:

};

#endif // GAME_H
