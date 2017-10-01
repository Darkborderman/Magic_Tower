#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include"background.h"
#include<QKeyEvent>
#include<QMouseEvent>
#include<iostream>
#include<QTimer>
#include"unit.h"
#include"player.h"
using namespace std;
namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e); // for debug
    background *bg=new background;
    QGraphicsScene *s[3];
    player *hero=new player;
    int cur_level=0;
    int prev_level=0;
    int detectwall(int x,int y);
    void detectmap(int x, int y);
    void battle(player *attacker, unit *attacked);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
