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
    void setmap(QGraphicsScene *s, int floor);
    void setstat(player *p);
        QGraphicsTextItem *stat[10];

        QGraphicsPixmapItem *floor_disp[16][16];
        QGraphicsPixmapItem *map_disp[16][16];
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

        unit *map[3][16][16]=
        {{
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new empty,new green_slime,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime,new empty,new green_slime,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime,new empty,new empty,new empty},
            {new empty,new empty,new green_slime,new empty,new green_slime,new green_slime,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new green_slime,new green_slime,new empty},
            {new empty,new empty,new green_slime,new empty,new green_slime,new green_slime,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new empty,new empty,new empty},
            {new empty,new empty,new green_slime,new empty,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new empty,new empty,new empty},
            {new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime,new empty,new green_slime,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new empty},
            {new empty,new green_slime,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new green_slime,new green_slime,new empty},
            {new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty},
            {new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty,new empty,new green_slime,new green_slime,new green_slime,new empty,new green_slime,new green_slime,new green_slime,new green_slime,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
        },
        {
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
            {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
        },
        {
             {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new empty,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty},
             {new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime},
             {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime},
             {new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime},
             {new empty,new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime},
             {new green_slime,new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime},
             {new green_slime,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new empty,new green_slime}
        }};
/*
 * can use creating field to avoid new that kind of stupid thing.
 * example
 *  empty *ep=new empty;
 * unit *x[2]={ep,ep};
 * green_slime *gs=new green slime;
 * x[0]=gs;
 * this kind of witchcraft works!
*/
};

#endif // BACKGROUND_H
