#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0;i<=1;i++)s[i]=new QGraphicsScene(0,0,1200,200);
    hero= new player;
    ui->setupUi(this);
    ui->graphicsView->setScene(s[1]);
    bg->setbattle(s[0]);
    bg->setstart(s[1]);
    bg->setfloor(1);
    bg->setstat(hero);
    bg->setmap(s[0],1);
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
        bg->setfloor(1);
        bg->setmap(s[0],1);
    }
    if(e->key()==Qt::Key_2)
    {
        cerr<<"Switch to floor 2";
        bg->setfloor(2);
            bg->setmap(s[0],2);
    }
    if(e->key()==Qt::Key_3)
    {
        cerr<<"Switch to floor 3";
        bg->setfloor(3);
            bg->setmap(s[0],3);
    }
    if(e->key()==Qt::Key_Q)
    {
        ui->graphicsView->setScene(s[1]);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int x=e->x(),y=e->y();
    if((x>=300&&x<=640)&&(y>=380&&y<=430)&&(ui->graphicsView->scene()==s[1])) ui->graphicsView->setScene(s[0]);
}
