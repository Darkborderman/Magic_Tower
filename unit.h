#ifndef UNIT_H
#define UNIT_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<iostream>
using namespace std;
class unit : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    unit();
    char type;
    int kind;
    int hp,atk,def,gold,exp;
    unit(char type, int kind,int hp,int atk,int def,int gold,int exp);\
    int tick=2;
public slots:
    virtual void loop();


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
