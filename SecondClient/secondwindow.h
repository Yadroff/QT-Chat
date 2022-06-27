#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTime>

const qint16 FIRST_PORT = 7777;
const qint16 SECOND_PORT = 5555;

QT_BEGIN_NAMESPACE
namespace Ui { class SecondWindow; }
QT_END_NAMESPACE

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

public slots:
    void ReadingData(); //чтение
private slots:
    void on_pushButton_clicked(); //запись

private:
    Ui::SecondWindow *ui;
    QUdpSocket *socket;
};
#endif // SECONDWINDOW_H
