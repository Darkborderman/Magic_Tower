#include "background.h"
void background::setbattle_msg(unit *hero,unit *attacked)
{

}
void background::updateframe()
{
    for(int i=0;i<=15;i++)for(int j=0;j<=15;j++) map_disp[i][j]->setPixmap(map[cur_level][i][j]->pixmap().scaled(48,48));
}

void background::setstart(QGraphicsScene *s)
{
    s->addItem(base[0]);
    s->addItem(title);
    for(int i=0;i<=1;i++) s->addItem(subtitle[i]);
    title->setHtml(QString("<div style='color:#FFFFFF'>Magic Tower</div>"));
    subtitle[0]->setHtml(QString("<div style='color:#FFFFFF'>Start Game</div>"));
    subtitle[1]->setHtml(QString("<div style='color:#FFFFFF'>Story</div>"));
}
void background::setstat(player *p)
{
    stat[0]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->level)+QString("</div>"));
    stat[1]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->hp)+QString("</div>"));
    stat[2]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->atk)+QString("</div>"));
    stat[3]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->def)+QString("</div>"));
    stat[4]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->gold)+QString("</div>"));
    stat[5]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->exp)+QString("</div>"));
    stat[6]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->yellowkey)+QString("</div>"));
    stat[7]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->bluekey)+QString("</div>"));
    stat[8]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(p->redkey)+QString("</div>"));
}
void background::setmessage(unit *u)
{
    if(u->type=='k')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'>You got a key</div>"));
    if(u->type=='g')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'>You got a gem</div>"));
    if(u->type=='p')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'>You got a potion</div>"));
    if(u->type=='d')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'>You opened a door</div>"));
    if(u->type=='m')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'>You got "+QString::number(u->gold)+"  gold, "+QString::number(u->exp)+"  exp"+"</div>"));
    if(u->type=='e')
        stat[10]->setHtml(QString("<div style='color:#DDDDDD'> </div>"));
}

void background::setbattle(QGraphicsScene *s)
{
    s->addItem(base[1]);
    for(int i=0;i<=3;i++) s->addItem(panel[i]);
    for(int i=0;i<=10;i++) s->addItem(stat[i]);
    for(int i=0;i<=15;i++){ for(int j=0;j<=15;j++)s->addItem(floor_disp[i][j]);}
    for(int i=0;i<=15;i++){ for(int j=0;j<=15;j++)s->addItem(map_disp[i][j]);}
}
void background::setfloor(int floor)
{
    cur_level=floor;
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<=15;j++)
        {
            if(level[floor][i][j]=='X') floor_disp[i][j]->setPixmap(QPixmap(":/res/map/wall1.png").scaled(48,48));
            if(level[floor][i][j]=='.') floor_disp[i][j]->setPixmap(QPixmap(":/res/map/path.png").scaled(48,48));
            if(level[floor][i][j]=='u') floor_disp[i][j]->setPixmap(QPixmap(":/res/map/upstair.png").scaled(48,48));
            if(level[floor][i][j]=='d') floor_disp[i][j]->setPixmap(QPixmap(":/res/map/downstair.png").scaled(48,48));
        }
    }
    stat[9]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(floor+1)+QString("</div>"));
}
void background::connection()
{
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<=15;j++)
        {
            disconnect(t,SIGNAL(timeout()),map[prev_level][i][j],SLOT(loop()));
            disconnect(t,SIGNAL(timeout()),map[prev_level][i][j],SLOT(loop()));
        }
    }
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<=15;j++)
        {
            connect(t,SIGNAL(timeout()),map[cur_level][i][j],SLOT(loop()));
        }
    }
    cerr<<prev_level;
    cerr<<cur_level;
}

background::background()
{
    //init timer
    t=new QTimer;
    t->start(100);
    //init level display
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<=15;j++)
        {
            floor_disp[i][j]=new QGraphicsPixmapItem;
            map_disp[i][j]=new unit;
            floor_disp[i][j]->setPos(48*j+200,48*i-390);
            map_disp[i][j]->setPos(48*j+200,48*i-390);
        }
    }

    //connect update frame
    connect(t,SIGNAL(timeout()),this,SLOT(updateframe()));
    connection();

    for(int i=0;i<=2;i++)
    {
        base[i]=new QGraphicsPixmapItem;
        base[i]->setPixmap(QPixmap(":/res/menu/background.png").scaled(1200,1000));
        base[i]->setPos(0,-500);
    }
    //init title screen
    title=new QGraphicsTextItem;
    title->setPos(190,-250);
    title->setFont(QFont("Arial",80,10));
    for(int i=0;i<=1;i++)
    {
        subtitle[i]=new QGraphicsTextItem;
        subtitle[i]->setFont(QFont("Arial",50,10));
    }
    subtitle[0]->setPos(290,-50);
    subtitle[1]->setPos(380,70);
    //init death screen
    death=new QGraphicsTextItem;
    death->setFont(QFont("Arial",80,10));
    death->setPos(220,-50);
    //init panel display
    for(int i=0;i<=3;i++) panel[i]=new QGraphicsPixmapItem;
    for(int i=0;i<=10;i++)
    {
        stat[i]=new QGraphicsTextItem;
        if(i==0)
        {
            stat[i]->setFont(QFont("Arial",30,10));
            stat[i]->setPos(80,-370);
        }
        else if(i>=1&&i<=5)
        {
            stat[i]->setFont(QFont("Arial",20,10));
            stat[i]->setPos(80,-340+34*i);
        }
        else if(i==9)
        {
             stat[i]->setFont(QFont("Arial",18,10));
             stat[i]->setPos(80,-110+40*i+9+60);
        }
        else if(i==10)
        {
            stat[i]->setFont(QFont("Arial",30,10));
            stat[i]->setPos(200,380);
        }
        else
        {
            stat[i]->setFont(QFont("Arial",25,10));
            stat[i]->setPos(80,-200+50*i+5+60);
        }
    }
    panel[0]->setPixmap(QPixmap(":/res/menu/stat.png").scaled(132*1.5,177*1.5));
    panel[1]->setPixmap(QPixmap(":/res/menu/slot.png").scaled(132*1.5,177*1.5-39+60));
    panel[2]->setPixmap(QPixmap(":/res/menu/inv.png").scaled(132*1.5,191*1.5));
    panel[3]->setPixmap(QPixmap(":/res/menu/statusbar.png").scaled(772,60));
    panel[0]->setPos(0,-390);
    panel[1]->setPos(0,-130);
    panel[2]->setPos(0,93+60);
    panel[3]->setPos(132*1.5,378);
}
void background::setdeath(QGraphicsScene *s)
{
    s->addItem(base[2]);
    s->addItem(death);
    death->setHtml(QString("<div style='color:#DDDDDD'>You Died!</div>"));
}
