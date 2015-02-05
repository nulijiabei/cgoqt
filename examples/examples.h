#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTextCodec>
#include "cgo.h"

using namespace std;

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
    QTimer* timer;
    Cgo* cgo;

public:

    void sendDisplay(const char *);

    int setCgo(Cgo*);

private slots:

    void sendCommand();

    void sendMessage();

    void on_quit_triggered();

    void on_clear_triggered();

    void on_connect_triggered();

    void on_help_triggered();

    void on_disconn_triggered();

    void on_network_triggered();

    void on_member_triggered();

    void on_save_triggered();

private:
    Ui::Examples *ui;
};

#endif // EXAMPLES_H
