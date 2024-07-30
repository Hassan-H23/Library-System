#include "book.h"

Book::Book(QString B_Name, int Price)
{
this->B_Name = B_Name;
this->Price = Price;
}
int Book::get_Price(){return Price;}
QString Book::getB_Name(){return B_Name;}
