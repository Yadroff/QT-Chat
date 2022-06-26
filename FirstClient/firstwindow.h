#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTime>

const qint16 FIRST_PORT = 7777;
const qint16 SECOND_PORT = 5555;

QT_BEGIN_NAMESPACE
namespace Ui { class FirstWindow; }
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();
public slots:
    void ReadingData(); // чтение данных
private slots:
    void on_pushButton_clicked(); // отправка данных
private:
    Ui::FirstWindow *ui;
    QUdpSocket *socket;
};
#endif // FIRSTWINDOW_H
