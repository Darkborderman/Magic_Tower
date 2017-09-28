#include "background.h"
void background::setbattle_disp(QGraphicsScene *s)
{

}

void background::setstart(QGraphicsScene *s)  //just set the start screen may put at start theme
{
    QGraphicsPixmapItem *titlebg=new QGraphicsPixmapItem;
    titlebg->setPixmap(QPixmap(":/res/menu/background.png").scaled(1200,1000));
    titlebg->setPos(0,-500);
    s->addItem(titlebg);
    QGraphicsTextItem *title=new QGraphicsTextItem;
    title->setFont(QFont("Arial",80,10));
    title->setHtml(QString("<div style='color:#FFFFFF'>Magic Tower</div>"));
    s->addItem(title);
    title->setPos(200,-200);
    QGraphicsTextItem *subtitle[2];
    for(int i=0;i<=1;i++)
    {
        subtitle[i]=new QGraphicsTextItem;
        subtitle[i]->setFont(QFont("Arial",20,10));
        s->addItem(subtitle[i]);
        subtitle[i]->setPos(0,0+100*i);
    }
    subtitle[0]->setHtml(QString("<div style='color:#FFFFFF'>Start Game</div>"));
    subtitle[1]->setHtml(QString("<div style='color:#FFFFFF'>Story</div>"));
}
void background::setstat(QGraphicsScene *s)  //may pass a type call unit, has key, stat, and these stats
{
    QGraphicsTextItem *stat[10];
    for(int i=0;i<=9;i++)
    {
        stat[i]=new QGraphicsTextItem;
        stat[i]->setFont(QFont("Arial",20,10));
        s->addItem(stat[i]);
        if(i>=0&&i<=5)stat[i]->setPos(0,-350+40*i);
        else stat[i]->setPos(0,-150+40*i);
        stat[i]->setHtml(QString("<div style='color:#DDDDDD'>")+QString::number(19)+QString("</div>"));
    }


}
void background::setbattle(QGraphicsScene *s)
{
    QGraphicsPixmapItem *menu=new QGraphicsPixmapItem,*inv=new QGraphicsPixmapItem;
    menu->setPixmap(QPixmap(":/res/menu/stat.png").scaled(132*1.5,177*1.5));
    inv->setPixmap(QPixmap(":/res/menu/inv.png").scaled(132*1.5,191*1.5));
    menu->setPos(0,-390);
    inv->setPos(0,90);
    s->addItem(menu);
    s->addItem(inv);
    for(int i=0;i<=15;i++){ for(int j=0;j<=15;j++)s->addItem(floor_disp[i][j]);}
}
void background::setlevel(QGraphicsScene *s,int level)
{
    int  a=level-1;
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<=15;j++)
        {
            floor_disp[i][j]->setPos(48*j+200,48*i-390);
            switch (floor[a][i][j])
            {
                case '0':
                {
                    floor_disp[i][j]->setPixmap(QPixmap(":/res/map/wall1.png").scaled(48,48));
                    break;
                }
                case '1':
                {
                    floor_disp[i][j]->setPixmap(QPixmap(":/res/map/path.png").scaled(48,48));
                    break;
                }
            }
        }
    }
}
background::background()
{
    for(int i=0;i<=15;i++) { for(int j=0;j<=15;j++) floor_disp[i][j]=new QGraphicsPixmapItem;}
}
