#include "about.h"
#include "ui_about.h"
#include "aboutprogram.h"
#include "aboutprogrammers.h"
About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_aboutGame_clicked()
{
    AboutProgram *aboutGame = new AboutProgram();
    aboutGame->show();
}

void About::on_aboutProgrammers_clicked()
{
    AboutProgrammers *aboutProgrammers = new AboutProgrammers();
    aboutProgrammers->show();
}

void About::on_close_clicked()
{
    close();
}
