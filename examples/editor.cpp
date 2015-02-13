#include <QDebug>
#include <QMessageBox>
#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    // 关闭自动换行
    ui->plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
    // 开启焦点选择
    ui->plainTextEdit->setFocus();
    // 关闭焦点选择
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    // 输入提示
    ui->lineEdit->setPlaceholderText(tr("提示：请在此处键入要编辑的文件或目录的完整路径."));
    // 连接
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

void Editor::on_pushButton_2_clicked()
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
    QString info;
    info.append(tr("<p style=color:red>该编辑器不支持(跳跃)后的设备文件编辑，点击确定说明您已经知晓该操作可能造成的严重后果.</p>"));
    info.append(tr("<p style=color:red>您确定要把当前编辑的内容(保存或覆盖)到文件吗?</p>"));
    info.append("(");
    info.append(ui->lineEdit->text());
    info.append(")");
    QMessageBox::StandardButton rb = QMessageBox::information(this, tr("保存"), info, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
        cgo->cgo_writer(ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length(),
                        ui->plainTextEdit->toPlainText().toLatin1().data(), ui->plainTextEdit->toPlainText().toLatin1().length());
}
