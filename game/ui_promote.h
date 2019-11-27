/********************************************************************************
** Form generated from reading UI file 'promote.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTE_H
#define UI_PROMOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_promote
{
public:
    QPushButton *Queen;
    QPushButton *Rock;
    QPushButton *Bishop;
    QPushButton *Knight;

    void setupUi(QWidget *promote)
    {
        if (promote->objectName().isEmpty())
            promote->setObjectName(QStringLiteral("promote"));
        promote->setWindowModality(Qt::ApplicationModal);
        promote->resize(559, 114);
        promote->setStyleSheet(QStringLiteral("background-color: rgb(88, 30, 3);"));
        Queen = new QPushButton(promote);
        Queen->setObjectName(QStringLiteral("Queen"));
        Queen->setGeometry(QRect(40, 10, 85, 85));
        Queen->setStyleSheet(QLatin1String("\n"
"QPushButton#Queen:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
""));
        Rock = new QPushButton(promote);
        Rock->setObjectName(QStringLiteral("Rock"));
        Rock->setGeometry(QRect(170, 10, 85, 85));
        Rock->setStyleSheet(QLatin1String("\n"
"QPushButton#Rock:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
""));
        Bishop = new QPushButton(promote);
        Bishop->setObjectName(QStringLiteral("Bishop"));
        Bishop->setGeometry(QRect(300, 10, 85, 85));
        Bishop->setStyleSheet(QLatin1String("\n"
"QPushButton#Bishop:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
""));
        Knight = new QPushButton(promote);
        Knight->setObjectName(QStringLiteral("Knight"));
        Knight->setGeometry(QRect(430, 10, 85, 85));
        Knight->setStyleSheet(QLatin1String("\n"
"QPushButton#Knight:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
""));

        retranslateUi(promote);

        QMetaObject::connectSlotsByName(promote);
    } // setupUi

    void retranslateUi(QWidget *promote)
    {
        promote->setWindowTitle(QApplication::translate("promote", "P R O M O T E    P A W N", 0));
        Queen->setText(QString());
        Rock->setText(QString());
        Bishop->setText(QString());
        Knight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class promote: public Ui_promote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTE_H
