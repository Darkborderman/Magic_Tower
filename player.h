#ifndef PLAYER_H
#define PLAYER_H
#include"unit.h"

class player: public unit
{
public:
    player();
    int x,y;
    int direction;
    int level;
    int redkey,bluekey,yellowkey;
};

#endif // PLAYER_H
