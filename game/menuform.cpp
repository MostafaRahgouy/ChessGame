#include "menuform.h"
#include "ui_menuform.h"
#include "mainwindow.h"
#include "about.h"
menuForm::menuForm(QWidget *parent) :
    QWidget(parent),
    menu(new Ui::menuForm)
{
    menu->setupUi(this);
}

menuForm::~menuForm()
{
    delete menu;
}

void menuForm::on_play_clicked()
{
    PLAY->show();
}

void menuForm::on_exit_clicked()
{
    exit(1);
}

void menuForm::on_newGame_clicked()
{
    PLAY->QTinit();
    PLAY->show();
}

void menuForm::on_about_clicked()
{
    About *aboutGame = new About();
    aboutGame->show();
}
