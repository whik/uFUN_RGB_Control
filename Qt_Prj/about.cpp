#include "about.h"
#include "ui_about.h"
#include <QDebug>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    this->setWindowTitle("关于");

}

about::~about()
{
    delete ui;
}
