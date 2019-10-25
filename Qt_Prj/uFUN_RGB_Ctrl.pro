#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T19:58:19
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uFUN_RGB_Ctrl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        rgb.cpp \
    about.cpp

HEADERS  += rgb.h \
    about.h

FORMS    += rgb.ui \
    about.ui


# 添加串口支持

QT += serialport
# 添加图标
RC_ICONS = icon.ico

#windeployqt UART_Demo.exe 自动添加程序运行所需的库

RESOURCES += \
    img.qrc
# 网络请求
QT += network
