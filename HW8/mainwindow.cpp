#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math/math.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this, SLOT(digitsNumbers()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this, SLOT(clearLabel()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this, SLOT(equal()));
    connect(ui->pushButton_15,SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_16,SIGNAL(clicked()),this, SLOT(operations()));

    ui->pushButton_12->setCheckable(true);
    ui->pushButton_13->setCheckable(true);
    ui->pushButton_15->setCheckable(true);
    ui->pushButton_16->setCheckable(true);
}
double firstNum;
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digitsNumbers(){
    QPushButton *button = (QPushButton *)sender();
    QString labelResult;
    double numbersInQueue;
    numbersInQueue = (ui->label->text() + button->text()).toDouble();
    labelResult = QString::number(numbersInQueue, 'g', 15);

    ui->label->setText(labelResult);
}
void MainWindow::clearLabel(){
    ui->pushButton_12 ->setChecked(false);
    ui->pushButton_13 ->setChecked(false);
    ui->pushButton_15 ->setChecked(false);
    ui->pushButton_16 ->setChecked(false);
   ui->label->setText("");
}
void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    firstNum = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}
void MainWindow::equal(){
    double labelNumber, secondNum;
    QString labelResult;

    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_12 ->isChecked()){
        labelNumber = add(firstNum, secondNum);
        labelResult = "Result: " + QString::number(labelNumber, 'g', 15);
        ui->label->setText(labelResult);
        ui->pushButton_12 ->setChecked(false);
    }else if(ui->pushButton_13 ->isChecked()){
        labelNumber = sub(firstNum, secondNum);
        labelResult = "Result: " + QString::number(labelNumber, 'g', 15);
        ui->label->setText(labelResult);
        ui->pushButton_13 ->setChecked(false);

    }else if(ui->pushButton_15 ->isChecked()){
        labelNumber = mul(firstNum, secondNum);
        labelResult = "Result: " + QString::number(labelNumber, 'g', 15);
        ui->label->setText(labelResult);
        ui->pushButton_15 ->setChecked(false);


    }else if(ui->pushButton_16 ->isChecked()){
        if(secondNum == 0){
            ui->label->setText("Error");
        }else{
            labelNumber = mydiv(firstNum, secondNum);
            labelResult = "Result: " + QString::number(labelNumber, 'g', 15);
            ui->label->setText(labelResult);
        }

        ui->pushButton_16 ->setChecked(false);
    }
}