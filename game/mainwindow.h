#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <string>
#include <string.h>
#include "QIcon"
#include "game.h"
#include "PieceType.h"
#include <QString>
#include "QPushButton"
#include "promote.h"
#include "boardCellType.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MainWindow(QWidget *parent = 0);
     ~MainWindow();
     void setIconOfBoard();
     static PieceType promotePawn();
     Game *game = new Game (promote::promotePawn);
     static string moveUser , tempMove;
     static bool clickOn;
     void setClick(string );
     void change();
     QIcon findIcon(string );
     void setICON(string , QIcon );
     void setTextOfLabels();
     void QTinit();
     void addWhiteNutsIcon();
     void addEmptyNuts(QPushButton * , QPushButton *,QPushButton * , QPushButton *
                       , QPushButton * , QPushButton * ,QPushButton * , QPushButton *);
     void addBlackNutsIcon();
     static int whiteHittingCount , blackHittingCount;
     void setHittingNuts(QIcon );
 private slots:
     void on_a1_clicked();
     void on_b1_clicked();
     void on_c1_clicked();
     void on_d1_clicked();
     void on_e1_clicked();
     void on_f1_clicked();
     void on_g1_clicked();
     void on_h1_clicked();
//***********************************************************************************
     void on_a2_clicked();
     void on_b2_clicked();
     void on_c2_clicked();
     void on_d2_clicked();
     void on_e2_clicked();
     void on_f2_clicked();
     void on_g2_clicked();
     void on_h2_clicked();
//***********************************************************************************
     void on_a3_clicked();
     void on_b3_clicked();
     void on_c3_clicked();
     void on_d3_clicked();
     void on_e3_clicked();
     void on_f3_clicked();
     void on_g3_clicked();
     void on_h3_clicked();
//***********************************************************************************
     void on_a4_clicked();
     void on_b4_clicked();
     void on_c4_clicked();
     void on_d4_clicked();
     void on_e4_clicked();
     void on_f4_clicked();
     void on_g4_clicked();
     void on_h4_clicked();
//***********************************************************************************
     void on_a5_clicked();
     void on_b5_clicked();
     void on_c5_clicked();
     void on_d5_clicked();
     void on_e5_clicked();
     void on_f5_clicked();
     void on_g5_clicked();
     void on_h5_clicked();
//***********************************************************************************
     void on_a6_clicked();
     void on_b6_clicked();
     void on_c6_clicked();
     void on_d6_clicked();
     void on_e6_clicked();
     void on_f6_clicked();
     void on_g6_clicked();
     void on_h6_clicked();
//***********************************************************************************
     void on_a7_clicked();
     void on_b7_clicked();
     void on_c7_clicked();
     void on_d7_clicked();
     void on_e7_clicked();
     void on_f7_clicked();
     void on_g7_clicked();
     void on_h7_clicked();
//***********************************************************************************
     void on_a8_clicked();
     void on_b8_clicked();
     void on_c8_clicked();
     void on_d8_clicked();
     void on_e8_clicked();
     void on_f8_clicked();
     void on_g8_clicked();
     void on_h8_clicked();
//***********************************************************************************
     void on_menu_clicked();

private:

     Ui::MainWindow *ui;
     void setIconKNIGHT_WHITE(string btnName);
     void setIconPAWN_WHITE(string btnName);
     void setIconROCK_WHITE(string btnName);
     void setIconBISHOP_WHITE(string btnName);
     void setIconQUEEN_WHITE(string btnName);
     void setIconKING_WHITE(string btnName);
     void setIconKNIGHT_BLACK(string btnName);
     void setIconPAWN_BLACK(string btnName);
     void setIconROCK_BLACK(string btnName);
     void setIconBISHOP_BLACK(string btnName);
     void setIconQUEEN_BLACK(string btnName);
     void setIconKING_BLACK(string btnName);
     void setIconEMPTY(string btnName);

};

#endif // MAINWINDOW_H
