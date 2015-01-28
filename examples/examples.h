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

public:
    QTimer * timer;

public:
    void sendDisplay(const char *);

private slots:

    void sendCommand();

    void on_quit_triggered();

    void on_clear_triggered();

    void on_connect_triggered();

    void on_help_triggered();

private:
    Ui::Examples *ui;
};

#endif // EXAMPLES_H
