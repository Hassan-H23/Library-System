#ifndef BOOKSPURCHASED_H
#define BOOKSPURCHASED_H

#include <QDialog>
#include "student.h"
namespace Ui {
class BooksPurchased;
}

class BooksPurchased : public QDialog
{
    Q_OBJECT

public:
    explicit BooksPurchased(QWidget *parent = nullptr, Student* s = nullptr);
    ~BooksPurchased();

private:
    Ui::BooksPurchased *ui;
};


#endif // BOOKSPURCHASED_H
