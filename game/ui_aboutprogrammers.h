/********************************************************************************
** Form generated from reading UI file 'aboutprogrammers.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPROGRAMMERS_H
#define UI_ABOUTPROGRAMMERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutProgrammers
{
public:
    QLabel *label_title;
    QPushButton *close;
    QPushButton *person_1;
    QPushButton *person_2;
    QPushButton *person_3;
    QPushButton *person_4;
    QLabel *name_1;
    QLabel *name_2;
    QLabel *name_3;
    QLabel *name_4;
    QLabel *email_1;
    QLabel *email_2;
    QLabel *email_3;
    QLabel *email_4;

    void setupUi(QWidget *AboutProgrammers)
    {
        if (AboutProgrammers->objectName().isEmpty())
            AboutProgrammers->setObjectName(QStringLiteral("AboutProgrammers"));
        AboutProgrammers->setWindowModality(Qt::ApplicationModal);
        AboutProgrammers->resize(770, 530);
        AboutProgrammers->setMinimumSize(QSize(770, 530));
        AboutProgrammers->setMaximumSize(QSize(770, 530));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        AboutProgrammers->setFont(font);
        AboutProgrammers->setStyleSheet(QLatin1String("background-color: rgb(58, 37, 179);\n"
""));
        label_title = new QLabel(AboutProgrammers);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(260, 70, 251, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_title->setFont(font1);
        close = new QPushButton(AboutProgrammers);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(270, 440, 211, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        close->setFont(font2);
        close->setStyleSheet(QLatin1String("\n"
"QPushButton#close:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        person_1 = new QPushButton(AboutProgrammers);
        person_1->setObjectName(QStringLiteral("person_1"));
        person_1->setGeometry(QRect(30, 130, 141, 121));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/about/about-1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        person_1->setIcon(icon);
        person_1->setIconSize(QSize(160, 150));
        person_1->setFlat(true);
        person_2 = new QPushButton(AboutProgrammers);
        person_2->setObjectName(QStringLiteral("person_2"));
        person_2->setGeometry(QRect(30, 280, 141, 121));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/about/about-3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        person_2->setIcon(icon1);
        person_2->setIconSize(QSize(160, 150));
        person_2->setFlat(true);
        person_3 = new QPushButton(AboutProgrammers);
        person_3->setObjectName(QStringLiteral("person_3"));
        person_3->setGeometry(QRect(400, 130, 141, 121));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/about/about-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        person_3->setIcon(icon2);
        person_3->setIconSize(QSize(140, 150));
        person_3->setFlat(true);
        person_4 = new QPushButton(AboutProgrammers);
        person_4->setObjectName(QStringLiteral("person_4"));
        person_4->setGeometry(QRect(400, 280, 141, 121));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/about/about-4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        person_4->setIcon(icon3);
        person_4->setIconSize(QSize(140, 150));
        person_4->setFlat(true);
        name_1 = new QLabel(AboutProgrammers);
        name_1->setObjectName(QStringLiteral("name_1"));
        name_1->setGeometry(QRect(180, 140, 181, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Comic Sans MS"));
        font3.setPointSize(9);
        name_1->setFont(font3);
        name_2 = new QLabel(AboutProgrammers);
        name_2->setObjectName(QStringLiteral("name_2"));
        name_2->setGeometry(QRect(180, 290, 181, 31));
        name_2->setFont(font3);
        name_3 = new QLabel(AboutProgrammers);
        name_3->setObjectName(QStringLiteral("name_3"));
        name_3->setGeometry(QRect(550, 140, 211, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Comic Sans MS"));
        font4.setPointSize(8);
        name_3->setFont(font4);
        name_4 = new QLabel(AboutProgrammers);
        name_4->setObjectName(QStringLiteral("name_4"));
        name_4->setGeometry(QRect(550, 290, 181, 31));
        name_4->setFont(font3);
        email_1 = new QLabel(AboutProgrammers);
        email_1->setObjectName(QStringLiteral("email_1"));
        email_1->setGeometry(QRect(180, 200, 211, 31));
        email_1->setFont(font4);
        email_2 = new QLabel(AboutProgrammers);
        email_2->setObjectName(QStringLiteral("email_2"));
        email_2->setGeometry(QRect(180, 350, 211, 31));
        email_2->setFont(font4);
        email_3 = new QLabel(AboutProgrammers);
        email_3->setObjectName(QStringLiteral("email_3"));
        email_3->setGeometry(QRect(550, 200, 211, 31));
        email_3->setFont(font4);
        email_4 = new QLabel(AboutProgrammers);
        email_4->setObjectName(QStringLiteral("email_4"));
        email_4->setGeometry(QRect(550, 350, 211, 31));
        email_4->setFont(font4);

        retranslateUi(AboutProgrammers);

        QMetaObject::connectSlotsByName(AboutProgrammers);
    } // setupUi

    void retranslateUi(QWidget *AboutProgrammers)
    {
        AboutProgrammers->setWindowTitle(QApplication::translate("AboutProgrammers", "A B O U T     P R O G R A M M E R S", 0));
        label_title->setText(QApplication::translate("AboutProgrammers", "ABOUT PROGRAMMERS", 0));
        close->setText(QApplication::translate("AboutProgrammers", "close", 0));
        person_1->setText(QString());
        person_2->setText(QString());
        person_3->setText(QString());
        person_4->setText(QString());
        name_1->setText(QApplication::translate("AboutProgrammers", "name_1", 0));
        name_2->setText(QApplication::translate("AboutProgrammers", "name_2", 0));
        name_3->setText(QApplication::translate("AboutProgrammers", "name_3", 0));
        name_4->setText(QApplication::translate("AboutProgrammers", "name_4", 0));
        email_1->setText(QApplication::translate("AboutProgrammers", "email_1", 0));
        email_2->setText(QApplication::translate("AboutProgrammers", "email_3", 0));
        email_3->setText(QApplication::translate("AboutProgrammers", "email_3", 0));
        email_4->setText(QApplication::translate("AboutProgrammers", "email_4", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutProgrammers: public Ui_AboutProgrammers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPROGRAMMERS_H
