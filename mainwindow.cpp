#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0;i<=1;i++)s[i]=new QGraphicsScene(0,0,1200,200);
    ui->setupUi(this);
    ui->graphicsView->setScene(s[0]);
    bg->setbattle(s[0]);
    bg->setstart(s[1]);
    bg->setstat(s[0]);
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
        bg->setlevel(s[0],1);
    }
    if(e->key()==Qt::Key_2)
    {
        cerr<<"Switch to floor 2";
        bg->setlevel(s[0],2);
    }
    if(e->key()==Qt::Key_3)
    {
        cerr<<"Switch to floor 3";
        bg->setlevel(s[0],3);
    }
    if(e->key()==Qt::Key_Q)
    {
        cerr<<"Switch to main screen";
        ui->graphicsView->setScene(s[1]);
    }
    if(e->key()==Qt::Key_E)
    {
        cerr<<"Switch to battle screen";
        ui->graphicsView->setScene(s[0]);
    }
}
