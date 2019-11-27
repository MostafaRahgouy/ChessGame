#ifndef MENUFORM_H
#define MENUFORM_H
#include <game.h>
#include <PieceType.h>
#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class menuForm;
}

class menuForm : public QWidget
{
    Q_OBJECT

public:
    explicit menuForm(QWidget *parent = 0);
    ~menuForm();
    MainWindow *PLAY = new MainWindow();
  //  static PieceType promotePawn();
  //  static Game game;// = new Game();// (promotePawn);
private slots:
    void on_play_clicked();
    void on_exit_clicked();

    void on_newGame_clicked();

    void on_about_clicked();

private:
    Ui::menuForm *menu;
};

#endif // MENUFORM_H
