#include "bookspurchased.h"
#include "ui_bookspurchased.h"
#include <QMessageBox>
#include <QException>

;
int occurences(Student *s, QString x){
    int count = 0;
    for(int i = 0; i< s->Purchased_Book->size(); i++){

        if(x == s->Purchased_Book[i]){

            count++;
        }
    }

    return count;
}
BooksPurchased::BooksPurchased(QWidget *parent, Student *s) :
    QDialog(parent),
    ui(new Ui::BooksPurchased)
{
ui->setupUi(this);
bool visited[10];
for(int i=0; i<10; i++){
    visited[i] = false;
}

//std::copy(s->Purchased_Book, s->Purchased_Book+10, arr);
this->setFixedSize(this->width(), this->height());
setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
ui->log->clear();

    if(s->Purchased_Book->isEmpty()){
ui->log->appendPlainText("No Books Purchased Yet.");
}
    else{

        for (int i = 0; i < 10; i++) {

               if (visited[i] == true)
                   continue;
               int count = 1;
               for (int j = i + 1; j < 10; j++) {

                   if (s->Purchased_Book[i] == s->Purchased_Book[j]) {
                       visited[j] = true;
                       count++;
                   }

               }
               if(s->Purchased_Book[i] != nullptr){
              ui->log->appendPlainText(s->Purchased_Book[i] + " x" + QString::number(count));
               }
           }
}
}

BooksPurchased::~BooksPurchased()
{
    delete ui;


}
