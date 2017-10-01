#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<QGraphicsPixmapItem>
#include<QGraphicsTextItem>
#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include"player.h"
#include"empty.h"
#include"green_slime.h"
#include"unit.h"
#include"large_potion.h"
#include<QObject>
#include<QTimer>
#include<iostream>
#include"blue_gem.h"
#include"yellow_key.h"
#include"yellow_door.h"
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
    //Monster List
    player *he=new player;
    empty *ep=new empty;
    green_slime *gs=new green_slime;
    large_potion *lp=new large_potion;
    blue_gem *bg=new blue_gem;
    yellow_key *yk=new yellow_key;
    yellow_door *yd=new yellow_door;

    //Monster Display
    unit *map[3][16][16]=
    {{
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,ep},
        {ep,ep,gs,ep,ep,gs,gs,gs,gs,gs,gs,ep,gs,ep,gs,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep,gs,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,gs,ep,gs,gs,ep,gs,gs,gs,gs,ep,ep,gs,gs,ep},
        {ep,ep,gs,ep,gs,gs,ep,gs,gs,gs,gs,ep,ep,ep,ep,ep},
        {ep,ep,gs,ep,gs,ep,ep,gs,gs,gs,gs,ep,ep,ep,ep,ep},
        {ep,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,ep,ep,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep,ep,ep,ep,ep},
        {ep,gs,gs,gs,gs,gs,ep,ep,ep,ep,ep,ep,ep,gs,ep,ep},
        {ep,gs,gs,gs,gs,gs,ep,ep,yd,ep,ep,ep,ep,gs,gs,ep},
        {ep,gs,gs,gs,gs,ep,ep,yk,ep,bg,ep,gs,gs,gs,gs,ep},
        {ep,gs,gs,gs,gs,ep,ep,ep,ep,lp,ep,gs,gs,gs,gs,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
    },
    {
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
    },
    {
         {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
         {gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs},
         {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs},
         {gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs},
         {ep,gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs},
         {gs,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs},
         {gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs}
    }};


public slots:
        void updateframe();
};

#endif // BACKGROUND_H
