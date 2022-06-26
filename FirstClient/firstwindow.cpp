#include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, FIRST_PORT);
    connect(socket, SIGNAL(readyRead()), this, SLOT(ReadingData()));
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::ReadingData()
{
 QHostAddress sender;
 quint16 senderPort;
 while (socket->hasPendingDatagrams()){
     QByteArray datagram;
     datagram.resize(socket->pendingDatagramSize());
     socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
     ui->textEdit->append("<font color=red>" + QTime::currentTime().toString("HH:mm::ss") + QString(datagram) + "</font>");
 }
}

void FirstWindow::on_pushButton_clicked()
{
    socket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, SECOND_PORT);
    ui->textEdit->append("Вы: <font color=blue>" + QTime::currentTime().toString("HH:mm:ss") + "\t" + ui->lineEdit->text() + "<\font>");
    ui->lineEdit->clear();
}



