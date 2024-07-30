#include "student.h"

Student::Student(QString Name, QString Password, QString ID, int Balance)
{

this->Name = Name;
this->Password = Password;
this->ID = ID;
this->Balance = Balance;
Purchased_Book = new QString[10];

for (int i =0; i<Purchased_Book->length(); i++){

    Purchased_Book[i] = nullptr;

}
}
QString Student::getName(){ return Name;}
QString Student::getPassword(){ return Password;}
QString Student::getID(){return ID;}
int Student::getBalance(){return Balance;}
void Student::rechargeBalance(int RB){Balance +=RB;}


void Student::addBook(QString Book){


for(int i = 0; i<10; i++){

    if(Purchased_Book[i] == nullptr){
        Purchased_Book[i] = Book;
        return;
    }
    else {
        continue;
    }

}


}
void Student::withdraw(int price){Balance -= price;}
Student::~Student(){

    delete Purchased_Book;
}

/*bool Student::isFull(){

    if(Purchased_Book[10]!= nullptr){
        return true;
    }
    else { return false;}
}
*/
