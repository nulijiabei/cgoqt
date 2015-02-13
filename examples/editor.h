#ifndef EDITOR_H
#define EDITOR_H


#include <QDialog>
#include "cgo.h"

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    Cgo *cgo;

public:
    int setCgo(Cgo*);

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private slots:
    void sendPathToCgo();
    void on_pushButton_clicked();
    void on_content_signal(const QString &);

    void on_pushButton_2_clicked();

private:
    Ui::Editor *ui;
};

#endif // EDITOR_H
