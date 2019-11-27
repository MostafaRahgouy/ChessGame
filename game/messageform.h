#ifndef MESSAGEFORM_H
#define MESSAGEFORM_H

#include <QWidget>

namespace Ui {
class messageForm;
}

class messageForm : public QWidget
{
    Q_OBJECT

public:
    explicit messageForm(QWidget *parent = 0);
    ~messageForm();
    void checkedMessage();
    void mateMessage();
    void invalidMessage();
    void staleMateMessage();
private slots:
    void on_ok_clicked();

private:
    Ui::messageForm *ms;
};

#endif // MESSAGEFORM_H
