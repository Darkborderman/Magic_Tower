#include "player.h"

player::player():unit('h',0,100,10,10,0,0)
{
    setPixmap(QPixmap(":/res/unit/hero_front_1"));
    this->level=1;
    this->yellowkey=0;
    this->bluekey=0;
    this->redkey=0;
}
