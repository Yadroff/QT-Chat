#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QDebug>

SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket();
    socket->bind(QHostAddress::LocalHost, SECOND_PORT);
    connect(socket, SIGNAL(readyRead()), this, SLOT(ReadingData()));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::ReadingData()
{
    QHostAddress sender;
    quint16 senderPort;
    while (socket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        ui->textEdit->append("<font color=red>" + QTime::currentTime().toString("HH:mm:ss") + " " + QString(datagram) + "</font>");
    }
}


void SecondWindow::on_pushButton_clicked()
{
    socket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, FIRST_PORT);
    ui->textEdit->append("Вы: <font color = blue>" + QTime::currentTime().toString("HH:mm:ss") + " " + ui->lineEdit->text() + "</font>");
    ui->lineEdit->clear();
}

