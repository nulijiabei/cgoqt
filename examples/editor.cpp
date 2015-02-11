#include <QDebug>
#include <QMessageBox>
#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(sendPathToCgo()));
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_pushButton_clicked()
{
    hide();
}

int Editor::setCgo(Cgo *_a)
{
    cgo = _a;
    return 1;
}

void Editor::sendPathToCgo()
{
    if(ui->lineEdit->text().isEmpty())
    {
        return;
    }
    int c = cgo->cgo_checkconn();
    if (c != 1)
    {
        QMessageBox::information(this, tr("连接"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    cgo->cgo_reader(ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length());
}

void Editor::on_content_signal(const QString &_content)
{
    ui->plainTextEdit->setPlainText(_content);
}
