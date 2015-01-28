#ifndef CONNECT_H
#define CONNECT_H

#include <QtGui>

namespace Ui {
class Connect;
}

class Connect : public QDialog
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = 0);
    ~Connect();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Connect *ui;
};

#endif // CONNECT_H
