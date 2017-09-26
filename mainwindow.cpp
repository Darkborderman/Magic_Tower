#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *s=new QGraphicsScene(0,0,1200,200);
    ui->graphicsView->setScene(s);
    QGraphicsPixmapItem *p=new QGraphicsPixmapItem;
    p->setPixmap(QPixmap(":/res/map/128.png").scaled(48,48));
    p->setPos(0,0);
    s->addItem(p);
    background b(s);

}

MainWindow::~MainWindow()
{
    delete ui;
}
