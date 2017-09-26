#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include"background.h"
#include<QKeyEvent>
#include<QMouseEvent>
#include<iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent *e); // for debug
    background *bg=new background;
    QGraphicsScene *s=new QGraphicsScene(0,0,1200,200);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
