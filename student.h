#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include<QString>
using namespace std;
class Student
{
private:
QString Name;
QString Password;
QString ID;
int Balance;
public:
    Student(QString,QString,QString,int);
    Student();
    QString *Purchased_Book;
    QString getName();
    QString getPassword();
    QString getID();
    int getBalance();
    void rechargeBalance(int);
    void addBook(QString);
    void withdraw(int);
    ~Student();
   // bool isFull();
};

#endif // STUDENT_H
