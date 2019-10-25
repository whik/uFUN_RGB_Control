#include "rgb.h"
#include "ui_rgb.h"
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QDesktopServices>

//网络相关头文件
//#include <QtNetwork/QNetworkAccessManager>
//#include <QtNetwork/QNetworkRequest>
//#include <QtNetwork/QNetworkReply>


RGB::RGB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RGB)
{
    ui->setupUi(this);
    /**********************/
    this->setWindowTitle("uFun开发板RGB灯控制 - By wcc "+CurVerison);

    connect(&serial, & QSerialPort::readyRead, this, &RGB::serialPort_readyRead);
    ui->cbb_com->clear();
    //运行开始查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbb_com->addItem(info.portName());  //串口号下拉菜单，增加一个条目，为串口号COM4
//        qDebug() << "串口搜索完成";
    }
    ui->cbb_baud->insertItem(0, "9600");
    ui->cbb_baud->insertItem(1, "115200");
    ui->cbb_baud->insertItem(2, "3000000");
    ui->cbb_baud->insertItem(3, "自定义");

    ui->cbb_baud->setCurrentIndex(1);   //设置默认波特率115200

    ui->hs_Red->setRange(0, 255);
    ui->hs_Green->setRange(0, 255);
    ui->hs_Blue->setRange(0, 255);

    ui->sb_Red->setRange(0, 255);
    ui->sb_Green->setRange(0, 255);
    ui->sb_Blue->setRange(0, 255);

    ui->hs_Red->setDisabled(true);
    ui->hs_Green->setDisabled(true);
    ui->hs_Blue->setDisabled(true);
    ui->sb_Red->setDisabled(true);
    ui->sb_Green->setDisabled(true);
    ui->sb_Blue->setDisabled(true);
    ui->btn_selColor->setDisabled(true);
    ui->btn_shut->setDisabled(true);

}

RGB::~RGB()
{
    delete ui;
}
//串口数据接收并显示
void RGB::serialPort_readyRead()
{
    QByteArray rx_buf= serial.readAll();;

    QString rx_buf_tmp = QString::fromLocal8Bit(rx_buf);    //转换为中文格式

//    qDebug() << rx_buf_tmp;         //控制台输出
    ui->tb_rx_buf->insertPlainText(rx_buf_tmp); //追加显示，末尾不会添加
    rx_buf_tmp.clear();

    rx_buf.clear();

}

void RGB::on_btn_OpenSerial_clicked()
{
    bool status;
    if(this->ui->btn_OpenSerial->text() == "打开串口")   //初始状态，配置串口参数
    {
        status = false;
        serial.setPortName(ui->cbb_com->currentText());     //设置串口号、
        serial.setBaudRate(ui->cbb_baud->currentText().toInt());    //设置波特率
        serial.setDataBits(QSerialPort::Data8);     //设置串口数据位8
        serial.setParity(QSerialPort::NoParity);    //无校验位
        serial.setStopBits(QSerialPort::OneStop);   //1位停止位
        serial.setFlowControl(QSerialPort::NoFlowControl);
        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox::critical(NULL, "提示", "串口打开失败");
            return;
        }
//        qDebug() << "串口打开成功";
        this->ui->btn_OpenSerial->setText("关闭串口");
        this->ui->btn_ScanSerial->setDisabled(true);
    }
    else
    {
        status = true;
        //关闭串口
        serial.close();
        this->ui->btn_OpenSerial->setText("打开串口");
        this->ui->btn_ScanSerial->setEnabled(true);
    }
    ui->hs_Red->setDisabled(status);
    ui->hs_Green->setDisabled(status);
    ui->hs_Blue->setDisabled(status);
    ui->sb_Red->setDisabled(status);
    ui->sb_Green->setDisabled(status);
    ui->sb_Blue->setDisabled(status);

    ui->btn_selColor->setDisabled(status);
    ui->btn_shut->setDisabled(status);

    ui->cbb_baud->setEnabled(status);
    ui->cbb_com->setEnabled(status);
}

