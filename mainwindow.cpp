#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    for(int i=0;i<=2;i++)s[i]=new QGraphicsScene(0,0,1200,200);
    ui->setupUi(this);
    ui->graphicsView->setScene(s[1]);
    bg->setbattle(s[0]);
    bg->setstart(s[1]);
    bg->setdeath(s[2]);
    bg->setfloor(cur_level);
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
        if(bg->level[cur_level][x][y]=='u')
        {
            bg->map[cur_level][hero->x][hero->y]=bg->ep;
            prev_level=cur_level;
            ++cur_level;
            bg->prev_level=prev_level;
            bg->cur_level=cur_level;
            bg->connection();
            bg->setfloor(cur_level);
        }
        else if(bg->level[cur_level][x][y]=='d')
        {
            bg->map[cur_level][hero->x][hero->y]=bg->ep;
            prev_level=cur_level;
            --cur_level;
            bg->prev_level=prev_level;
            bg->cur_level=cur_level;
            bg->setfloor(cur_level);
            bg->connection();
        }
        if(bg->map[cur_level][x][y]->type=='d')
        {
            if(bg->map[cur_level][x][y]->kind==1&&hero->yellowkey>=1)
            {
                hero->yellowkey--;
                bg->setmessage(bg->map[cur_level][x][y]);
                bg->map[cur_level][x][y]=bg->ep;
                return 0;
            }
            else return 0;
        }
        return 1;
    }
    else return 0;
}
void MainWindow::detectmap(int x, int y)
{

    if(bg->map[cur_level][x][y]->type=='p')
    {
        bg->setmessage(bg->map[cur_level][x][y]);
        if(bg->map[cur_level][x][y]->kind==1) hero->hp+=200;
        if(bg->map[cur_level][x][y]->kind==2) hero->hp+=500;
    }
    if(bg->map[cur_level][x][y]->type=='g')
    {
        bg->setmessage(bg->map[cur_level][x][y]);
        if(bg->map[cur_level][x][y]->kind==1) hero->atk+=3;
        if(bg->map[cur_level][x][y]->kind==2) hero->def+=3;
    }
    if(bg->map[cur_level][x][y]->type=='k')
    {
        bg->setmessage(bg->map[cur_level][x][y]);
        if(bg->map[cur_level][x][y]->kind==1) hero->yellowkey+=1;
        if(bg->map[cur_level][x][y]->kind==2) hero->bluekey+=1;
        if(bg->map[cur_level][x][y]->kind==3) hero->redkey+=1;
    }
    if(bg->map[cur_level][x][y]->type=='m')
    {
        battle(hero,bg->map[cur_level][x][y]);
        bg->setmessage(bg->map[cur_level][x][y]);
        bg->setbattle_msg(hero,bg->map[cur_level][x][y]);
        hero->gold+=bg->map[cur_level][x][y]->gold;
        hero->exp+=bg->map[cur_level][x][y]->exp;
    }
}
void MainWindow::battle(player *attacker, unit *attacked)
{
    unit temp;
    temp.hp=attacked->hp;
    while(attacker->hp>0)
    {
        attacked->hp-=(attacker->atk-attacked->def);
        if (attacked->hp<=0)
        {
            attacked->hp=temp.hp;
            break;
        }
        attacker->hp-=(attacked->atk-attacker->def);
        bg->setstat(attacker);
    }
    if(attacker->hp<=0)
    {
        ui->graphicsView->setScene(s[2]);
    }
    return ;
}
