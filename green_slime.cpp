#include "green_slime.h"

green_slime::green_slime():unit('m',0,50,15,5,3,1)
{
    setPixmap(QPixmap(":/res/unit/green slime_1.png").scaled(48,48));
}
void green_slime::loop()
{
    tick++;
    if(tick%4<=1)setPixmap(QPixmap(":/res/unit/green slime_1.png").scaled(48,48));
    else setPixmap(QPixmap(":/res/unit/green slime_2.png").scaled(48,48));
    if(tick>=4) tick=0;
}
