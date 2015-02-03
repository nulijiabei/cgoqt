/********************************************************************************
** Form generated from reading UI file 'examples.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLES_H
#define UI_EXAMPLES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Examples
{
public:
    QAction *connect;
    QAction *disconn;
    QAction *save;
    QAction *upload;
    QAction *download;
    QAction *help;
    QAction *quit;
    QAction *clear;
    QAction *reboot;
    QAction *killall;
    QAction *shutdown;
    QAction *network;
    QAction *openvpn;
    QAction *member;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *display;
    QLineEdit *command;
    QToolBar *toolBar_main;
    QMenuBar *menuBar_main;
    QMenu *menu_main;
    QMenu *menu_tool;
    QToolBar *toolBar_tool;

    void setupUi(QMainWindow *Examples)
    {
        if (Examples->objectName().isEmpty())
            Examples->setObjectName(QString::fromUtf8("Examples"));
        Examples->resize(800, 600);
        Examples->setMinimumSize(QSize(0, 0));
        Examples->setMaximumSize(QSize(16777215, 16777215));
        connect = new QAction(Examples);
        connect->setObjectName(QString::fromUtf8("connect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/conn.png"), QSize(), QIcon::Normal, QIcon::Off);
        connect->setIcon(icon);
        connect->setShortcutContext(Qt::WidgetWithChildrenShortcut);
        disconn = new QAction(Examples);
        disconn->setObjectName(QString::fromUtf8("disconn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/disc.png"), QSize(), QIcon::Normal, QIcon::Off);
        disconn->setIcon(icon1);
        save = new QAction(Examples);
        save->setObjectName(QString::fromUtf8("save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon2);
        upload = new QAction(Examples);
        upload->setObjectName(QString::fromUtf8("upload"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upload->setIcon(icon3);
        download = new QAction(Examples);
        download->setObjectName(QString::fromUtf8("download"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        download->setIcon(icon4);
        help = new QAction(Examples);
        help->setObjectName(QString::fromUtf8("help"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon5);
        quit = new QAction(Examples);
        quit->setObjectName(QString::fromUtf8("quit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit->setIcon(icon6);
        clear = new QAction(Examples);
        clear->setObjectName(QString::fromUtf8("clear"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clear->setIcon(icon7);
        reboot = new QAction(Examples);
        reboot->setObjectName(QString::fromUtf8("reboot"));
        killall = new QAction(Examples);
        killall->setObjectName(QString::fromUtf8("killall"));
        shutdown = new QAction(Examples);
        shutdown->setObjectName(QString::fromUtf8("shutdown"));
        network = new QAction(Examples);
        network->setObjectName(QString::fromUtf8("network"));
        openvpn = new QAction(Examples);
        openvpn->setObjectName(QString::fromUtf8("openvpn"));
        member = new QAction(Examples);
        member->setObjectName(QString::fromUtf8("member"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/mm.png"), QSize(), QIcon::Normal, QIcon::Off);
        member->setIcon(icon8);
        centralwidget = new QWidget(Examples);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        display = new QTextBrowser(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));

        verticalLayout->addWidget(display);

        command = new QLineEdit(centralwidget);
        command->setObjectName(QString::fromUtf8("command"));
        command->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(command);


        horizontalLayout_2->addLayout(verticalLayout);

        Examples->setCentralWidget(centralwidget);
        toolBar_main = new QToolBar(Examples);
        toolBar_main->setObjectName(QString::fromUtf8("toolBar_main"));
        Examples->addToolBar(Qt::TopToolBarArea, toolBar_main);
        menuBar_main = new QMenuBar(Examples);
        menuBar_main->setObjectName(QString::fromUtf8("menuBar_main"));
        menuBar_main->setGeometry(QRect(0, 0, 800, 22));
        menu_main = new QMenu(menuBar_main);
        menu_main->setObjectName(QString::fromUtf8("menu_main"));
        menu_tool = new QMenu(menuBar_main);
        menu_tool->setObjectName(QString::fromUtf8("menu_tool"));
        Examples->setMenuBar(menuBar_main);
        toolBar_tool = new QToolBar(Examples);
        toolBar_tool->setObjectName(QString::fromUtf8("toolBar_tool"));
        Examples->addToolBar(Qt::TopToolBarArea, toolBar_tool);
        Examples->insertToolBarBreak(toolBar_tool);

        toolBar_main->addAction(connect);
        toolBar_main->addAction(disconn);
        toolBar_main->addSeparator();
        toolBar_main->addAction(member);
        toolBar_main->addSeparator();
        toolBar_main->addAction(upload);
        toolBar_main->addAction(download);
        toolBar_main->addSeparator();
        toolBar_main->addAction(save);
        toolBar_main->addAction(clear);
        toolBar_main->addSeparator();
        toolBar_main->addAction(help);
        toolBar_main->addSeparator();
        toolBar_main->addAction(quit);
        menuBar_main->addAction(menu_main->menuAction());
        menuBar_main->addAction(menu_tool->menuAction());
        menu_main->addAction(connect);
        menu_main->addAction(disconn);
        menu_main->addSeparator();
        menu_main->addAction(member);
        menu_main->addSeparator();
        menu_main->addAction(save);
        menu_main->addSeparator();
        menu_main->addAction(upload);
        menu_main->addAction(download);
        menu_main->addSeparator();
        menu_main->addAction(clear);
        menu_main->addSeparator();
        menu_main->addAction(help);
        menu_main->addSeparator();
        menu_main->addAction(quit);
        menu_tool->addAction(reboot);
        menu_tool->addAction(killall);
        menu_tool->addAction(shutdown);
        menu_tool->addAction(network);
        menu_tool->addAction(openvpn);
        toolBar_tool->addAction(network);
        toolBar_tool->addSeparator();
        toolBar_tool->addAction(openvpn);
        toolBar_tool->addSeparator();
        toolBar_tool->addAction(killall);
        toolBar_tool->addSeparator();
        toolBar_tool->addAction(reboot);
        toolBar_tool->addSeparator();
        toolBar_tool->addAction(shutdown);

        retranslateUi(Examples);

        QMetaObject::connectSlotsByName(Examples);
    } // setupUi

    void retranslateUi(QMainWindow *Examples)
    {
        Examples->setWindowTitle(QString());
        connect->setText(QApplication::translate("Examples", "\350\277\236\346\216\245(&N)", 0, QApplication::UnicodeUTF8));
        connect->setIconText(QApplication::translate("Examples", "\350\277\236\346\216\245(N)", 0, QApplication::UnicodeUTF8));
        disconn->setText(QApplication::translate("Examples", "\346\226\255\345\274\200(&C)", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("Examples", "\344\277\235\345\255\230(&S)", 0, QApplication::UnicodeUTF8));
        upload->setText(QApplication::translate("Examples", "\344\270\212\344\274\240(&U)", 0, QApplication::UnicodeUTF8));
        download->setText(QApplication::translate("Examples", "\344\270\213\350\275\275(&D)", 0, QApplication::UnicodeUTF8));
        help->setText(QApplication::translate("Examples", "\345\270\256\345\212\251(&H)", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("Examples", "\351\200\200\345\207\272(&Q)", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("Examples", "\346\270\205\347\220\206(&C)", 0, QApplication::UnicodeUTF8));
        reboot->setText(QApplication::translate("Examples", "\351\207\215\345\220\257\347\263\273\347\273\237(&R)", 0, QApplication::UnicodeUTF8));
        killall->setText(QApplication::translate("Examples", "\351\207\215\345\220\257\347\250\213\345\272\217(&K)", 0, QApplication::UnicodeUTF8));
        shutdown->setText(QApplication::translate("Examples", "\345\205\263\351\227\255\347\263\273\347\273\237(&D)", 0, QApplication::UnicodeUTF8));
        network->setText(QApplication::translate("Examples", "\347\275\221\347\273\234\344\277\241\346\201\257(&N)", 0, QApplication::UnicodeUTF8));
        openvpn->setText(QApplication::translate("Examples", "\344\270\223\347\224\250\347\275\221\347\273\234(&V)", 0, QApplication::UnicodeUTF8));
        member->setText(QApplication::translate("Examples", "\350\267\263\350\267\203(&T)", 0, QApplication::UnicodeUTF8));
        toolBar_main->setWindowTitle(QApplication::translate("Examples", "toolBar", 0, QApplication::UnicodeUTF8));
        menu_main->setTitle(QApplication::translate("Examples", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        menu_tool->setTitle(QApplication::translate("Examples", "\345\267\245\345\205\267(&T)", 0, QApplication::UnicodeUTF8));
        toolBar_tool->setWindowTitle(QApplication::translate("Examples", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Examples: public Ui_Examples {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLES_H
