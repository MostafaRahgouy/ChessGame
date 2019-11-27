#include "messageform.h"
#include "ui_messageform.h"
#include "QApplication"
messageForm::messageForm(QWidget *parent) :
    QWidget(parent),
    ms(new Ui::messageForm)
{
    ms->setupUi(this);
    ms->ok->setText("OK");
}

messageForm::~messageForm()
{
    delete ms;
}

void messageForm::on_ok_clicked()
{
    close();
}

void messageForm::checkedMessage()
{
    QIcon checkIcon;
    checkIcon.addFile(QString::fromUtf8("images/checked/checked.jpg") , QSize() , QIcon::Normal , QIcon::Off);
    ms->messageImage->setIcon(checkIcon);
    ms->messageImage->setIconSize(QSize(600 , 300));
    ms->messageText->setText("<b><font size = '5' color = white>\" Game checked has happend !!!\"/font></b>");
}

void messageForm::mateMessage()
{
    QIcon checkIcon;
    checkIcon.addFile(QString::fromUtf8("images/mate/mate.jpg") , QSize() , QIcon::Normal , QIcon::Off);
    ms->messageImage->setIcon(checkIcon);
    ms->messageImage->setIconSize(QSize(500 , 200));
    ms->messageText->setText("<font size = '5' color = white>\"!!! Game Is Mate !!!\"<font></b");
}

void messageForm::invalidMessage()
{
    QIcon checkIcon;
    checkIcon.addFile(QString::fromUtf8("images/invalid/invalid.jpg") , QSize() , QIcon::Normal , QIcon::Off);

    ms->messageImage->setIcon(checkIcon);
    ms->messageImage->setIconSize(QSize(600 , 300));
    ms->messageText->setText("<b><font size = '5' color = white>\"Your Move is Wrrong !!\"<font></b>");
}

void messageForm::staleMateMessage()
{
    QIcon checkIcon;
    checkIcon.addFile(QString::fromUtf8("images/stalMate/stalMate.jpg") , QSize() , QIcon::Normal , QIcon::Off);
    ms->messageImage->setIcon(checkIcon);
    ms->messageImage->setIconSize(QSize(600 , 300));
    ms->messageText->setText("<b><font size = '5' color = white>\"!!! Stale Mate happend !!! \"<font></b>");
}
