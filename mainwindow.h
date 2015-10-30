#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <cstdlib>
#include "Game.h"
#include "clickablelabel.h"
#include "Card.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_startGame_clicked();

    void labelClicked();

    bool clickCard(Card *);
    void updateButtons();



    void on_take_single_clicked();
    void on_take_camels_clicked();

private:
    Ui::MainWindow *ui;

    int players;
    Game *gm;
    Player *currentPlayer;

    QLabel *deckLabel;
    QLabel *deckNumber;

    int selectedCards;

    bool selectingMarketCards;
    bool selectingHandCards;

    //Card** marketCards;
    //bool* marketClickedState;

    void initializeDeckLabels();

    void showMarket();
    void showHand();


};

#endif // MAINWINDOW_H
