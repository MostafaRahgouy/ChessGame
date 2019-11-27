#ifndef PROMOTE_H
#define PROMOTE_H

#include <QDialog>
#include "QPushButton"
#include "PieceType.h"
#include "PieceColor.h"
namespace Ui {
class promote;
}

class promote : public QDialog
{
    Q_OBJECT
public:
    int choose;
    explicit promote(QDialog *parent = 0);
    ~promote();
    void initPromoteBlackNuts();
    void initPromoteWhiteNuts();
    int getChooseNutsNumber();
    static PieceType promotePawn(PieceColor turn);

private slots:
    void on_Queen_clicked();
    void on_Rock_clicked();
    void on_Bishop_clicked();
    void on_Knight_clicked();

private:
    Ui::promote *pro;
};

#endif // PROMOTE_H
