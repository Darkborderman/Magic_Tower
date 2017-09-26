#include "background.h"

background::background(QGraphicsScene *s)
{
    char floor[10][10]=
    {
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','0','1','0','0','0','0','0','0','0'},
    {'0','0','1','0','0','0','0','0','0','0'},
    {'0','1','1','0','0','0','0','0','0','0'},
    {'1','1','0','0','0','0','0','0','0','0'},
    {'1','0','0','0','0','0','0','0','0','0'}
    };

    //What a HUGE map
    QGraphicsPixmapItem *floor_disp[10][10];
    for(int i=0;i<=9;i++)
    { for(int j=0;j<=9;j++)
            floor_disp[i][j]=new QGraphicsPixmapItem;
    }

    //
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            floor_disp[i][j]->setPos(48*j,48*i-50);
            switch (floor[i][j])
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
            s->addItem(floor_disp[i][j]);
        }
    }
}
