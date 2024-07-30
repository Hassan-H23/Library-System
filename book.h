#ifndef BOOK_H
#define BOOK_H
#include<string>
#include <QString>
using namespace std;
class Book
{

private:

    QString B_Name;
    int Price;

public:
    Book(QString, int);
    QString getB_Name();
    int get_Price();

};

#endif // BOOK_H
