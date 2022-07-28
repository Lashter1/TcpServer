#include "widget.h"
#include "ui_widget.h"
#include "QTcpSocket"
#include "QTextStream"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->listWidget->addItem(text);

    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_connector_clicked()
{
    mSocket->connectToHost("10.10.220.86" , 4444);
}


void Widget::on_seatBelt_clicked()
{
    ui->listWidget->addItem("Have a nice trip.");
    ui->seatBelt->setEnabled(false);

}

