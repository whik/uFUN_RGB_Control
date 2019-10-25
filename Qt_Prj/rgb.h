#ifndef RGB_H
#define RGB_H

#include <QDialog>

#include <QSerialPort>
#include <QSerialPortInfo>
#include "about.h"
////网络相关头文件
//#include <QtNetwork/QNetworkAccessManager>
//#include <QtNetwork/QNetworkRequest>
//#include <QtNetwork/QNetworkReply>
////JSON相关头文件
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>
#include <QTimer>
#include <QDebug>
#include <QtMath>
//#include "about.h"
namespace Ui {
class RGB;
}

class RGB : public QDialog
{
    Q_OBJECT

public:
    explicit RGB(QWidget *parent = 0);
    ~RGB();

    void SetBkgrdColr();
    QString CurVerison = "V1.2";

private slots:
    void on_btn_OpenSerial_clicked();
    void serialPort_readyRead();
    void on_btn_exit_clicked();
    void on_btn_selColor_clicked();

    void on_sb_Red_valueChanged(int arg1);
    void on_sb_Green_valueChanged(int arg1);
    void on_sb_Blue_valueChanged(int arg1);

    void on_hs_Red_valueChanged(int value);
    void on_hs_Green_valueChanged(int value);
    void on_hs_Blue_valueChanged(int value);

    void on_hs_Red_sliderReleased();
    void on_hs_Green_sliderReleased();
    void on_hs_Blue_sliderReleased();
    void UART_Send_RGB_String();
    void on_btn_shut_clicked();
    void on_btn_about_clicked();

    void on_btn_ScanSerial_clicked();

private:
    Ui::RGB *ui;
    QSerialPort serial;
    about ab;
    int parse_UpdateJSON(QString str);


};

#endif // RGB_H
