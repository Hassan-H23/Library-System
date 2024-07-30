#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "bookreservation.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
Student* login(QString name, QString password);



//Student "DataBase"
Student *S_Array[2] = {new Student("Hassan", "123", "900226023", 1000), new Student("Ahmed", "1234", "900221567", 500)};
  void delay(int);
private slots:
  void on_signup_clicked();

private:
    Ui::MainWindow *ui;
    BookReservation *BR;







};
#endif // MAINWINDOW_H
