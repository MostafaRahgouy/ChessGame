#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messageform.h"
#include "promote.h"
#include <iostream>
#include <string>
#include <string.h>
#include "QIcon"
#include "Game.h"
#include "QString"
#include "PieceType.h"
#include "QMessageBox"
#include "QProcess"
#include "boardCellType.h"
#include <ctime>
using namespace std;
//***********************************************************************************
bool MainWindow::clickOn = false;
int MainWindow::whiteHittingCount = 0;
int MainWindow::blackHittingCount = 0;
string MainWindow::moveUser = "";
string MainWindow::tempMove = "";
//***********************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTextOfLabels();
    setIconOfBoard();
    ui->turnName->setText("<b><font size = '4' color = 'white'>TURN  : </font></b>");
    ui->playerOneYourMove->setText("<font size = '5' color = 'orange' ><b> your Move : </b></font>");
    ui->playerTwoYourMove->setText("<font size = '5' color = 'black'><b> your Move : </b></font>");
    ui->messagePlayerOne->setText("<font size = '5' color = 'orange'  ><b> message   : </b></font>");
    ui->messagePlayerTwo->setText("<font size = '5' color = 'black'   ><b> message   : </b></font>");

}
//***********************************************************************************
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setIconOfBoard()
{
    BoardCellType **boardGame = game->getState();
    int i , j;
    char rowChar = '1' , colChar;
    string btnName = "XX";
    for(i = 0 ; i < 8 ; i ++)
    {
        colChar = 'a';
        for(j = 0 ; j < 8 ; j ++)
        {
            btnName[0] = colChar;
            btnName[1] = rowChar;
            switch (boardGame[i][j])
            {
            case NONE:
                setIconEMPTY(btnName);
                break;
            case KING_WHITE:
                setIconKING_WHITE(btnName);
                break;
            case QUEEN_WHITE:
                setIconQUEEN_WHITE(btnName);
                break;
            case KNIGHT_WHITE:
                setIconKNIGHT_WHITE(btnName);
                break;
            case BISHOP_WHITE:
                setIconBISHOP_WHITE(btnName);
                break;
            case ROCK_WHITE:
                setIconROCK_WHITE(btnName);
                break;
            case PAWN_WHITE:
                setIconPAWN_WHITE(btnName);
                break;
            case KING_BLACK:
                setIconKING_BLACK(btnName);
                break;
            case QUEEN_BLACK:
                setIconQUEEN_BLACK(btnName);
                break;
            case KNIGHT_BLACK:
                setIconKNIGHT_BLACK(btnName);
                break;
            case BISHOP_BLACK:
                setIconBISHOP_BLACK(btnName);
                break;
            case ROCK_BLACK:
                setIconROCK_BLACK(btnName);
                break;
            case PAWN_BLACK:
                setIconPAWN_BLACK(btnName);
                break;
            }
            colChar ++;
            btnName = "XX";
        }
        rowChar ++;
    }
}
//***********************************************************************************
void MainWindow::setClick(string click)
{
    QString move;
    if(!clickOn )
    {
        clickOn = true;
        tempMove = click;
        return;
    }
    if( clickOn )
    {
        string msg = " ";
        moveUser = tempMove + click;
        move = QString::fromStdString(moveUser);
        game->getTurn() == WHITE ? (ui->playerOneMove->setText("<font size ='5' color ='white'><b>\"" + move + "\"</b></font>"),
                                     ui->playerTwoMove->setText("<font size = '5' color = 'white' >\"\"</font>")):
                                     (ui->playerTwoMove->setText("<font size ='5' color = 'white'><b>\"" + move + "\"</b></font>"),
                                      ui->playerOneMove->setText("<font size = '5' color = 'white' >\"\"</font>"));

        ui->messageOne->setText("<font size ='5' color = 'white'><b>\"\"</b></font>");
        ui->messageTwo->setText("<font size ='5' color = 'white'><b>\"\"</b></font>");
        if(game->makeMove(moveUser , msg))
        {
            QString turnText = game->getTurn() == WHITE ? "White" : "Black";
            turnText == "White" ? ui->turn->setText("<font color = 'orange'>\"" + turnText + "\"</font>")
                                : ui->turn->setText("<font color = 'black'>\"" + turnText + "\"</font>");
            string searchHittingNut = "XX";
            searchHittingNut[0] = moveUser[2];
            searchHittingNut[1] = moveUser[3];
            QIcon icon = findIcon(searchHittingNut);
            if(! icon.isNull())
            {
                setHittingNuts(icon);
            }
            setIconOfBoard();
           // change();
            if( game->isChecked() )
            {
                if(game->isMate())
                {
                    messageForm *msg = new messageForm();
                    msg->mateMessage();
                    msg->show();
                }
                else
                {
                    messageForm *msg = new messageForm();
                    msg->checkedMessage();
                    msg->show();
                }
            }
          /*  if( game->isStaleMate())
            {
                messageForm *msg = new messageForm();
                msg->staleMateMessage();
                msg->show();
            }*/
            game->getTurn() == BLACK ? ui->messageOne->setText("<font size ='5' color = 'white'><b>\"True Move\"</b></font>")
                                     : ui->messageTwo->setText("<font size ='5' color = 'white'><b>\"True Move\"</b></font>");
        }
        else
        {
            messageForm *msg = new messageForm();
            msg->invalidMessage();
            msg->show();
            game->getTurn() == WHITE ? ui->messageOne->setText("<font size ='5' color = 'white'><b>\"False Move\"</b></font>")
                                     : ui->messageTwo->setText("<font size ='5' color = 'white'><b>\"False Move \"</b></font>");
        }
        clickOn = false;
    }
}
//***********************************************************************************
void MainWindow::setHittingNuts(QIcon icon)
{
    if(game->getTurn() == WHITE )
    {
        whiteHittingCount ++;
        switch (whiteHittingCount)
        {
        case 1:
           ui->white_1->setIcon(icon);
           return;
        case 2:
            ui->white_2->setIcon(icon);
            return;
        case 3:
            ui->white_3->setIcon(icon);
            return;
        case 4:
            ui->white_4->setIcon(icon);
            return;
        case 5:
            ui->white_5->setIcon(icon);
            return;
        case 6:
            ui->white_6->setIcon(icon);
            return;
        case 7:
            ui->white_7->setIcon(icon);
            return;
        case 8:
            ui->white_8->setIcon(icon);
            return;
        case 9:
            ui->white_9->setIcon(icon);
            return;
        case 10:
            ui->white_10->setIcon(icon);
            return;
        case 11:
            ui->white_11->setIcon(icon);
            return;
        case 12:
            ui->white_12->setIcon(icon);
            return;
        case 13:
            ui->white_13->setIcon(icon);
            return;
        case 14:
            ui->white_14->setIcon(icon);
            return;
        case 15:
            ui->white_15->setIcon(icon);
            return;
        }
    }
    if(game->getTurn() == BLACK)
    {
        blackHittingCount ++;
        switch (blackHittingCount)
        {
        case 1:
            ui->black_1->setIcon(icon);
            return;
        case 2:
            ui->black_2->setIcon(icon);
            return;
        case 3:
            ui->black_3->setIcon(icon);
            return;
        case 4:
            ui->black_4->setIcon(icon);
            return;
        case 5:
            ui->black_5->setIcon(icon);
            return;
        case 6:
            ui->black_6->setIcon(icon);
            return;
        case 7:
            ui->black_7->setIcon(icon);
            return;
        case 8:
            ui->black_8->setIcon(icon);
            return;
        case 9:
            ui->black_9->setIcon(icon);
            return;
        case 10:
            ui->black_10->setIcon(icon);
            return;
        case 11:
            ui->black_11->setIcon(icon);
            return;
        case 12:
            ui->black_12->setIcon(icon);
            return;
        case 13:
            ui->black_13->setIcon(icon);
            return;
        case 14:
            ui->black_14->setIcon(icon);
            return;
        case 15:
            ui->black_15->setIcon(icon);
            return;
        }
    }
}
void MainWindow::change()
{
    string moveString = moveUser;
    string firstPlace = "XX" ;
    firstPlace[0] = moveString[0];
    firstPlace[1] = moveString[1];
    string secondPlace = "XX";
    secondPlace[0] = moveString[2];
    secondPlace[1] = moveString[3];
    QIcon delIcon , icon;
    icon = findIcon(firstPlace);
    setICON( secondPlace , icon);
    setICON( firstPlace , delIcon);
}
//***********************************************************************************
void MainWindow::setTextOfLabels()
{
    ui->A->setText("<font color = 'white'> <b> A </b> </font>");
    ui->B->setText("<font color = 'white'> <b> B </b> </font>");
    ui->C->setText("<font color = 'white'> <b> C </b> </font>");
    ui->D->setText("<font color = 'white'> <b> D </b> </font>");
    ui->E->setText("<font color = 'white'> <b> E </b> </font>");
    ui->F->setText("<font color = 'white'> <b> F </b> </font>");
    ui->G->setText("<font color = 'white'> <b> G </b> </font>");
    ui->H->setText("<font color = 'white'> <b> H </b> </font>");
    ui->one->setText("<font color = 'white'> <b> 1 </b> </font>");
    ui->two->setText("<font color = 'white'> <b> 2 </b> </font>");
    ui->three->setText("<font color = 'white'> <b> 3 </b> </font>");
    ui->four->setText("<font color = 'white'> <b> 4 </b> </font>");
    ui->five->setText("<font color = 'white'> <b> 5 </b> </font>");
    ui->six->setText("<font color = 'white'> <b> 6 </b> </font>");
    ui->seven->setText("<font color = 'white'> <b> 7 </b> </font>");
    ui->eight->setText("<font color = 'white'> <b> 8 </b> </font>");

}
//***********************************************************************************
void MainWindow::QTinit()
{
    game->init();
    addWhiteNutsIcon();
    addEmptyNuts(ui->a3 ,ui->b3 , ui->c3 , ui->d3 , ui->e3 , ui->f3, ui->g3 , ui->h3);
    addEmptyNuts(ui->a4 ,ui->b4 , ui->c4 , ui->d4 , ui->e4 , ui->f4, ui->g4 , ui->h4);
    addEmptyNuts(ui->a5 ,ui->b5 , ui->c5 , ui->d5 , ui->e5 , ui->f5, ui->g5 , ui->h5);
    addEmptyNuts(ui->a6 ,ui->b6 , ui->c6 , ui->d6 , ui->e6 , ui->f6, ui->g6 , ui->h6);
    addEmptyNuts(ui->white_1 , ui->white_2 , ui->white_3 , ui->white_4
                 , ui->white_5 , ui->white_6 , ui->white_7 , ui->white_8);
    addEmptyNuts(ui->white_9 , ui->white_10 , ui->white_11 ,ui->white_12
                 , ui->white_13 , ui->white_14 , ui->white_15 ,ui->white_15);
    addEmptyNuts(ui->black_1 , ui->black_2 , ui->black_3 , ui->black_4
                 , ui->black_5 , ui->black_6 , ui->black_7 , ui->black_8);
    addEmptyNuts(ui->black_9 , ui->black_10 , ui->black_11 , ui->black_12
                 , ui->black_13 , ui->black_14 , ui->black_15 , ui->black_15);
    addBlackNutsIcon();
    blackHittingCount = 0;
    whiteHittingCount = 0;
}
void MainWindow::addEmptyNuts(QPushButton *a, QPushButton *b, QPushButton *c, QPushButton *d
                              ,QPushButton *e, QPushButton *f, QPushButton *g, QPushButton *h)
{
    QIcon icon;
    a->setIcon(icon);
    a->setIconSize(QSize(70 , 85));
    b->setIcon(icon);
    b->setIconSize(QSize(70 , 85));
    c->setIcon(icon);
    c->setIconSize(QSize(70 , 85));
    d->setIcon(icon);
    d->setIconSize(QSize(70 , 85));
    e->setIcon(icon);
    e->setIconSize(QSize(70 , 85));
    f->setIcon(icon);
    f->setIconSize(QSize(70 , 85));
    g->setIcon(icon);
    g->setIconSize(QSize(70 , 85));
    h->setIcon(icon);
    h->setIconSize(QSize(70 , 85));
}

