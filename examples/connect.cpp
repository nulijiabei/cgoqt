#include "connect.h"
#include "ui_connect.h"
#include "cgo.h"

Connect::Connect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connect)
{
    ui->setupUi(this);
}

Connect::~Connect()
{
    delete ui;
}

int Connect::setCgo(Cgo *_a)
{
    cgo = _a;
    return 1;
}

void Connect::on_pushButton_clicked()
{
    this->close();
}

void Connect::on_pushButton_2_clicked()
{

    if(ui->lineEdit->text().isEmpty())
    {
        return;
    }
    int c = cgo->cgo_checkconn();
    if (c == 1)
    {
        QMessageBox::information(this, tr("连接"), tr("如需连接其它设备,请先断开当前连接."), QMessageBox::Yes);
        return;
    }
    int n = cgo->cgo_connect((void*)ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length(),
                             (void*)ui->lineEdit_2->text().toLatin1().data(), ui->lineEdit_2->text().length());
    if (n == 1)
    {
        this->hide();
        QMessageBox::information(this, tr("连接"), tr("连接服务器成功."), QMessageBox::Yes);
        this->close();
    }
    else
    {
        QMessageBox::information(this, tr("连接"), tr("连接服务器失败."), QMessageBox::Yes);
    }
}
