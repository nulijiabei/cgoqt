#ifndef GOLINE_H
#define GOLINE_H


#include <QDialog>
#include <QMessageBox>
#include "cgo.h"


namespace Ui {
class Goline;
}

class Goline : public QDialog
{
    Q_OBJECT

public:
    explicit Goline(QWidget *parent = 0);
    ~Goline();

public:
    Cgo *cgo;

public:
    int setCgo(Cgo*);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Goline *ui;
};

#endif // GOLINE_H
