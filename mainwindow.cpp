#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *s=new QGraphicsScene(0,0,1200,200);
    ui->graphicsView->setScene(s);
    background b(s);

}

MainWindow::~MainWindow()
{
    delete ui;
}
