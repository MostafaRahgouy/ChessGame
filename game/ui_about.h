/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QPushButton *aboutGame;
    QPushButton *iconPhoto;
    QPushButton *aboutProgrammers;
    QPushButton *close;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->setWindowModality(Qt::ApplicationModal);
        About->resize(650, 370);
        About->setMinimumSize(QSize(650, 370));
        About->setMaximumSize(QSize(650, 370));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        About->setFont(font);
        About->setStyleSheet(QLatin1String("background-color: rgb(58, 37, 179);\n"
""));
        aboutGame = new QPushButton(About);
        aboutGame->setObjectName(QStringLiteral("aboutGame"));
        aboutGame->setGeometry(QRect(50, 60, 211, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        aboutGame->setFont(font1);
        aboutGame->setStyleSheet(QLatin1String("\n"
"QPushButton#aboutGame:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        iconPhoto = new QPushButton(About);
        iconPhoto->setObjectName(QStringLiteral("iconPhoto"));
        iconPhoto->setGeometry(QRect(280, 10, 361, 341));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        iconPhoto->setIcon(icon);
        iconPhoto->setIconSize(QSize(300, 300));
        iconPhoto->setFlat(true);
        aboutProgrammers = new QPushButton(About);
        aboutProgrammers->setObjectName(QStringLiteral("aboutProgrammers"));
        aboutProgrammers->setGeometry(QRect(50, 160, 211, 71));
        aboutProgrammers->setFont(font1);
        aboutProgrammers->setStyleSheet(QLatin1String("\n"
"QPushButton#aboutProgrammers:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        close = new QPushButton(About);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(50, 260, 211, 71));
        close->setFont(font1);
        close->setStyleSheet(QLatin1String("\n"
"QPushButton#close:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "A B O U T", 0));
        aboutGame->setText(QApplication::translate("About", "About Program", 0));
        aboutProgrammers->setText(QApplication::translate("About", "About Programmers", 0));
        close->setText(QApplication::translate("About", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
