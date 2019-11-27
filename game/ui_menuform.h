/********************************************************************************
** Form generated from reading UI file 'menuform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUFORM_H
#define UI_MENUFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuForm
{
public:
    QPushButton *play;
    QPushButton *newGame;
    QPushButton *about;
    QPushButton *exit;
    QPushButton *iconPhoto;

    void setupUi(QWidget *menuForm)
    {
        if (menuForm->objectName().isEmpty())
            menuForm->setObjectName(QStringLiteral("menuForm"));
        menuForm->setWindowModality(Qt::ApplicationModal);
        menuForm->resize(650, 370);
        menuForm->setMinimumSize(QSize(650, 370));
        menuForm->setMaximumSize(QSize(700, 370));
        menuForm->setStyleSheet(QStringLiteral("background-color: rgb(58, 37, 179);"));
        play = new QPushButton(menuForm);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(50, 40, 231, 41));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(14);
        play->setFont(font);
        play->setStyleSheet(QLatin1String("\n"
"QPushButton#play:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        newGame = new QPushButton(menuForm);
        newGame->setObjectName(QStringLiteral("newGame"));
        newGame->setGeometry(QRect(50, 120, 231, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        newGame->setFont(font1);
        newGame->setStyleSheet(QLatin1String("\n"
"QPushButton#newGame:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        about = new QPushButton(menuForm);
        about->setObjectName(QStringLiteral("about"));
        about->setGeometry(QRect(50, 200, 231, 41));
        about->setFont(font);
        about->setStyleSheet(QLatin1String("\n"
"QPushButton#about:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        exit = new QPushButton(menuForm);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(50, 280, 231, 41));
        exit->setFont(font);
        exit->setStyleSheet(QLatin1String("\n"
"QPushButton#exit:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        iconPhoto = new QPushButton(menuForm);
        iconPhoto->setObjectName(QStringLiteral("iconPhoto"));
        iconPhoto->setGeometry(QRect(280, 10, 361, 341));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        iconPhoto->setIcon(icon);
        iconPhoto->setIconSize(QSize(300, 300));
        iconPhoto->setFlat(true);

        retranslateUi(menuForm);

        QMetaObject::connectSlotsByName(menuForm);
    } // setupUi

    void retranslateUi(QWidget *menuForm)
    {
        menuForm->setWindowTitle(QApplication::translate("menuForm", "C H E S S ", 0));
        play->setText(QApplication::translate("menuForm", "Play", 0));
        newGame->setText(QApplication::translate("menuForm", "New Game", 0));
        about->setText(QApplication::translate("menuForm", "About", 0));
        exit->setText(QApplication::translate("menuForm", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class menuForm: public Ui_menuForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUFORM_H
