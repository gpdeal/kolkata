#include <list>
#include <stack>
#include <vector>
#include <algorithm> // random_shuffle
#include <iostream>  // debug statements
#include "goods_t.h"
#include "Card.h"


#pragma once


class Board
{
public:
   Board(QWidget *parent);
   ~Board(void);

   int getDeckSize();
   //int getCamels();
   Card ** getMarket();
   std::stack<int>* getLeatherTokens();
   std::stack<int>* getSpiceTokens();
   std::stack<int>* getSilkTokens();
   std::stack<int>* getSilverTokens();
   std::stack<int>* getGoldTokens();
   std::stack<int>* getJewelTokens();
   std::stack<int>* get3SaleTokens();
   std::stack<int>* get4SaleTokens();
   std::stack<int>* get5SaleTokens();


   void buildDeck();
   void shuffle();
   void fillMarket();

   // remove card at passed market index from market and return it.
   Card * takeCard(int);
   // replace card at passed market index with one of passed type, and return it.
   Card *replaceCard(int, Card *);

   void resetCamels();

   int takeNextLeatherToken();
   int takeNextSpiceToken();
   int takeNextSilkToken();
   int takeNextSilverToken();
   int takeNextGoldToken();
   int takeNextJewelToken();
   int takeNext3SaleToken();
   int takeNext4SaleToken();
   int takeNext5SaleToken();

private:
   QWidget *parent;
   std::list<Card *> *deck;
   Card** market;
   //int camels; //probably not necessary

   std::stack<int> *leatherTokens;
   std::stack<int> *spiceTokens;
   std::stack<int> *silkTokens;
   std::stack<int> *silverTokens;
   std::stack<int> *goldTokens;
   std::stack<int> *jewelTokens;

   std::stack<int> *threeSaleTokens;
   std::stack<int> *fourSaleTokens;
   std::stack<int> *fiveSaleTokens;

   Card * createCard(goods_t);
};

