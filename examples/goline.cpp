#include <QDebug>
#include "goline.h"
#include "ui_goline.h"
#include "cgo.h"

Goline::Goline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Goline)
{
    ui->setupUi(this);
}

Goline::~Goline()
{
    delete ui;
}

int Goline::setCgo(Cgo *_a)
{
    cgo = _a;
    return 0;
}

void Goline::on_pushButton_clicked()
{
    this->close();
}

void Goline::on_pushButton_2_clicked()
{
    if (ui->ipaddr->text().isEmpty() || ui->username->text().isEmpty() || ui->password->text().isEmpty())
    {
        return;
    }
    int c = cgo->cgo_checkconn();
    if (c != 1)
    {
        QMessageBox::information(this, tr("提示"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QString goline;
    goline.append(ui->ipaddr->text());
    goline.append(" ");
    goline.append(ui->username->text());
    goline.append(" ");
    goline.append(ui->password->text());
    goline.append(" ");
    if (ui->checkBox->checkState() == Qt::Checked)
    {
        goline.append("true");
    }
    else
    {
        goline.append("false");
    }
    cgo->cgo_goline(goline.toLatin1().data(), goline.toLatin1().length());
    this->close();
}