void RGB::on_btn_exit_clicked()
{
    serial.write("R0G0B0*");     //把数据通过串口发送出去
    this->close();
}

void RGB::on_btn_selColor_clicked()
{
    QColorDialog color_panel;//调出颜色选择器对话框
    QColor color = color_panel.getRgba();
    int RGB_R = 0, RGB_G = 0, RGB_B = 0;

    RGB_R = color.red();
    RGB_G = color.green();
    RGB_B = color.blue();

    ui->sb_Blue->setValue(RGB_B);
    ui->sb_Green->setValue(RGB_G);
    ui->sb_Red->setValue(RGB_R);

    ui->hs_Blue->setValue(RGB_B);
    ui->hs_Green->setValue(RGB_G);
    ui->hs_Red->setValue(RGB_R);
    SetBkgrdColr();
    UART_Send_RGB_String();
}


//微调框改变
void RGB::on_sb_Red_valueChanged(int arg1)
{
    ui->hs_Red->setValue(arg1);
    SetBkgrdColr();
    UART_Send_RGB_String();
}
//微调框改变
void RGB::on_sb_Green_valueChanged(int arg1)
{
    ui->hs_Green->setValue(arg1);
    SetBkgrdColr();
    UART_Send_RGB_String();
}
//微调框改变
void RGB::on_sb_Blue_valueChanged(int arg1)
{
    ui->hs_Blue->setValue(arg1);
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_hs_Red_sliderReleased()
{
//    qDebug() << "释放";
    ui->sb_Red->setValue(ui->hs_Red->value());
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_hs_Green_sliderReleased()
{
    ui->sb_Green->setValue(ui->hs_Green->value());
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_hs_Blue_sliderReleased()
{
    ui->sb_Blue->setValue(ui->hs_Blue->value());
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::SetBkgrdColr()
{
    QString RGB_String;
    RGB_String.sprintf("background-color: rgb(%d, %d, %d);", ui->hs_Red->value(), ui->hs_Green->value(),ui->hs_Blue->value());
    ui->tb_rx_buf->setStyleSheet(RGB_String);
}

void RGB::UART_Send_RGB_String()
{
    QString UART_String;
    UART_String.sprintf("R%dG%dB%d*", ui->hs_Red->value(), ui->hs_Green->value(),ui->hs_Blue->value());
    QByteArray tx_buf = UART_String.toLocal8Bit();   //转换为标准字符，支持中文
    serial.write(tx_buf);     //把数据通过串口发送出去
    tx_buf.clear();
}

void RGB::on_hs_Red_valueChanged(int value)
{
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_hs_Green_valueChanged(int value)
{
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_hs_Blue_valueChanged(int value)
{
    SetBkgrdColr();
    UART_Send_RGB_String();
}

void RGB::on_btn_shut_clicked()
{
    if(ui->btn_shut->text() == "熄灭")
    {
        serial.write("R0G0B0*");     //把数据通过串口发送出去
        ui->btn_shut->setText("点亮");

        ui->sb_Blue->setValue(0);
        ui->sb_Red->setValue(0);
        ui->sb_Green->setValue(0);

        ui->hs_Green->setValue(0);
        ui->hs_Red->setValue(0);
        ui->hs_Blue->setValue(0);
    }
    else
    {
        serial.write("R255G255B255*");
        ui->btn_shut->setText("熄灭");

        ui->sb_Blue->setValue(255);
        ui->sb_Red->setValue(255);
        ui->sb_Green->setValue(255);

        ui->hs_Blue->setValue(255);
        ui->hs_Red->setValue(255);
        ui->hs_Green->setValue(255);
    }

}

void RGB::on_btn_about_clicked()
{
    this->ab.setWindowTitle("关于");
    this->ab.exec();
}

void RGB::on_btn_ScanSerial_clicked()
{
    ui->cbb_com->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbb_com->addItem(info.portName());  //串口号下拉菜单，增加一个条目，为串口号COM4
//        qDebug() << "串口搜索完成";
    }
}
