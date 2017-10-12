#include "slime_red.h"

slime_red::slime_red():unit('m',0,50,15,5,3,1)
{
    setPixmap(QPixmap(":/res/unit/red slime_1.png").scaled(48,48));
}
void slime_red::loop()
{
    tick++;
    if(tick%4<=1)setPixmap(QPixmap(":/res/unit/red slime_1.png").scaled(48,48));
    else setPixmap(QPixmap(":/res/unit/red slime_2.png").scaled(48,48));
    if(tick>=4) tick=0;
}
