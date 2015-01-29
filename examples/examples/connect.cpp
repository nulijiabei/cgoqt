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

void Connect::on_pushButton_clicked()
{
    this->close();
}

void Connect::on_pushButton_2_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        int c = cgo_checkconn();
        if (c == 1)
        {
            QMessageBox::information(this, tr("连接"), tr("请先断开当前与服务器连接!"), QMessageBox::Yes);
            return;
        }
        int n = cgo_connect((void*)ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length());
        if (n == 1)
        {
            this->hide();
            QMessageBox::information(this, tr("连接"), tr("连接服务器成功!"), QMessageBox::Yes);
            this->close();
        }
        else
        {
            QMessageBox::information(this, tr("连接"), tr("连接服务器失败!"), QMessageBox::Yes);
        }
    } else {
        QMessageBox::information(this, tr("连接"), tr("请输入设备地址!"), QMessageBox::Yes);
    }
}
