#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<QGraphicsPixmapItem>
#include<QGraphicsTextItem>
#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include<QObject>
#include<QTimer>
#include<iostream>
#include"player.h"
#include"empty.h"
#include"unit.h"

//Potion and Gem
#include"potion_blue.h"
#include"potion_red.h"
#include"gem_blue.h"
#include"gem_red.h"

//Key and Door
#include"key_blue.h"
#include"key_red.h"
#include"key_godly.h"
#include"key_yellow.h"
#include"door_yellow.h"
#include"door_godly.h"
#include"door_blue.h"
#include"door_red.h"

//Monster
#include"slime_blue.h"
#include"slime_green.h"
#include"slime_red.h"




using namespace std;

class background: public QObject
{
    Q_OBJECT
public:
    background();
    void setbattle_msg(unit *hero, unit *attacked);
    void setstart(QGraphicsScene *s);
    void setbattle(QGraphicsScene *s);
    void setfloor(int floor);
    void setstat(player *p);
    void connection();
    void setmessage(unit *u);
    void setdeath(QGraphicsScene *s);

    int cur_level=0;
    int prev_level=0;
    QTimer *t;
    QGraphicsPixmapItem *floor_disp[16][16];
    unit *map_disp[16][16];
    QGraphicsPixmapItem *base[3],*panel[4];
    QGraphicsTextItem *stat[11],*title,*subtitle[2],*death;

    //Wall display
    char level[3][16][16]=
    {{
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','.','.','.','.','.','.','.','.','.','.','.','.','X'},
        {'X','X','.','X','X','.','.','.','.','.','.','X','.','X','.','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','.','X','.','X'},
        {'X','X','.','X','u','.','.','.','.','.','.','.','.','X','.','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','.','X','X','X'},
        {'X','X','.','X','.','.','X','.','.','.','.','X','.','.','.','X'},
        {'X','X','.','X','.','.','X','.','.','.','.','X','.','X','X','X'},
        {'X','X','.','X','.','X','X','.','.','.','.','X','.','X','X','X'},
        {'X','.','.','.','.','.','.','.','.','.','.','X','.','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','.','X','.','X','X','X'},
        {'X','.','.','.','.','.','u','X','.','.','.','.','.','.','X','X'},
        {'X','.','.','.','.','.','X','X','.','X','X','X','X','.','.','X'},
        {'X','.','.','.','.','X','X','.','.','.','X','.','.','.','.','X'},
        {'X','.','.','.','.','X','X','.','.','.','X','.','.','.','.','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
    },
    {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','d','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','.','.','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','.','.','.','d','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
    },
    {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'.','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'.','.','X','X','X','X','X','X','X','X','X','X','X','X','X','.'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','.'},
        {'.','.','X','X','X','X','X','X','X','X','X','X','X','X','X','.'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','.'},
        {'.','.','X','X','X','X','X','X','X','X','X','X','X','X','X','.'},
        {'.','X','X','X','X','X','X','X','X','X','X','X','X','X','X','.'}
    }};
    //Item list
    player *he=new player;
    empty *empt=new empty;

    potion_blue *po_b=new potion_blue;
    potion_red *po_r=new potion_red;
    gem_blue *ge_b=new gem_blue;
    gem_red *ge_r=new gem_red;

    key_blue *ke_b=new key_blue;
    key_red *ke_r=new key_red;
    key_yellow *ke_y=new key_yellow;
    key_godly *ke_g=new key_godly;
    door_blue *do_b=new door_blue;
    door_godly *do_g=new door_godly;
    door_red *do_r=new door_red;
    door_yellow *do_y=new door_yellow;

    slime_blue *sl_b=new slime_blue;
    slime_green *sl_g=new slime_green;

    //Monster Display
    unit *map[3][16][16]=
    {{
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,empt},
        {empt,empt,sl_g,empt,empt,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,empt,sl_g,empt,sl_g,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g,empt,sl_g,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,sl_g,sl_g,empt,sl_g,sl_g,sl_g,sl_g,empt,empt,sl_g,sl_g,empt},
        {empt,empt,sl_g,empt,sl_g,sl_g,empt,sl_g,sl_g,sl_g,sl_g,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,sl_g,empt,empt,sl_g,sl_g,sl_g,sl_g,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,sl_g,empt,empt,empt,empt,empt},
        {empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,sl_g,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,sl_g,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,sl_g,empt,empt},
        {empt,sl_g,sl_g,sl_g,sl_g,sl_g,empt,empt,do_g,empt,empt,empt,empt,sl_g,sl_g,empt},
        {empt,sl_g,sl_g,sl_g,sl_g,empt,empt,ke_g,empt,ge_r,empt,sl_g,sl_g,sl_g,sl_g,empt},
        {empt,sl_g,sl_g,sl_g,sl_g,empt,empt,empt,empt,po_r,empt,sl_g,sl_g,sl_g,sl_g,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
    },
    {
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
    },
    {
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,empt,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt},
        {sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g},
        {sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g},
        {empt,sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g},
        {sl_g,sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g},
        {sl_g,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,empt,sl_g}
    }};


public slots:
        void updateframe();
};

#endif // BACKGROUND_H
