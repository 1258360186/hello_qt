#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButton, &QPushButton::clicked, this, qOverload<>(&Dialog::do_font_color));
    QObject::connect(ui->radioButton_2, &QPushButton::clicked, this, qOverload<>(&Dialog::do_font_color));
    QObject::connect(ui->radioButton_3, &QPushButton::clicked, this, qOverload<>(&Dialog::do_font_color));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_checkBox_clicked(bool checked)
{
    QFont font=ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_2_clicked(bool checked)
{
    QFont font=ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_3_clicked(bool checked)
{
    QFont font=ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::do_font_color()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->radioButton->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(ui->radioButton_2->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if(ui->radioButton_3->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    ui->plainTextEdit->setPalette(plet);
}

