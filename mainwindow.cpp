#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(s);
    bg->setbattle(s);
    bg->setstart(s);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//For debug
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_1)
    {
        cerr<<"Switch to floor 1";
        bg->setlevel(s,1);
    }
    if(e->key()==Qt::Key_2)
    {
        cerr<<"Switch to floor 2";
        bg->setlevel(s,2);
    }
    if(e->key()==Qt::Key_3)
    {
        cerr<<"Switch to floor 3";
        bg->setlevel(s,3);
    }
}
