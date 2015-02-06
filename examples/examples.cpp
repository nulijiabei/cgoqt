#include "examples.h"
#include "ui_examples.h"
#include "connect.h"
#include "goline.h"
#include "cgo.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

Examples::Examples(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Examples)
{
    ui->setupUi(this);
    // ...
    ui->display->append("");
    ui->display->append(tr("Welcome to Goline"));
    ui->display->append("");
    ui->display->append(tr("[ 警告 ] 前台常驻命令禁止使用."));
    ui->display->append(tr("[ 提示 ] 通过帮助查看使用方法."));
    ui->display->append("");
    // 关闭自动换行
    ui->display->setWordWrapMode(QTextOption::NoWrap);
    // 改变背景色
    QPalette pal = ui->display->palette();
    pal.setColor(QPalette::Base, QColor(255,228,196));
    ui->display->setPalette(pal);
    // 信号连接
    connect(ui->command, SIGNAL(returnPressed()), this, SLOT(sendCommand()));
    // 定时器
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(sendMessage()));
    timer->start(100);
    // ...
    history = new QStringList();
    model = new QStandardItemModel(0, 1, this);
    completer = new QCompleter(model, this);
    ui->command->setCompleter(completer);
    connect(completer, SIGNAL(activated(const QString&)), this, SLOT(onCommandChoosed(const QString&)));
    connect(ui->command, SIGNAL(textChanged(const QString&)), this, SLOT(onCommandChanged(const QString&)));
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
    // ...
    appendHistory(ui->command->text());
    // ...
    QString command;
    command.append("<pre>");
    command.append("# ");
    command.append(ui->command->text());
    command.append("</pre>");
    ui->display->append(command.toLatin1().data());
    cgo->cgo_command((void*)ui->command->text().toLatin1().data(), ui->command->text().toLatin1().length());
    ui->display->moveCursor(QTextCursor::End);
    ui->command->clear();
}

void Examples::appendHistory(const QString &_str)
{
    for (int i = 0; i < history->size(); ++i)
    {
        if (history->at(i).compare(_str.trimmed()) == 0)
        {
            return;
        }
    }
    history->append(_str.trimmed());
}

void Examples::sendDisplay(const char * _content)
{
    QString command;
    command.append("<pre>");
    command.append(tr(_content));
    command.append("</pre>");
    ui->display->append(command);
    ui->display->moveCursor(QTextCursor::End);
}

void Examples::sendMessage()
{
    void * p = cgo->cgo_message();
    QString command = (char*)p;
    if (!command.isEmpty())
    {
        QMessageBox::information(this, tr("提示"), tr(command.toLatin1().data()), QMessageBox::Yes);
    }
}

void Examples::on_connect_triggered()
{
    Connect conn(this);
    conn.setCgo(cgo);
    conn.exec();
}

void Examples::on_help_triggered()
{
    QMessageBox::information(this, tr("帮助"), tr("德纳科技"), QMessageBox::Yes);
}

void Examples::on_disconn_triggered()
{
    int n = cgo->cgo_checkconn();
    if (n != 1)
    {
        QMessageBox::information(this, tr("断开"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::information(this, tr("断开"), tr("您确定要断开当前连接吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        cgo->cgo_disconn();
    }
}

void Examples::on_network_triggered()
{
    int n = cgo->cgo_checkconn();
    if (n != 1)
    {
        QMessageBox::information(this, tr("提示"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QString command;
    command.append("network");
    cgo->cgo_shortcuts(command.toLatin1().data(), command.toLatin1().length());
}

void Examples::on_member_triggered()
{
    Goline goline(this);
    goline.setCgo(cgo);
    goline.exec();
}

int Examples::setCgo(Cgo *_a)
{
    cgo = _a;
    return 0;
}

void Examples::on_save_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("保存"), "./history.txt", tr("Text files (*.txt)"));
    if (!path.isEmpty())
    {
        QFile *file = new QFile;
        file->setFileName(path);
        bool ok = file->open(QIODevice::WriteOnly);
        if (ok) {
            QTextStream out(file);
            out << ui->display->toPlainText();
            file->close();
            QMessageBox::information(this, tr("提示"), tr("保存文件成功."), QMessageBox::Yes);
        }
        else
        {
            QMessageBox::information(this, tr("提示"), tr("保存文件失败."), QMessageBox::Yes);
        }
        delete file;
    }
}

void Examples::onCommandChoosed(const QString& _command)
{
    // 清除已存在的文本更新内容
    ui->command->clear();
    ui->command->setText(_command);
}

void Examples::onCommandChanged(const QString& _str)
{
    // 清楚已经存在的数据
    model->removeRows(0, model->rowCount());

    // 遍历所有的命令
    for (int i = 0; i < history->size(); ++i)
    {
        // 插入包含关键字的数据
        if (history->at(i).startsWith(_str))
        {
            model->insertRow(0);
            model->setData(model->index(0, 0), history->at(i));
        }
    }
}
