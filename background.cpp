#include "background.h"

background::background(QGraphicsScene *s)
{
}
void background::setbattle_disp(QGraphicsScene *s)
{

}

void background::setstart(QGraphicsScene *s)
{
    QGraphicsTextItem *t=new QGraphicsTextItem;
    t->setFont(QFont("Arial",20,10));
    t->setHtml(QString("<div style='color:#666666'>")+QString::number(19)+QString("</div>"));
    s->addItem(t);
    t->setPos(0,0);


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
