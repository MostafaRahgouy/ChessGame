#ifndef ABOUTPROGRAMMERS_H
#define ABOUTPROGRAMMERS_H

#include <QWidget>

namespace Ui {
class AboutProgrammers;
}

class AboutProgrammers : public QWidget
{
    Q_OBJECT

public:
    explicit AboutProgrammers(QWidget *parent = 0);
    ~AboutProgrammers();

private slots:
    void on_close_clicked();

private:
    Ui::AboutProgrammers *ui;
};

#endif // ABOUTPROGRAMMERS_H
