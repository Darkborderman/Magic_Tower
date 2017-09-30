#include "player.h"

player::player():unit('h',1,2000,10,10,0,0)
{
    setPixmap(QPixmap(":/res/unit/hero_front_1.png"));
    this->level=1;
    this->yellowkey=0;
    this->bluekey=0;
    this->redkey=0;
}
void player::loop()
{
    //use kind to express the direction since the unit can't access the int direction
    if(this->kind==1)
    {
        tick=1;
        setPixmap(QPixmap(":/res/unit/hero_back_"+QString::number(tick)+".png").scaled(48,48));
    }
    if(this->kind==2)
    {
        tick=1;
        setPixmap(QPixmap(":/res/unit/hero_left_"+QString::number(tick)+".png").scaled(48,48));
    }
    if(this->kind==3)
    {
        tick=1;
        setPixmap(QPixmap(":/res/unit/hero_front_"+QString::number(tick)+".png").scaled(48,48));
    }
    if(this->kind==4)
    {
        tick=1;
        setPixmap(QPixmap(":/res/unit/hero_right_"+QString::number(tick)+".png").scaled(48,48));
    }
}
