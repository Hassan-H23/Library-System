#ifndef BOOKRESERVATION_H
#define BOOKRESERVATION_H
#include "student.h"
#include <QDialog>
#include "book.h"
#include "bookspurchased.h"
namespace Ui {
class BookReservation;
}

class BookReservation : public QDialog
{
    Q_OBJECT

public:
    explicit BookReservation(QWidget *parent = nullptr, Student *s = nullptr);
    ~BookReservation();
    Book *B_array[5] = {new Book("Data Structure", 100), new Book("Calculus", 120), new Book("Human Spirit", 90), new Book("Physics", 200), new Book("Data Mining", 250)};



private slots:
    void on_Books_activated(int index);
    void on_rechargeButton_clicked();
    void delay(int n);
    void buyBook(QString book, int price);
    void on_But_Button_clicked();

    void on_ViewBooks_clicked();

private:
    Ui::BookReservation *ui;
    BooksPurchased *BP;

};

#endif // BOOKRESERVATION_H
