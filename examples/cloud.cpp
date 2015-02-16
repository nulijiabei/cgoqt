#include "cloud.h"
#include "ui_cloud.h"

Cloud::Cloud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cloud)
{
    ui->setupUi(this);
    this->ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    this->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    this->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    this->ui->tableWidget->setAlternatingRowColors(true);
    QStringList header;
    header<< "ID" <<"NAME "<<"年龄"<<"sex"<<"data";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(5);

}

Cloud::~Cloud()
{
    delete ui;
}

int Cloud::setCgo(Cgo *_a)
{
    cgo = _a;
    return 1;
}
