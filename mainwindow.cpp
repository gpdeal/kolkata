#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    players(1)
{
    ui->setupUi(this);

    ui->take_single->hide();
    ui->trade_cards->hide();
    ui->take_camels->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDeckLabels() {

    deckLabel = new QLabel(this);
    deckLabel->setGeometry(15, 260, 90, 130);
    deckLabel->setPixmap(QPixmap(":/images/deck"));
    deckLabel->hide();

    deckNumber = new QLabel(this);
    char buf [3];
    itoa(gm->brd->getDeckSize(), buf, 10);
    deckNumber->setText(QString(buf));
    deckNumber->setGeometry(35, 290, 60, 60);
    QFont deckFont = deckNumber->font();
    deckFont.setPointSize(20);
    deckNumber->setFont(deckFont);
    deckNumber->hide();
}

void MainWindow::showMarket() {
    if (gm->brd->getDeckSize() == 0) {
        // clear market
    }

    Card** market = gm->brd->getMarket();

    int currentX = 120;    
    for (int i = 0; i < 5; i++) {
        ClickableLabel *label = market[i]->getLabel();
        label->setGeometry(currentX, 270, 80, 120);
        market[i]->getLabel()->show();
        connect(label, SIGNAL(clicked()), this, SLOT(labelClicked()));
        currentX += 90;
    }
}


void MainWindow::showHand() {
    list<goods_t> *handGoods = gm->p1->getHand();



}


void MainWindow::on_comboBox_currentIndexChanged(int index) {
 players = index + 1;

}


void MainWindow::on_startGame_clicked() {
    gm = new Game(this);

    ui->startGame->hide();
    ui->select_players->hide();

    initializeDeckLabels();

    deckLabel->show();
    deckNumber->show();
    ui->take_single->show();
    ui->trade_cards->show();
    ui->take_camels->show();
    ui->take_single->setDisabled(true);
    ui->trade_cards->setDisabled(true);

    showMarket();
    selectedCards = 0;
    selectingCardsFlag = true;

    //currentPlayer = rand % 2;
}



void MainWindow::labelClicked() {
    ClickableLabel *sender = (ClickableLabel *) QObject::sender();
    int marketPos = sender->getMarketPos();
    Card** market = gm->brd->getMarket();
    Card *clickedCard = sender->getParentCard();

    if (selectingCardsFlag && clickedCard->getType() != camel) {
        if (clickedCard->getSelected()) {
            QPoint topLeft = sender->geometry().topLeft();
            topLeft.setY(topLeft.y() + 25);
            sender->move(topLeft);
            clickedCard->setSelected(false);
            selectedCards--;
        } else {
            QPoint topLeft = sender->geometry().topLeft();
            topLeft.setY(topLeft.y() - 25);
            sender->move(topLeft);
            clickedCard->setSelected(true);
            selectedCards++;
        }
        if (selectedCards == 0) {
            ui->take_single->setDisabled(true);
            ui->trade_cards->setDisabled(true);
        } else if (selectedCards == 1) {
            ui->take_single->setEnabled(true);
            ui->trade_cards->setEnabled(true);
        } else {
            ui->take_single->setDisabled(true);
            ui->trade_cards->setEnabled(true);
        }
    }
}

void MainWindow::testClicked() {
    ClickableLabel *label = (ClickableLabel*) QObject::sender();

    label->setPixmap(QPixmap(":/images/jewels"));
}
