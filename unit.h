#ifndef UNIT_H
#define UNIT_H

#include<QGraphicsPixmapItem>

class unit
{
public:
    unit();
    char type;
    int hp,atk,def,gold,exp,type;
    unit(int hp,int atk,int def,int gold,int exp);
    QGraphicsPixmapItem *icon;

};

#endif // UNIT_H
