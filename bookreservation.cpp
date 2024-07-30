#include "bookreservation.h"
#include "ui_bookreservation.h"
#include "book.h"
#include <QTime>
using namespace std;
Student *student;
extern int count;
//delay function
void BookReservation::delay(int n){
    QTime dieTime= QTime::currentTime().addSecs(n);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

BookReservation::BookReservation(QWidget *parent, Student *s) :
    QDialog(parent),
    ui(new Ui::BookReservation)
{

    ui->setupUi(this);
    student = s;
    ui->UserLabel->setText("User : " + student->getName());
    ui->BalanceHeading->setText("Balance : $" + QString::number(student->getBalance()));
    ui->IDHeading->setText("ID : " + student->getID());
    ui->Books->addItem("Select Book");
    for(int i =0; i<5; i++){

     ui->Books->addItem(B_array[i]->getB_Name());

    }
}

BookReservation::~BookReservation()
{
    delete ui;
}



void BookReservation::on_Books_activated(int index)
{

 for(int i =0; i < 6; i++){
     if (i == 0){ui->PriceHeading->setText("Price : "); continue;}
     else if (i == index){
         ui->PriceHeading->setText("Price : $" + QString::number(B_array[i-1]->get_Price()));
     }
 }
}
void BookReservation::on_rechargeButton_clicked()
{
try{
        if(ui->RechargeBalance->text().toInt() > 0){
    student->rechargeBalance(ui->RechargeBalance->text().toInt());
     ui->BalanceHeading->setText("Balance : $"+QString::number(student->getBalance()));
     ui->RechargeBalance->setStyleSheet("color: green");
     ui->RechargeBalance->setReadOnly(true);
     ui->RechargeBalance->setText("Successfully Recharged!");
     delay(2);
     ui->RechargeBalance->setStyleSheet("color: black");
     ui->RechargeBalance->setReadOnly(false);
     ui->RechargeBalance->setText("");
    }
    else if (ui->RechargeBalance->text().toInt() < 0) {
            throw 1;
    }
        else {
            throw 2;
        }

}
    catch(int e){
        switch(e){
        case 1:
            ui->RechargeBalance->setReadOnly(true);
            ui->RechargeBalance->setStyleSheet("color:red");
            ui->RechargeBalance->setText("Can't enter -ve value!");
             delay(3);
              ui->RechargeBalance->setReadOnly(false);
               ui->RechargeBalance->setStyleSheet("color:black");
             ui->RechargeBalance->setText("");
            break;
        case 2:
            ui->RechargeBalance->setReadOnly(true);
             ui->RechargeBalance->setText("Can't enter string value or 0!");
             ui->RechargeBalance->setStyleSheet("color:red");
             delay(3);
             ui->RechargeBalance->setText("");
              ui->RechargeBalance->setStyleSheet("color:black");
             ui->RechargeBalance->setReadOnly(false);
            break;
        }
    }
}

void BookReservation::buyBook(QString book, int price){
    student->addBook(book);
    student->withdraw(price);
}


void BookReservation::on_But_Button_clicked()
{
 Book *a;
 for(int i =0; i<6; i++){

    if(i == ui->Books->currentIndex()){

       a = B_array[i-1];
    }
 }


 if(ui->Books->currentIndex() == 0){
ui->Book_Alert->setStyleSheet("color:red");
ui->Book_Alert->setText("Please Select a Book!");
delay(2);
ui->Book_Alert->setText("");
}

else if(a->get_Price() > student->getBalance()){
    ui->Book_Alert->setStyleSheet("color:red");
    ui->Book_Alert->setText("Insuffienct Funds!");
     ui->PriceHeading->setText("Price : ");
    ui->Books->setCurrentIndex(0);
    delay(2);
    ui->Book_Alert->setText("");
}

else{
    student->addBook(a->getB_Name());
    student->withdraw(a->get_Price());
    ui->BalanceHeading->setText("Balance : $"+QString::number(student->getBalance()));
    ui->Books->setCurrentIndex(0);
    ui->Book_Alert->setStyleSheet("color:green");
    ui->Book_Alert->setText("Succesfully Purchased " + a->getB_Name() + "!");
     ui->PriceHeading->setText("Price : ");
    delay(2);
    ui->Book_Alert->setText("");

}

}


void BookReservation::on_ViewBooks_clicked()
{
    //Test Loop
     /*for(int i=0; i<10; i++)
     {
    qInfo() << i <<" = "<< student->Purchased_Book[i];
}*/
    BP = new BooksPurchased(this, student);
    BP->show();


}

