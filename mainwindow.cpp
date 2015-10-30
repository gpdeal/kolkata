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
    Card** market = gm->brd->getMarket();

    int currentX = 120;    
    for (int i = 0; i < 5; i++) {
        ClickableLabel *label = market[i]->getLabel();
        label->setGeometry(currentX, 270, 80, 120);
        market[i]->getLabel()->show();
        if (!market[i]->isConnected()) {
            connect(label, SIGNAL(clicked()), this, SLOT(labelClicked()));
            market[i]->setConnected(true);
        }
        currentX += 90;
    }
}


void MainWindow::showHand() {
    list<Card *> *hand = gm->p1->getHand();

    int center = 310;
    int offset = (hand->size() - 1) * -1;

    for (auto handIt = hand->begin(); handIt != hand->end(); handIt++) {
        ClickableLabel *label = (*handIt)->getLabel();
        label->setGeometry(center + (offset * 45), 500, 80, 120);
        label->show();
        offset += 2;
    }
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
    selectingMarketCards = true;

    //currentPlayer = rand % 2;
    currentPlayer = gm->p1; // TODO: make this random
}



void MainWindow::labelClicked() {
    ClickableLabel *sender = (ClickableLabel *) QObject::sender();
    //int marketPos = sender->getMarketPos();
    //Card** market = gm->brd->getMarket();
    Card *clickedCard = sender->getParentCard();

    if (selectingMarketCards && clickedCard->getType() != camel) {
        bool selected = clickCard(clickedCard);
        if (selected) {
            selectedCards++;
        } else {
            selectedCards--;
        }

        updateButtons();
    } else if (selectingHandCards) {

    }


}


bool MainWindow::clickCard(Card * card) {
    QPoint topLeft = card->getLabel()->geometry().topLeft();
    if (card->getSelected()) {
        topLeft.setY(topLeft.y() + 25);
        card->getLabel()->move(topLeft);
        card->setSelected(false);
        return false;
    } else {
        QPoint topLeft = card->getLabel()->geometry().topLeft();
        topLeft.setY(topLeft.y() - 25);
        card->getLabel()->move(topLeft);
        card->setSelected(true);
        return true;
    }
}


void MainWindow::updateButtons() {
    if (selectedCards == 0) {
        ui->take_single->setDisabled(true);
        ui->trade_cards->setDisabled(true);
    } else if (selectedCards == 1) {
        ui->trade_cards->setEnabled(true);
        if (currentPlayer->getHand()->size() < 7) {
            ui->take_single->setEnabled(true);
        }
    } else {
        ui->take_single->setDisabled(true);
        ui->trade_cards->setEnabled(true);
    }
}


void MainWindow::on_take_single_clicked() {
    Card **market = gm->brd->getMarket();

    // find the selected card
    int cardPos;
    for (int i = 0; i < 5; i++) {
        if (market[i]->getSelected()) {
            cardPos = i;
            break;
        }
    }

    Card *card = gm->brd->takeCard(cardPos);
    currentPlayer->addCard(card);
    card->setSelected(false);
    card->getLabel()->hide();

    selectedCards = 0;
    ui->take_single->setDisabled(true);
    ui->trade_cards->setDisabled(true);

    gm->brd->fillMarket();
    showMarket();
    showHand();
}

void MainWindow::on_take_camels_clicked() {
    Card **market = gm->brd->getMarket();
    int camels = 0;

    for (int i = 0; i < 5; i++) {
        if (market[i]->getType() == camel) {
            Card *card = gm->brd->takeCard(i);
            delete card;
            camels++;
        }
    }

    currentPlayer->addCamels(camels);
    char buf[2];
    itoa(currentPlayer->getHerd(), buf, 10);
    string text = "Herd: " + string(buf) + " camels";
    if (currentPlayer == gm->p1) {
        ui->p1HerdLabel->setText(QString::fromStdString(text));
    }
    gm->brd->fillMarket();
    showMarket();
}
