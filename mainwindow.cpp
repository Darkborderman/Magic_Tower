#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    for(int i=0;i<=1;i++)s[i]=new QGraphicsScene(0,0,1200,200);
    ui->setupUi(this);
    ui->graphicsView->setScene(s[1]);
    bg->setbattle(s[0]);
    bg->setstart(s[1]);
    bg->setfloor(1);
    bg->setstat(hero);
    hero->x=14;
    hero->y=7;
    bg->map[0][hero->x][hero->y]=hero;
    hero->loop();
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Q)
    {
        ui->graphicsView->setScene(s[1]);
    }
    //control
    if(e->key()==Qt::Key_W&&detectwall((hero->x)-1,hero->y))
    {
        bg->map[cur_level][hero->x][hero->y]=bg->ep;
        hero->x-=1;
        hero->kind=1;
    }
    if(e->key()==Qt::Key_A&&detectwall(hero->x,(hero->y)-1))
    {
        bg->map[cur_level][hero->x][hero->y]=bg->ep;
        hero->y-=1;
        hero->kind=2;
    }
    if(e->key()==Qt::Key_S&&detectwall((hero->x)+1,hero->y))
    {
        bg->map[cur_level][hero->x][hero->y]=bg->ep;
        hero->x+=1;
        hero->kind=3;
    }
    if(e->key()==Qt::Key_D&&detectwall(hero->x,(hero->y)+1))
    {
        bg->map[cur_level][hero->x][hero->y]=bg->ep;
        hero->y+=1;
        hero->kind=4;
    }
    bg->map[cur_level][hero->x][hero->y]=hero;
    hero->loop();
    bg->setstat(hero);
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int x=e->x(),y=e->y();
    if((x>=300&&x<=640)&&(y>=380&&y<=430)&&(ui->graphicsView->scene()==s[1])) ui->graphicsView->setScene(s[0]);
    if(e->button()==Qt::RightButton)  //for debug
    {
        cerr<<(y-22)/48<<"   "<<(x-200)/48<<endl;
    }
}
int MainWindow::detectwall(int x,int y)  //use return int to judge upfloor downfloor or others
{
    if(bg->level[cur_level][x][y]=='.'||bg->level[cur_level][x][y]=='u'||bg->level[cur_level][x][y]=='d')
    {
        detectmap(x,y);
        return 1;
    }
    else return 0;
}
void MainWindow::detectmap(int x, int y)
{
    if(bg->map[cur_level][x][y]->type=='p')
    {
        if(bg->map[cur_level][x][y]->kind==1) hero->hp+=200;
        if(bg->map[cur_level][x][y]->kind==2) hero->hp+=500;
    }
}
