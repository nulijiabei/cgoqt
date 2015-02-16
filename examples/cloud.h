#ifndef CLOUD_H
#define CLOUD_H

#include <QDialog>
#include "cgo.h"

namespace Ui {
class Cloud;
}

class Cloud : public QDialog
{
    Q_OBJECT

public:
    explicit Cloud(QWidget *parent = 0);
    ~Cloud();

public:
    Cgo *cgo;

public:
    int setCgo(Cgo*);

private:
    Ui::Cloud *ui;
};

#endif // CLOUD_H
