/********************************************************************************
** Form generated from reading UI file 'goline.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOLINE_H
#define UI_GOLINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Goline
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_c;
    QLabel *label_c;
    QLineEdit *ipaddr;
    QHBoxLayout *horizontalLayout_a;
    QLabel *label_a;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_b;
    QLabel *label_b;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_d;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Goline)
    {
        if (Goline->objectName().isEmpty())
            Goline->setObjectName(QString::fromUtf8("Goline"));
        Goline->resize(400, 200);
        verticalLayout_2 = new QVBoxLayout(Goline);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Goline);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_c = new QHBoxLayout();
        horizontalLayout_c->setObjectName(QString::fromUtf8("horizontalLayout_c"));
        label_c = new QLabel(Goline);
        label_c->setObjectName(QString::fromUtf8("label_c"));

        horizontalLayout_c->addWidget(label_c);

        ipaddr = new QLineEdit(Goline);
        ipaddr->setObjectName(QString::fromUtf8("ipaddr"));
        ipaddr->setMinimumSize(QSize(0, 25));

        horizontalLayout_c->addWidget(ipaddr);


        verticalLayout->addLayout(horizontalLayout_c);

        horizontalLayout_a = new QHBoxLayout();
        horizontalLayout_a->setObjectName(QString::fromUtf8("horizontalLayout_a"));
        label_a = new QLabel(Goline);
        label_a->setObjectName(QString::fromUtf8("label_a"));

        horizontalLayout_a->addWidget(label_a);

        username = new QLineEdit(Goline);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(0, 25));

        horizontalLayout_a->addWidget(username);


        verticalLayout->addLayout(horizontalLayout_a);

        horizontalLayout_b = new QHBoxLayout();
        horizontalLayout_b->setObjectName(QString::fromUtf8("horizontalLayout_b"));
        label_b = new QLabel(Goline);
        label_b->setObjectName(QString::fromUtf8("label_b"));

        horizontalLayout_b->addWidget(label_b);

        password = new QLineEdit(Goline);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(10, 25));

        horizontalLayout_b->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_b);

        horizontalLayout_d = new QHBoxLayout();
        horizontalLayout_d->setObjectName(QString::fromUtf8("horizontalLayout_d"));
        checkBox = new QCheckBox(Goline);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_d->addWidget(checkBox, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_d);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(Goline);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(Goline);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Goline);

        QMetaObject::connectSlotsByName(Goline);
    } // setupUi

    void retranslateUi(QDialog *Goline)
    {
        Goline->setWindowTitle(QApplication::translate("Goline", "\350\267\263\350\267\203", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Goline", "\350\267\263\350\267\203(\347\231\273\345\275\225)\345\210\260\345\261\200\345\237\237\347\275\221\344\270\255\347\232\204\345\217\246\345\244\226\344\270\200\345\217\260\350\256\276\345\244\207.", 0, QApplication::UnicodeUTF8));
        label_c->setText(QApplication::translate("Goline", "\347\275\221\347\273\234\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        ipaddr->setText(QApplication::translate("Goline", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_a->setText(QApplication::translate("Goline", "\347\224\250\346\210\267\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Goline", "root", 0, QApplication::UnicodeUTF8));
        label_b->setText(QApplication::translate("Goline", "\347\224\250\346\210\267\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        password->setText(QApplication::translate("Goline", "123456", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Goline", " - \346\230\276\347\244\272\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Goline", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Goline", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Goline: public Ui_Goline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOLINE_H
