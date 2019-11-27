/********************************************************************************
** Form generated from reading UI file 'messageform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFORM_H
#define UI_MESSAGEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_messageForm
{
public:
    QPushButton *ok;
    QPushButton *messageImage;
    QLabel *messageText;

    void setupUi(QWidget *messageForm)
    {
        if (messageForm->objectName().isEmpty())
            messageForm->setObjectName(QStringLiteral("messageForm"));
        messageForm->setWindowModality(Qt::ApplicationModal);
        messageForm->resize(460, 314);
        messageForm->setMinimumSize(QSize(460, 100));
        messageForm->setMaximumSize(QSize(460, 370));
        messageForm->setStyleSheet(QStringLiteral("background-color: rgb(88, 30, 3);"));
        ok = new QPushButton(messageForm);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(120, 260, 241, 41));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        ok->setFont(font);
        ok->setStyleSheet(QLatin1String("\n"
"QPushButton#ok:hover{\n"
"    background-color: rgb(99, 199, 147);\n"
"};\n"
"background-color: rgb(255, 255, 255);"));
        messageImage = new QPushButton(messageForm);
        messageImage->setObjectName(QStringLiteral("messageImage"));
        messageImage->setGeometry(QRect(30, 20, 411, 201));
        messageImage->setFlat(true);
        messageText = new QLabel(messageForm);
        messageText->setObjectName(QStringLiteral("messageText"));
        messageText->setGeometry(QRect(120, 220, 241, 31));
        messageText->setFont(font);

        retranslateUi(messageForm);

        QMetaObject::connectSlotsByName(messageForm);
    } // setupUi

    void retranslateUi(QWidget *messageForm)
    {
        messageForm->setWindowTitle(QApplication::translate("messageForm", "M E S S A G E    B O X", 0));
        ok->setText(QApplication::translate("messageForm", "ok", 0));
        messageImage->setText(QString());
        messageText->setText(QApplication::translate("messageForm", "textMassage", 0));
    } // retranslateUi

};

namespace Ui {
    class messageForm: public Ui_messageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFORM_H
