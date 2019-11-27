#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QWidget>

namespace Ui {
class AboutProgram;
}

class AboutProgram : public QWidget
{
    Q_OBJECT

public:
    explicit AboutProgram(QWidget *parent = 0);
    ~AboutProgram();

private slots:
    void on_close_clicked();

private:
    Ui::AboutProgram *ui;
};

#endif // ABOUTPROGRAM_H