//***********************************************************************************
void MainWindow::addWhiteNutsIcon()
{
    QIcon iconRock , iconPawn , iconKing, iconQueen , iconKnight , iconBishop;
    iconRock.addFile(QString::fromUtf8("images/whiteNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->a1->setIcon(iconRock);
    ui->a1->setIconSize(QSize(70 , 85));
    ui->h1->setIcon(iconRock);
    ui->h1->setIconSize(QSize(70 , 85));
    iconPawn.addFile(QString::fromUtf8("images/whiteNuts/PAWN.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->a2->setIcon(iconPawn);
    ui->a2->setIconSize(QSize(70 , 85));
    ui->b2->setIcon(iconPawn);
    ui->b2->setIconSize(QSize(70 , 85));
    ui->c2->setIcon(iconPawn);
    ui->c2->setIconSize(QSize(70 , 85));
    ui->d2->setIcon(iconPawn);
    ui->d2->setIconSize(QSize(70 , 85));
    ui->e2->setIcon(iconPawn);
    ui->e2->setIconSize(QSize(70 , 85));
    ui->f2->setIcon(iconPawn);
    ui->f2->setIconSize(QSize(70 , 85));
    ui->g2->setIcon(iconPawn);
    ui->g2->setIconSize(QSize(70 , 85));
    ui->h2->setIcon(iconPawn);
    ui->h2->setIconSize(QSize(70 , 85));
    iconKing.addFile(QString::fromUtf8("images/whiteNuts/KING.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->e1->setIcon(iconKing);
    ui->e1->setIconSize(QSize(70 , 85));
    iconQueen.addFile(QString::fromUtf8("images/whiteNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->d1->setIcon(iconQueen);
    ui->d1->setIconSize(QSize(70 , 85));
    iconKnight.addFile(QString::fromUtf8("images/whiteNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->b1->setIcon(iconKnight);
    ui->b1->setIconSize(QSize(70 , 85));
    ui->g1->setIcon(iconKnight);
    ui->g1->setIconSize(QSize(70 , 85));
    iconBishop.addFile(QString::fromUtf8("images/whiteNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->c1->setIcon(iconBishop);
    ui->c1->setIconSize(QSize(70 , 85));
    ui->f1->setIcon(iconBishop);
    ui->f1->setIconSize(QSize(70 , 85));
}
//***********************************************************************************
void MainWindow::addBlackNutsIcon()
{
    QIcon iconRock , iconPawn , iconKing, iconQueen , iconKnight , iconBishop;
    iconRock.addFile(QString::fromUtf8("images/blackNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->a8->setIcon(iconRock);
    ui->a8->setIconSize(QSize(70 , 85));
    ui->h8->setIcon(iconRock);
    ui->h8->setIconSize(QSize(70 , 85));
    iconPawn.addFile(QString::fromUtf8("images/blackNuts/PAWN.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->a7->setIcon(iconPawn);
    ui->a7->setIconSize(QSize(70 , 85));
    ui->b7->setIcon(iconPawn);
    ui->b7->setIconSize(QSize(70 , 85));
    ui->c7->setIcon(iconPawn);
    ui->c7->setIconSize(QSize(70 , 85));
    ui->d7->setIcon(iconPawn);
    ui->d7->setIconSize(QSize(70 , 85));
    ui->e7->setIcon(iconPawn);
    ui->e7->setIconSize(QSize(70 , 85));
    ui->f7->setIcon(iconPawn);
    ui->f7->setIconSize(QSize(70 , 85));
    ui->g7->setIcon(iconPawn);
    ui->g7->setIconSize(QSize(70 , 85));
    ui->h7->setIcon(iconPawn);
    ui->h7->setIconSize(QSize(70 , 85));
    iconKing.addFile(QString::fromUtf8("images/blackNuts/KING.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->e8->setIcon(iconKing);
    ui->e8->setIconSize(QSize(70 , 85));
    iconQueen.addFile(QString::fromUtf8("images/blackNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->d8->setIcon(iconQueen);
    ui->d8->setIconSize(QSize(70 , 85));
    iconKnight.addFile(QString::fromUtf8("images/blackNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->b8->setIcon(iconKnight);
    ui->b8->setIconSize(QSize(70 , 85));
    ui->g8->setIcon(iconKnight);
    ui->g8->setIconSize(QSize(70 , 85));
    iconBishop.addFile(QString::fromUtf8("images/blackNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    ui->c8->setIcon(iconBishop);
    ui->c8->setIconSize(QSize(70 , 85));
    ui->f8->setIcon(iconBishop);
    ui->f8->setIconSize(QSize(70 , 85));
}
//***********************************************************************************
void MainWindow::setICON(string icon , QIcon setIconName)
{
    if(icon == "a1")
    {
        ui->a1->setIcon(setIconName);
    }
    if(icon == "a2")
    {
        ui->a2->setIcon(setIconName);
    }
    if(icon == "a3")
    {
        ui->a3->setIcon(setIconName);
    }
    if(icon == "a4")
    {
        ui->a4->setIcon(setIconName);
    }
    if(icon == "a5")
    {
        ui->a5->setIcon(setIconName);
    }
    if(icon == "a6")
    {
        ui->a6->setIcon(setIconName);
    }
    if(icon == "a7")
    {
        ui->a7->setIcon(setIconName);
    }
    if(icon == "a8")
    {
        ui->a8->setIcon(setIconName);
    }

    if(icon == "b1")
    {
        ui->b1->setIcon(setIconName);
    }
    if(icon == "b2")
    {
        ui->b2->setIcon(setIconName);
    }
    if(icon == "b3")
    {
        ui->b3->setIcon(setIconName);
    }
    if(icon == "b4")
    {
        ui->b4->setIcon(setIconName);
    }
    if(icon == "b5")
    {
        ui->b5->setIcon(setIconName);
    }
    if(icon == "b6")
    {
        ui->b6->setIcon(setIconName);
    }
    if(icon == "b7")
    {
        ui->b7->setIcon(setIconName);
    }
    if(icon == "b8")
    {
        ui->b8->setIcon(setIconName);
    }

    if(icon == "c1")
    {
        ui->c1->setIcon(setIconName);
    }
    if(icon == "c2")
    {
        ui->c2->setIcon(setIconName);
    }
    if(icon == "c3")
    {
        ui->c3->setIcon(setIconName);
    }
    if(icon == "c4")
    {
        ui->c4->setIcon(setIconName);
    }
    if(icon == "c5")
    {
        ui->c5->setIcon(setIconName);
    }
    if(icon == "c6")
    {
        ui->c6->setIcon(setIconName);
    }
    if(icon == "c7")
    {
        ui->c7->setIcon(setIconName);
    }
    if(icon == "c8")
    {
        ui->c8->setIcon(setIconName);
    }

    if(icon == "d1")
    {
        ui->d1->setIcon(setIconName);
    }
    if(icon == "d2")
    {
        ui->d2->setIcon(setIconName);
    }
    if(icon == "d3")
    {
        ui->d3->setIcon(setIconName);
    }
    if(icon == "d4")
    {
        ui->d4->setIcon(setIconName);
    }
    if(icon == "d5")
    {
        ui->d5->setIcon(setIconName);
    }
    if(icon == "d6")
    {
        ui->d6->setIcon(setIconName);
    }
    if(icon == "d7")
    {
        ui->d7->setIcon(setIconName);
    }

    if(icon == "d8")
    {
        ui->d8->setIcon(setIconName);
    }

    if(icon == "e1")
    {
        ui->e1->setIcon(setIconName);
    }
    if(icon == "e2")
    {
        ui->e2->setIcon(setIconName);
    }
    if(icon == "e3")
    {
        ui->e3->setIcon(setIconName);
    }
    if(icon == "e4")
    {
        ui->e4->setIcon(setIconName);
    }
    if(icon == "e5")
    {
        ui->e5->setIcon(setIconName);
    }
    if(icon == "e6")
    {
        ui->e6->setIcon(setIconName);
    }
    if(icon == "e7")
    {
        ui->e7->setIcon(setIconName);
    }
    if(icon == "e8")
    {
        ui->e8->setIcon(setIconName);
    }

    if(icon == "f1")
    {
        ui->f1->setIcon(setIconName);
    }
    if(icon == "f2")
    {
        ui->f2->setIcon(setIconName);
    }
    if(icon == "f3")
    {
        ui->f3->setIcon(setIconName);
    }
    if(icon == "f4")
    {
        ui->f4->setIcon(setIconName);
    }
    if(icon == "f5")
    {
        ui->f5->setIcon(setIconName);
    }
    if(icon == "f6")
    {
        ui->f6->setIcon(setIconName);
    }
    if(icon == "f7")
    {
        ui->f7->setIcon(setIconName);
    }
    if(icon == "f8")
    {
        ui->f8->setIcon(setIconName);
    }

    if(icon == "g1")
    {
        ui->g1->setIcon(setIconName);
    }
    if(icon == "g2")
    {
        ui->g2->setIcon(setIconName);
    }
    if(icon == "g3")
    {
        ui->g3->setIcon(setIconName);
    }
    if(icon == "g4")
    {
        ui->g4->setIcon(setIconName);
    }
    if(icon == "g5")
    {
        ui->g5->setIcon(setIconName);
    }
    if(icon == "g6")
    {
        ui->g6->setIcon(setIconName);
    }
    if(icon == "g7")
    {
        ui->g7->setIcon(setIconName);
    }
    if(icon == "g8")
    {
        ui->g8->setIcon(setIconName);
    }

    if(icon == "h1")
    {
       ui->h1->setIcon(setIconName);
    }
    if(icon == "h2")
    {
        ui->h2->setIcon(setIconName);
    }
    if(icon == "h3")
    {
        ui->h3->setIcon(setIconName);
    }
    if(icon == "h4")
    {
        ui->h4->setIcon(setIconName);
    }
    if(icon == "h5")
    {
        ui->h5->setIcon(setIconName);
    }
    if(icon == "h6")
    {
        ui->h6->setIcon(setIconName);
    }
    if(icon == "h7")
    {
        ui->h7->setIcon(setIconName);
    }
    if(icon == "h8")
    {
        ui->h8->setIcon(setIconName);
    }

}
//***********************************************************************************
QIcon MainWindow::findIcon(string icon)
{
    if(icon == "a1")
    {
        return ui->a1->icon();
    }
    if(icon == "a2")
    {
        return ui->a2->icon();
    }
    if(icon == "a3")
    {
        return ui->a3->icon();
    }
    if(icon == "a4")
    {
        return ui->a4->icon();
    }
    if(icon == "a5")
    {
        return ui->a5->icon();
    }
    if(icon == "a6")
    {
        return ui->a6->icon();
    }
    if(icon == "a7")
    {
        return ui->a7->icon();
    }
    if(icon == "a8")
    {
        return ui->a8->icon();
    }

    if(icon == "b1")
    {
        return ui->b1->icon();
    }
    if(icon == "b2")
    {
        return ui->b2->icon();
    }
    if(icon == "b3")
    {
        return ui->b3->icon();
    }
    if(icon == "b4")
    {
        return ui->b4->icon();
    }
    if(icon == "b5")
    {
        return ui->b5->icon();
    }
    if(icon == "b6")
    {
        return ui->b6->icon();
    }
    if(icon == "b7")
    {
        return ui->b7->icon();
    }
    if(icon == "b8")
    {
        return ui->b8->icon();
    }

    if(icon == "c1")
    {
        return ui->c1->icon();
    }
    if(icon == "c2")
    {
        return ui->c2->icon();
    }
    if(icon == "c3")
    {
        return ui->c3->icon();
    }
    if(icon == "c4")
    {
        return ui->c4->icon();
    }
    if(icon == "c5")
    {
        return ui->c5->icon();
    }
    if(icon == "c6")
    {
        return ui->c6->icon();
    }
    if(icon == "c7")
    {
        return ui->c7->icon();
    }
    if(icon == "c8")
    {
        return ui->c8->icon();
    }

    if(icon == "d1")
    {
        return ui->d1->icon();
    }
    if(icon == "d2")
    {
        return ui->d2->icon();
    }
    if(icon == "d3")
    {
        return ui->d3->icon();
    }
    if(icon == "d4")
    {
        return ui->d4->icon();
    }
    if(icon == "d5")
    {
        return ui->d5->icon();
    }
    if(icon == "d6")
    {
        return ui->d6->icon();
    }
    if(icon == "d7")
    {
        return ui->d7->icon();
    }
    if(icon == "d8")
    {
        return ui->d8->icon();
    }

    if(icon == "e1")
    {
        return ui->e1->icon();
    }
    if(icon == "e2")
    {
        return ui->e2->icon();
    }
    if(icon == "e3")
    {
        return ui->e3->icon();
    }
    if(icon == "e4")
    {
        return ui->e4->icon();
    }
    if(icon == "e5")
    {
        return ui->e5->icon();
    }
    if(icon == "e6")
    {
        return ui->e6->icon();
    }
    if(icon == "e7")
    {
        return ui->e7->icon();
    }
    if(icon == "e8")
    {
        return ui->e8->icon();
    }

    if(icon == "f1")
    {
        return ui->f1->icon();
    }
    if(icon == "f2")
    {
        return ui->f2->icon();
    }
    if(icon == "f3")
    {
        return ui->f3->icon();
    }
    if(icon == "f4")
    {
        return ui->f4->icon();
    }
    if(icon == "f5")
    {
        return ui->f5->icon();
    }
    if(icon == "f6")
    {
        return ui->f6->icon();
    }
    if(icon == "f7")
    {
        return ui->f7->icon();
    }
    if(icon == "f8")
    {
        return ui->f8->icon();
    }

    if(icon == "g1")
    {
        return ui->g1->icon();
    }
    if(icon == "g2")
    {
        return ui->g2->icon();
    }
    if(icon == "g3")
    {
        return ui->g3->icon();
    }
    if(icon == "g4")
    {
        return ui->g4->icon();
    }
    if(icon == "g5")
    {
        return ui->g5->icon();
    }
    if(icon == "g6")
    {
        return ui->g6->icon();
    }
    if(icon == "g7")
    {
        return ui->g7->icon();
    }
    if(icon == "g8")
    {
        return ui->g8->icon();
    }

    if(icon == "h1")
    {
        return ui->h1->icon();
    }
    if(icon == "h2")
    {
        return ui->h2->icon();
    }
    if(icon == "h3")
    {
        return ui->h3->icon();
    }
    if(icon == "h4")
    {
        return ui->h4->icon();
    }
    if(icon == "h5")
    {
        return ui->h5->icon();
    }
    if(icon == "h6")
    {
        return ui->h6->icon();
    }
    if(icon == "h7")
    {
        return ui->h7->icon();
    }
    if(icon == "h8")
    {
        return ui->h8->icon();
    }
}

//***********************************************************************************
void MainWindow::on_a1_clicked()
{
   setClick("a1");
}

void MainWindow::on_b1_clicked()
{
   setClick("b1");
}

void MainWindow::on_c1_clicked()
{
   setClick("c1");
}

void MainWindow::on_d1_clicked()
{
   setClick("d1");
}

void MainWindow::on_e1_clicked()
{
   setClick("e1");
}

void MainWindow::on_f1_clicked()
{
   setClick("f1");
}

void MainWindow::on_g1_clicked()
{
   setClick("g1");
}

void MainWindow::on_h1_clicked()
{
   setClick("h1");
}

//***********************************************************************************
void MainWindow::on_a2_clicked()
{
    setClick("a2");
}

void MainWindow::on_b2_clicked()
{
   setClick("b2");
}

void MainWindow::on_c2_clicked()
{
   setClick("c2");
}

void MainWindow::on_d2_clicked()
{
   setClick("d2");
}

void MainWindow::on_e2_clicked()
{
   setClick("e2");
}

void MainWindow::on_f2_clicked()
{
   setClick("f2");
}

void MainWindow::on_g2_clicked()
{
   setClick("g2");
}

void MainWindow::on_h2_clicked()
{
   setClick("h2");
}
//***********************************************************************************
void MainWindow::on_a3_clicked()
{
   setClick("a3");
}

void MainWindow::on_b3_clicked()
{
   setClick("b3");
}

void MainWindow::on_c3_clicked()
{
   setClick("c3");
}

void MainWindow::on_d3_clicked()
{
   setClick("d3");
}

void MainWindow::on_e3_clicked()
{
   setClick("e3");
}

void MainWindow::on_f3_clicked()
{
   setClick("f3");
}

void MainWindow::on_g3_clicked()
{
   setClick("g3");
}

void MainWindow::on_h3_clicked()
{
   setClick("h3");
}
//***********************************************************************************

void MainWindow::on_a4_clicked()
{
   setClick("a4");
}

void MainWindow::on_b4_clicked()
{
   setClick("b4");
}

void MainWindow::on_c4_clicked()
{
   setClick("c4");
}

void MainWindow::on_d4_clicked()
{
   setClick("d4");
}

void MainWindow::on_e4_clicked()
{
   setClick("e4");
}

void MainWindow::on_f4_clicked()
{
   setClick("f4");
}

void MainWindow::on_g4_clicked()
{
   setClick("g4");
}

void MainWindow::on_h4_clicked()
{
   setClick("h4");
}
//***********************************************************************************

void MainWindow::on_a5_clicked()
{
   setClick("a5");
}

void MainWindow::on_b5_clicked()
{
   setClick("b5");
}

void MainWindow::on_c5_clicked()
{
   setClick("c5");
}

void MainWindow::on_d5_clicked()
{
   setClick("d5");
}

void MainWindow::on_e5_clicked()
{
   setClick("e5");
}

void MainWindow::on_f5_clicked()
{
   setClick("f5");
}

void MainWindow::on_g5_clicked()
{
   setClick("g5");
}

void MainWindow::on_h5_clicked()
{
   setClick("h5");
}
//***********************************************************************************

void MainWindow::on_a6_clicked()
{
   setClick("a6");
}

void MainWindow::on_b6_clicked()
{
   setClick("b6");
}

void MainWindow::on_c6_clicked()
{
   setClick("c6");
}

void MainWindow::on_d6_clicked()
{
   setClick("d6");
}

void MainWindow::on_e6_clicked()
{
   setClick("e6");
}

void MainWindow::on_f6_clicked()
{
   setClick("f6");
}

void MainWindow::on_g6_clicked()
{
   setClick("g6");
}

void MainWindow::on_h6_clicked()
{
   setClick("h6");
}
//***********************************************************************************

void MainWindow::on_a7_clicked()
{
   setClick("a7");
}

void MainWindow::on_b7_clicked()
{
   setClick("b7");
}

void MainWindow::on_c7_clicked()
{
   setClick("c7");
}

void MainWindow::on_d7_clicked()
{
   setClick("d7");
}

void MainWindow::on_e7_clicked()
{
   setClick("e7");
}

void MainWindow::on_f7_clicked()
{
   setClick("f7");
}

void MainWindow::on_g7_clicked()
{
   setClick("g7");
}

void MainWindow::on_h7_clicked()
{
   setClick("h7");
}
//***********************************************************************************

void MainWindow::on_a8_clicked()
{
   setClick("a8");
}

void MainWindow::on_b8_clicked()
{
   setClick("b8");
}

void MainWindow::on_c8_clicked()
{
   setClick("c8");
}

void MainWindow::on_d8_clicked()
{
   setClick("d8");
}

void MainWindow::on_e8_clicked()
{
   setClick("e8");
}

void MainWindow::on_f8_clicked()
{
   setClick("f8");
}

void MainWindow::on_g8_clicked()
{
   setClick("g8");
}

void MainWindow::on_h8_clicked()
{
   setClick("h8");
}
//***********************************************************************************

void MainWindow::on_menu_clicked()
{
    close();
}

void MainWindow::setIconKNIGHT_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconPAWN_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/PAWN.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconROCK_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconBISHOP_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconQUEEN_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconKING_WHITE(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/whiteNuts/KING.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconKNIGHT_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/KNIGHT.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconPAWN_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/PAWN.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconROCK_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/ROCK.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconBISHOP_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/BISHOP.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconQUEEN_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/QUEEN.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconKING_BLACK(string btnName)
{
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/blackNuts/KING.png") , QSize() , QIcon::Normal , QIcon::Off);
    setICON(btnName , icon);
}

void MainWindow::setIconEMPTY(string btnName)
{
    QIcon icon;
    setICON(btnName , icon);
}
