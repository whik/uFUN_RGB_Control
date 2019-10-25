/********************************************************************************
** Form generated from reading UI file 'rgb.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_H
#define UI_RGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RGB
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *sb_Blue;
    QSlider *hs_Red;
    QSlider *hs_Blue;
    QLabel *label;
    QSpinBox *sb_Green;
    QLabel *label_3;
    QSlider *hs_Green;
    QSpinBox *sb_Red;
    QTextBrowser *tb_rx_buf;
    QVBoxLayout *verticalLayout;
    QComboBox *cbb_baud;
    QComboBox *cbb_com;
    QPushButton *btn_OpenSerial;
    QPushButton *btn_ScanSerial;
    QPushButton *btn_selColor;
    QPushButton *btn_shut;
    QPushButton *btn_exit;
    QPushButton *btn_about;
    QPushButton *btn_chkUpdate;

    void setupUi(QDialog *RGB)
    {
        if (RGB->objectName().isEmpty())
            RGB->setObjectName(QStringLiteral("RGB"));
        RGB->resize(643, 382);
        horizontalLayout = new QHBoxLayout(RGB);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(RGB);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("image: url(:/QRCode/green.png);"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        sb_Blue = new QSpinBox(RGB);
        sb_Blue->setObjectName(QStringLiteral("sb_Blue"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sb_Blue->sizePolicy().hasHeightForWidth());
        sb_Blue->setSizePolicy(sizePolicy);
        sb_Blue->setFont(font);

        gridLayout->addWidget(sb_Blue, 2, 2, 1, 1);

        hs_Red = new QSlider(RGB);
        hs_Red->setObjectName(QStringLiteral("hs_Red"));
        hs_Red->setFont(font);
        hs_Red->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_Red, 0, 1, 1, 1);

        hs_Blue = new QSlider(RGB);
        hs_Blue->setObjectName(QStringLiteral("hs_Blue"));
        hs_Blue->setFont(font);
        hs_Blue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_Blue, 2, 1, 1, 1);

        label = new QLabel(RGB);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(48, 48));
        label->setMaximumSize(QSize(48, 48));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("image: url(:/QRCode/red.png);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        sb_Green = new QSpinBox(RGB);
        sb_Green->setObjectName(QStringLiteral("sb_Green"));
        sizePolicy.setHeightForWidth(sb_Green->sizePolicy().hasHeightForWidth());
        sb_Green->setSizePolicy(sizePolicy);
        sb_Green->setFont(font);

        gridLayout->addWidget(sb_Green, 1, 2, 1, 1);

        label_3 = new QLabel(RGB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("image: url(:/QRCode/blue.png);"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        hs_Green = new QSlider(RGB);
        hs_Green->setObjectName(QStringLiteral("hs_Green"));
        hs_Green->setFont(font);
        hs_Green->setStyleSheet(QStringLiteral("selection-color: rgb(81, 255, 0);"));
        hs_Green->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_Green, 1, 1, 1, 1);

        sb_Red = new QSpinBox(RGB);
        sb_Red->setObjectName(QStringLiteral("sb_Red"));
        sizePolicy.setHeightForWidth(sb_Red->sizePolicy().hasHeightForWidth());
        sb_Red->setSizePolicy(sizePolicy);
        sb_Red->setFont(font);

        gridLayout->addWidget(sb_Red, 0, 2, 1, 1);

        tb_rx_buf = new QTextBrowser(RGB);
        tb_rx_buf->setObjectName(QStringLiteral("tb_rx_buf"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(11);
        tb_rx_buf->setFont(font1);
        tb_rx_buf->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tb_rx_buf, 3, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cbb_baud = new QComboBox(RGB);
        cbb_baud->setObjectName(QStringLiteral("cbb_baud"));
        cbb_baud->setFont(font);

        verticalLayout->addWidget(cbb_baud);

        cbb_com = new QComboBox(RGB);
        cbb_com->setObjectName(QStringLiteral("cbb_com"));
        cbb_com->setFont(font);

        verticalLayout->addWidget(cbb_com);

        btn_OpenSerial = new QPushButton(RGB);
        btn_OpenSerial->setObjectName(QStringLiteral("btn_OpenSerial"));
        btn_OpenSerial->setFont(font);

        verticalLayout->addWidget(btn_OpenSerial);

        btn_ScanSerial = new QPushButton(RGB);
        btn_ScanSerial->setObjectName(QStringLiteral("btn_ScanSerial"));
        btn_ScanSerial->setFont(font);

        verticalLayout->addWidget(btn_ScanSerial);

        btn_selColor = new QPushButton(RGB);
        btn_selColor->setObjectName(QStringLiteral("btn_selColor"));
        btn_selColor->setFont(font);

        verticalLayout->addWidget(btn_selColor);

        btn_shut = new QPushButton(RGB);
        btn_shut->setObjectName(QStringLiteral("btn_shut"));
        btn_shut->setFont(font);

        verticalLayout->addWidget(btn_shut);

        btn_exit = new QPushButton(RGB);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setFont(font);

        verticalLayout->addWidget(btn_exit);

        btn_about = new QPushButton(RGB);
        btn_about->setObjectName(QStringLiteral("btn_about"));
        btn_about->setFont(font);

        verticalLayout->addWidget(btn_about);

        btn_chkUpdate = new QPushButton(RGB);
        btn_chkUpdate->setObjectName(QStringLiteral("btn_chkUpdate"));
        btn_chkUpdate->setFont(font);

        verticalLayout->addWidget(btn_chkUpdate);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(RGB);

        QMetaObject::connectSlotsByName(RGB);
    } // setupUi

    void retranslateUi(QDialog *RGB)
    {
        RGB->setWindowTitle(QApplication::translate("RGB", "RGB", Q_NULLPTR));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
        btn_OpenSerial->setText(QApplication::translate("RGB", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        btn_ScanSerial->setText(QApplication::translate("RGB", "\346\211\253\346\217\217\344\270\262\345\217\243", Q_NULLPTR));
        btn_selColor->setText(QApplication::translate("RGB", "\351\200\211\346\213\251\351\242\234\350\211\262", Q_NULLPTR));
        btn_shut->setText(QApplication::translate("RGB", "\347\206\204\347\201\255", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("RGB", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_about->setText(QApplication::translate("RGB", "\345\205\263\344\272\216", Q_NULLPTR));
        btn_chkUpdate->setText(QApplication::translate("RGB", "\346\243\200\346\237\245\346\233\264\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RGB: public Ui_RGB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_H
