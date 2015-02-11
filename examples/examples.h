#ifndef EXAMPLES_H
#define EXAMPLES_H


#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QStandardItemModel>
#include <QCompleter>
#include "cgo.h"
#include "editor.h"

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
    Cgo *cgo;
    QTimer *timer;
    Editor *edit;

public:
    void recvDisplayByCgo(const char *);
    void recvMessageByCgo(const char *);
    void recvContentByCgo(const char *);
    int setCgo(Cgo*);

protected:
    bool eventFilter(QObject *obj, QEvent *ev);

signals:
    void send_message_signal(const QString &);
    void send_content_signal(const QString &);

private slots:
    void sendCommandsToCgo();
    void on_message_signal(const QString &);

private slots:
    void on_quit_triggered();
    void on_clear_triggered();
    void on_connect_triggered();
    void on_help_triggered();
    void on_disconn_triggered();
    void on_network_triggered();
    void on_member_triggered();
    void on_save_triggered();

    void on_edit_triggered();

private:
    Ui::Examples *ui;

};

#endif // EXAMPLES_H
