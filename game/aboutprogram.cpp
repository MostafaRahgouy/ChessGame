#include "aboutprogram.h"
#include "ui_aboutprogram.h"

AboutProgram::AboutProgram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutProgram)
{
    ui->setupUi(this);
    ui->label_title->setText("<font size = '5' color = 'orange' > ABOUT PROGRAM </font>");
    ui->label_line1->setText("<font size = '4' color = 'white'>This program has written by c ++  language and disigned by QT</font>");
    ui->label_line2->setText("<font size = '4' color = 'white'>We used classes , call back and inheritance in it and we will</font>");
    ui->label_line3->setText("<font size = '4' color = 'white'>add networking game onlin game and artificial intelligence to</font>");
    ui->label_line4->setText("<font size = '4' color = 'white'>it soon.</font>");

}

AboutProgram::~AboutProgram()
{
    delete ui;
}

void AboutProgram::on_close_clicked()
{
    close();
}
