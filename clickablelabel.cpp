#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString& text, Card *parentCard, QWidget* parent)
    : parentCard(parentCard), QLabel(parent) {
    setText(text);

}

ClickableLabel::~ClickableLabel() {
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent* event) {
    emit clicked();
}

int ClickableLabel::getMarketPos() {
    return marketPos;
}

void ClickableLabel::setMarketPos(int pos) {
    marketPos = pos;
}

Card * ClickableLabel::getParentCard() {
    return parentCard;
}
