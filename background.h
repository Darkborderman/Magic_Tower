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
class background
{
public:
    background();
    void setbattle_disp(QGraphicsScene *s);
    void setstart(QGraphicsScene *s);
    void setbattle(QGraphicsScene *s);
    void setfloor(int floor);
    void setstat(player *p);

    QGraphicsPixmapItem *floor_disp[16][16],*map_disp[16][16];
    QGraphicsPixmapItem *bg[2],*panel[3];
    QGraphicsTextItem *stat[10],*title,*subtitle[2];

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
        {'X','X','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','X','X','X','d','X','X','X','X','X','X','X','X','X'},
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

    empty *ep=new empty;
    green_slime *gs=new green_slime;

    //Monster Display
    unit *map[3][16][16]=
    {{
        {ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep,ep},
        {ep,ep,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,ep},
        {ep,ep,gs,ep,ep,gs,gs,gs,gs,gs,gs,ep,gs,ep,gs,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep,gs,ep},
        {ep,ep,gs,ep,ep,gs,gs,gs,gs,gs,gs,gs,gs,ep,gs,ep},
        {ep,ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep,ep,ep},
        {ep,ep,gs,ep,gs,gs,ep,gs,gs,gs,gs,ep,gs,gs,gs,ep},
        {ep,ep,gs,ep,gs,gs,ep,gs,gs,gs,gs,ep,gs,ep,ep,ep},
        {ep,ep,gs,ep,gs,ep,ep,gs,gs,gs,gs,ep,gs,ep,ep,ep},
        {ep,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,ep,gs,ep,ep,ep},
        {ep,gs,ep,ep,ep,ep,ep,ep,ep,ep,gs,ep,gs,ep,ep,ep},
        {ep,gs,gs,gs,gs,gs,ep,ep,gs,gs,gs,gs,gs,gs,ep,ep},
        {ep,gs,gs,gs,gs,gs,ep,ep,gs,ep,ep,ep,ep,gs,gs,ep},
        {ep,gs,gs,gs,gs,ep,ep,gs,gs,gs,ep,gs,gs,gs,gs,ep},
        {ep,gs,gs,gs,gs,ep,ep,gs,gs,gs,ep,gs,gs,gs,gs,ep},
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
};

#endif // BACKGROUND_H
