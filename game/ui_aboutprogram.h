/********************************************************************************
** Form generated from reading UI file 'aboutprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPROGRAM_H
#define UI_ABOUTPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutProgram
{
public:
    QLabel *label_title;
    QLabel *label_line1;
    QLabel *label_line2;
    QLabel *label_line3;
    QLabel *label_line4;
    QPushButton *close;

    void setupUi(QWidget *AboutProgram)
    {
        if (AboutProgram->objectName().isEmpty())
            AboutProgram->setObjectName(QStringLiteral("AboutProgram"));
        AboutProgram->setWindowModality(Qt::ApplicationModal);
        AboutProgram->resize(770, 530);
        AboutProgram->setMinimumSize(QSize(770, 530));
        AboutProgram->setMaximumSize(QSize(770, 530));
        AboutProgram->setStyleSheet(QLatin1String("background-color: rgb(58, 37, 179);\n"
""));
        label_title = new QLabel(AboutProgram);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(240, 50, 341, 41));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_title->setFont(font);
        label_line1 = new QLabel(AboutProgram);
        label_line1->setObjectName(QStringLiteral("label_line1"));
        label_line1->setGeometry(QRect(130, 130, 581, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(10);
        label_line1->setFont(font1);
        label_line2 = new QLabel(AboutProgram);
        label_line2->setObjectName(QStringLiteral("label_line2"));
        label_line2->setGeometry(QRect(130, 190, 581, 31));
        label_line2->setFont(font1);
        label_line3 = new QLabel(AboutProgram);
        label_line3->setObjectName(QStringLiteral("label_line3"));
        label_line3->setGeometry(QRect(130, 250, 581, 31));
        label_line3->setFont(font1);
        label_line4 = new QLabel(AboutProgram);
        label_line4->setObjectName(QStringLiteral("label_line4"));
        label_line4->setGeometry(QRect(130, 310, 581, 31));
        label_line4->setFont(font1);
        close = new QPushButton(AboutProgram);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(270, 450, 211, 51));
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

        retranslateUi(AboutProgram);

        QMetaObject::connectSlotsByName(AboutProgram);
    } // setupUi

    void retranslateUi(QWidget *AboutProgram)
    {
        AboutProgram->setWindowTitle(QApplication::translate("AboutProgram", "A B O U T   P R O G R A M", 0));
        label_title->setText(QApplication::translate("AboutProgram", "ABOUT PROGRAM", 0));
        label_line1->setText(QApplication::translate("AboutProgram", "line_1", 0));
        label_line2->setText(QApplication::translate("AboutProgram", "line_2", 0));
        label_line3->setText(QApplication::translate("AboutProgram", "line_3", 0));
        label_line4->setText(QApplication::translate("AboutProgram", "line_4", 0));
        close->setText(QApplication::translate("AboutProgram", "close", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutProgram: public Ui_AboutProgram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPROGRAM_H
