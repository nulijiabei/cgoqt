#include "examples.h"
#include "ui_examples.h"
#include "connect.h"
#include "cgo.h"

Examples::Examples(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Examples)
{
    ui->setupUi(this);
    // ...
    ui->display->append(tr("Welcome to Goline"));
    ui->display->append(tr("[ 警告 ] 前台常驻命令禁止使用."));
    ui->display->append(tr("[ 提示 ] 通过帮助查看使用方法."));
    // 关闭自动换行
    ui->display->setWordWrapMode(QTextOption::NoWrap);
    // 改变背景色
    QPalette pal = ui->display->palette();
    pal.setColor(QPalette::Base, QColor(255,228,196));
    ui->display->setPalette(pal);
    // 信号连接
    connect(ui->command, SIGNAL(returnPressed()), this, SLOT(sendCommand()));
}

Examples::~Examples()
{
    delete ui;
}

void Examples::on_quit_triggered()
{
    this->close();
}

void Examples::on_clear_triggered()
{
    ui->display->clear();
}

void Examples::sendCommand()
{
    if(ui->command->text().isEmpty())
    {
        return;
    }
    QString command = "# ";
    command.append(ui->command->text());
    ui->display->append(command.toLatin1().data());
    int n = cgo_command((void*)ui->command->text().toLatin1().data(), ui->command->text().toLatin1().length());
    if (n == 1)
    {
        ui->display->append(tr("> 命令提交成功."));
    }
    else
    {
        ui->display->append(tr("> 命令提交失败，请检查连接."));
    }
    ui->display->moveCursor(QTextCursor::End);
    ui->command->clear();
}

void Examples::sendDisplay(const char * _content)
{
    ui->display->append(tr(_content));
    ui->display->moveCursor(QTextCursor::End);
}

void Examples::on_connect_triggered()
{
    Connect conn(this);
    conn.exec();
}

void Examples::on_help_triggered()
{
    QMessageBox::information(this, tr("帮助"), tr("2015-01-28"), QMessageBox::Yes);
}
