#include "widget.h"
#include "ui_widget.h"
#include "QTcpServer"
#include "QTcpSocket"
#include "QTextStream"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new QTcpServer(this);
    mSocket = nullptr;

    connect(mServer, &QTcpServer::newConnection, [&]() {
        mSocket = mServer->nextPendingConnection();
    });

    mServer->listen(QHostAddress::Any, 4444);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if (mSocket == nullptr){
        return;
    }
    QTextStream T(mSocket);
    T << ui->lineEditm->text();
    mSocket->flush();

}

void Widget::on_pushButton_2_clicked()
{
    QTextStream T(mSocket);
    T << "Fasten your seatbelt!";
    mSocket->flush();

}

