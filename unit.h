#ifndef UNIT_H
#define UNIT_H

#include<QGraphicsPixmapItem>

class unit : public QGraphicsPixmapItem
{
public:
    unit();
    char type;
    int kind;
    int hp,atk,def,gold,exp;
    unit(char type, int kind,int hp,int atk,int def,int gold,int exp);
private:

};

#endif // UNIT_H


/*
 *k = key d=door p=potion
 *m=monster g=gem
 * i=item h=hero
 * e=empty
 *
 *
 *

*/
