#include "Game.h"

Game::Game(QWidget *parent){
    brd = new Board(parent);
    p1 = new Player();
    p2 = new Player();
}

