#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <QtGui>

namespace Ui {
class Examples;
}

class Examples : public QMainWindow
{
    Q_OBJECT

public:
    explicit Examples(QWidget *parent = 0);
    ~Examples();

private:
    Ui::Examples *ui;
};

#endif // EXAMPLES_H
