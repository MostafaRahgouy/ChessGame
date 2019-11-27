#include "aboutprogrammers.h"
#include "ui_aboutprogrammers.h"

AboutProgrammers::AboutProgrammers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutProgrammers)
{
    ui->setupUi(this);
    ui->label_title->setText("<font seize = '5' color = 'orange' > ABOUT PROGRAMMERS</font>");
    // hamed babaei
    ui->email_4->setText("<font size = '4' color = 'white'> Hamed1.Babaei@gmail.com</font>");
    ui->name_4->setText("<font size = '4' color = 'white'> Hamed Babaei</font>");
    // mostafa rahgooy
    ui->email_1->setText("<font size = '4' color = 'white'> </font>");
    ui->name_1->setText("<font size = '4' color = 'white'> Mostafa Rahghooy</font>");
    // mohammad karami
    ui->email_2->setText("<font size = '4' color = 'white'> Mohammad_m919@yahoo.com</font>");
    ui->name_2->setText("<font size = '4' color = 'white'> Mohammad Karami </font>");
    // salar rasouli
    ui->email_3->setText("<font size = '4' color = 'white'>Salar.rasooli.s.r.7@gmail.com</font>");
    ui->name_3->setText("<font size = '4' color = 'white'> Salar Khayat Mirza Rasouli</font>");

}

AboutProgrammers::~AboutProgrammers()
{
    delete ui;
}

void AboutProgrammers::on_close_clicked()
{
    close();
}
