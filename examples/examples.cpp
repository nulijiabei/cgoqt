#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QKeyEvent>
#include "examples.h"
#include "ui_examples.h"
#include "connect.h"
#include "goline.h"
#include "cgo.h"
#include "editor.h"


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
    connect(ui->command, SIGNAL(returnPressed()), this, SLOT(sendCommandsToCgo()));
    connect(this, SIGNAL(send_message_signal(const QString&)), this, SLOT(on_message_signal(const QString&)));
    // 事件捕捉
    ui->command->installEventFilter(this);
    // 文本编辑器
    edit = new Editor(this);
    connect(this, SIGNAL(send_content_signal(const QString&)), edit, SLOT(on_content_signal(const QString&)));
    // ...
}

Examples::~Examples()
{
    delete ui;
}

// CGO
void Examples::recvMessageByCgo(const char *_content)
{
    // 由于CGO无法直接调用到QMessageBox所以此处使用信号发送
    QString command = (char*)_content;
    if (!command.isEmpty())
        emit send_message_signal(command);
}

// CGO
void Examples::recvDisplayByCgo(const char *_content)
{
    QString command;
    command.append("<pre>");
    command.append(tr(_content));
    command.append("</pre>");
    ui->display->append(command);
    ui->display->moveCursor(QTextCursor::End);
}

// CGO
void Examples::recvContentByCgo(const char *_content)
{
    emit send_content_signal(tr(_content));
}

void Examples::on_message_signal(const QString &_content)
{
    QMessageBox::information(this, tr("提示"), tr(_content.toLatin1().data()), QMessageBox::Yes);
}

void Examples::on_quit_triggered()
{
    this->close();
}

void Examples::on_clear_triggered()
{
    ui->display->clear();
}

void Examples::sendCommandsToCgo()
{
    if(ui->command->text().isEmpty())
        return;
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
        cgo->cgo_disconn();
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
    return 1;
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
            QMessageBox::information(this, tr("提示"), tr("保存文件失败."), QMessageBox::Yes);
        delete file;
    }
}

bool Examples::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->command) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Tab)
            {
                //
            }
            else
                return QMainWindow::eventFilter(obj, event);
            return true;
        } else
            return false;
    } else
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
}

// ...
void Examples::on_edit_triggered()
{
    edit->setCgo(cgo);
    edit->show();
}

void Examples::on_killall_triggered()
{
    int n = cgo->cgo_checkconn();
    if (n != 1)
    {
        QMessageBox::information(this, tr("提示"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::information(this, tr("提示"), tr("您确定要重启程序吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        QString command;
        command.append("pkill");
        cgo->cgo_shortcuts(command.toLatin1().data(), command.toLatin1().length());
    }
}

void Examples::on_reboot_triggered()
{
    int n = cgo->cgo_checkconn();
    if (n != 1)
    {
        QMessageBox::information(this, tr("提示"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::information(this, tr("提示"), tr("您确定要重启系统吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        QString command;
        command.append("reboot");
        cgo->cgo_shortcuts(command.toLatin1().data(), command.toLatin1().length());
    }
}

void Examples::on_shutdown_triggered()
{
    int n = cgo->cgo_checkconn();
    if (n != 1)
    {
        QMessageBox::information(this, tr("提示"), tr("未连接服务器,请先连接."), QMessageBox::Yes);
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::information(this, tr("提示"), tr("您确定要关闭系统吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        QString command;
        command.append("shutdown");
        cgo->cgo_shortcuts(command.toLatin1().data(), command.toLatin1().length());
    }
}

void Examples::on_upload_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File",QDir::currentPath());
    qDebug() << fileName;
}
