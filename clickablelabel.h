#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <iostream> // cerr (for debugging)

class Card;

class ClickableLabel : public QLabel {
Q_OBJECT

public:
    explicit ClickableLabel( const QString& text,
                             Card *parentCard, QWidget* parent);
    ~ClickableLabel();

    int getMarketPos();
    void setMarketPos(int);
    Card * getParentCard();
private:
    Card *parentCard;
    int marketPos;

signals:
    void clicked();
protected:
    void mouseReleaseEvent(QMouseEvent* event);
private slots:

};

#endif // CLICKABLELABEL_H
