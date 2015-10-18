#include "Card.h"

Card::Card(goods_t type) : type(type), label(nullptr),
    selected(false) {

}

Card::~Card() {
    delete label;
}

goods_t Card::getType() {
    return type;
}

ClickableLabel * Card::getLabel() {
    return label;
}

void Card::setLabel(ClickableLabel * newLabel) {
    label = newLabel;
}

void Card::setSelected(bool isSelected) {
    selected = isSelected;
}

bool Card::getSelected() {
    return selected;
}
