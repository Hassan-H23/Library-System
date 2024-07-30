#include "mainwindow.h"
#include "bookreservation.h"
#include "qdatetime.h"
#include "ui_mainwindow.h"
#include<iostream>


using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}


void MainWindow::delay(int n){
    QTime dieTime= QTime::currentTime().addSecs(n);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete S_Array[2];
}


Student* MainWindow::login(QString name, QString pass){
for (auto x: S_Array){
    if(x->getName() == name){
        if(x->getPassword() == pass){
            ui->Alert->setStyleSheet("color:green");
            ui->Alert->setText("Welcome, " + x->getName());
            ui->IDHeading->setText("ID : " + x->getID());
            ui->BalanceHeading->setText("Balance : " + QString::number(x->getBalance()));
            return x;
        }
        else{
            ui->Alert->setStyleSheet("color:red");
            ui->Alert->setText("Name is correct but password is not!");
            ui->IDHeading->setText("ID : ");
            ui->BalanceHeading->setText("Balance : ");
            delay(2);
            ui->Alert->setText("");
            return nullptr;
        }
}
    else{continue;}

}
ui->Alert->setStyleSheet("color:red");
ui->Alert->setText("Name does not Exist!");
ui->IDHeading->setText("ID : ");
ui->BalanceHeading->setText("Balance : ");
delay(2);
ui->Alert->setText("");
return nullptr;
}
void MainWindow::on_signup_clicked()
{
Student* s = login(ui->NameLine->text(), ui->PasswordLine->text());
    if(s!=nullptr){
   BR = new BookReservation(this, s);
   BR->show();
}
}

