#include "promote.h"
#include "ui_promote.h"
#include <iostream>
using namespace std;


promote::promote(QDialog *parent) :
    QDialog(parent),
    pro(new Ui::promote)
{
    pro->setupUi(this);
}

promote::~promote()
{
    delete pro;
}

void promote::initPromoteWhiteNuts()
{
    QIcon QUEEN_WHITE, KNIGHT_WHITE , BISHOP_WHITE ,ROCK_WHITE ;
    QUEEN_WHITE.addFile(QString::fromUtf8("images/whiteNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Queen->setIcon(QUEEN_WHITE);
    pro->Queen->setIconSize(QSize(85 , 85));
    KNIGHT_WHITE.addFile(QString::fromUtf8("images/whiteNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Knight->setIcon(KNIGHT_WHITE);
    pro->Knight->setIconSize(QSize(85 , 85));
    BISHOP_WHITE.addFile(QString::fromUtf8("images/whiteNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Bishop->setIcon(BISHOP_WHITE);
    pro->Bishop->setIconSize(QSize(85 , 85));
    ROCK_WHITE.addFile(QString::fromUtf8("images/whiteNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Rock->setIcon(ROCK_WHITE);
    pro->Rock->setIconSize(QSize(85 , 85));
}

void promote::initPromoteBlackNuts()
{
    QIcon QUEEN_BLACK, KNIGHT_BLACK , BISHOP_BLACK ,ROCK_BLACK ;
    QUEEN_BLACK.addFile(QString::fromUtf8("images/blackNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Queen->setIcon(QUEEN_BLACK);
    pro->Queen->setIconSize(QSize(85 , 85));
    KNIGHT_BLACK.addFile(QString::fromUtf8("images/blackNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Knight->setIcon(KNIGHT_BLACK);
    pro->Knight->setIconSize(QSize(85 , 85));
    BISHOP_BLACK.addFile(QString::fromUtf8("images/blackNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Bishop->setIcon(BISHOP_BLACK);
    pro->Bishop->setIconSize(QSize(85 , 85));
    ROCK_BLACK.addFile(QString::fromUtf8("images/blackNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    pro->Rock->setIcon(ROCK_BLACK);
    pro->Rock->setIconSize(QSize(85 , 85));
}

int promote::getChooseNutsNumber()
{
    return choose;
}

void promote::on_Queen_clicked()
{
   choose = 1;
   close();
}

void promote::on_Rock_clicked()
{
    choose = 2;
    close();
}

void promote::on_Bishop_clicked()
{
    choose = 3;
    close();
}

void promote::on_Knight_clicked()
{
   choose = 4;
   close();
}

PieceType promote::promotePawn(PieceColor turn)
{
    promote *myPromote = new promote();
    if( turn == WHITE)
    {
        myPromote->initPromoteWhiteNuts();
    }
    if(turn == BLACK)
    {
        myPromote->initPromoteBlackNuts();
    }
    int choose;
    myPromote->exec();
    choose = myPromote->choose;
    switch (choose)
    {
    case 1:
        return QUEEN;
    case 2:
        return ROCK;
    case 3:
        return BISHOP;
    case 4:
        return KNIGHT;
    }
 }
