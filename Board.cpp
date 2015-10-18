#include "Board.h"

Board::Board(QWidget *parent) : parent(parent) {
    deck = new std::list<Card *>;
    buildDeck();
    shuffle();

    // prime market with 3 camels and 2 empty slots
    market = new Card* [5];
    market[0] = createCard(camel);
    market[1] = createCard(camel);
    market[2] = createCard(camel);
    market[3] = nullptr;
    market[4] = nullptr;

    fillMarket();
}

Board::~Board() {

}


int Board::getDeckSize() {
    return deck->size();
}

//int Board::getCamels() {
//    return camels;
//}


Card ** Board::getMarket(){
    return market;
}

std::stack<int>* Board::getLeatherTokens(){
    return leatherTokens;
}

std::stack<int>* Board::getSilkTokens(){
    return silkTokens;
}

std::stack<int>* Board::getSpiceTokens(){
    return spiceTokens;
}

std::stack<int>* Board::getSilverTokens(){
    return silverTokens;
}

std::stack<int>* Board::getGoldTokens(){
    return goldTokens;
}

std::stack<int>* Board::getJewelTokens(){
    return jewelTokens;
}

std::stack<int>* Board::get3SaleTokens(){
    return threeSaleTokens;
}

std::stack<int>* Board::get4SaleTokens(){
    return fourSaleTokens;
}

std::stack<int>* Board::get5SaleTokens(){
    return fiveSaleTokens;
}


void Board::buildDeck() {
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(camel));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(leather));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(spices));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silk));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(silver));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(gold));
    deck->push_front(createCard(jewels));
    deck->push_front(createCard(jewels));
    deck->push_front(createCard(jewels));
    deck->push_front(createCard(jewels));
    deck->push_front(createCard(jewels));
    deck->push_front(createCard(jewels));
}


Card * Board::createCard(goods_t type) {
    Card * newCard = new Card(type);
    ClickableLabel *label = new ClickableLabel("", newCard, parent);

    if (type == camel) {
        label->setPixmap(QPixmap(":images/camel"));
    } else if (type == leather) {
        label->setPixmap(QPixmap(":images/leather"));
    } else if (type == spices) {
        label->setPixmap(QPixmap(":images/spices"));
    } else if (type == silk) {
        label->setPixmap(QPixmap(":images/silk"));
    } else if (type == silver) {
        label->setPixmap(QPixmap(":images/silver"));
    } else if (type == gold) {
        label->setPixmap(QPixmap(":images/gold"));
    } else {
        label->setPixmap(QPixmap(":images/jewels"));
    }

    newCard->setLabel(label);
    return newCard;
}


void Board::shuffle() {

    for (std::list<Card*>::iterator deckIt = deck->begin();
         deckIt != deck->end(); deckIt++) {
    }

    // copy to vector to apply random_shuffle, then copy back
    std::vector<Card*> tempVec(deck->size());
    copy(deck->begin(), deck->end(), tempVec.begin());
    std::random_shuffle(tempVec.begin(), tempVec.end());
    delete deck;
    deck = new std::list<Card*>(tempVec.begin(), tempVec.end());
}


void Board::fillMarket() {

    for (int i = 0; i < 5; i++) {
        if (market[i] == nullptr) {
            market[i] = deck->front();
            market[i]->getLabel()->setMarketPos(i);
            deck->pop_front();
        }
    }
}


Card *Board::takeCard(int index) {
    Card *chosenCard = market[index];
    market[index] = nullptr;
    return chosenCard;
}


Card * Board::replaceCard(int index, Card *newCard) {
    Card *chosenCard = market[index];
    market[index] = newCard;
    return chosenCard;
}


int Board::takeNextLeatherToken() {
    int nextToken = leatherTokens->top();
    leatherTokens->pop();
    return nextToken;
}

int Board::takeNextSpiceToken() {
    int nextToken = spiceTokens->top();
    spiceTokens->pop();
    return nextToken;
}

int Board::takeNextSilkToken() {
    int nextToken = silkTokens->top();
    silkTokens->pop();
    return nextToken;
}

int Board::takeNextSilverToken() {
    int nextToken = silverTokens->top();
    silverTokens->pop();
    return nextToken;
}

int Board::takeNextGoldToken() {
    int nextToken = goldTokens->top();
    goldTokens->pop();
    return nextToken;
}

int Board::takeNextJewelToken() {
    int nextToken = jewelTokens->top();
    jewelTokens->pop();
    return nextToken;
}

int Board::takeNext3SaleToken() {
    int nextToken = threeSaleTokens->top();
    threeSaleTokens->pop();
    return nextToken;
}

int Board::takeNext4SaleToken() {
    int nextToken = fourSaleTokens->top();
    fourSaleTokens->pop();
    return nextToken;
}

int Board::takeNext5SaleToken() {
    int nextToken = fiveSaleTokens->top();
    fiveSaleTokens->pop();
    return nextToken;
}
