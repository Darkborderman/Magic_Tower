#include "slime_green.h"

slime_green::slime_green():unit('m',0,50,15,5,3,1)
{
    setPixmap(QPixmap(":/res/unit/green slime_1.png").scaled(48,48));
}
void slime_green::loop()
{
    tick++;
    if(tick%4<=1)setPixmap(QPixmap(":/res/unit/green slime_1.png").scaled(48,48));
    else setPixmap(QPixmap(":/res/unit/green slime_2.png").scaled(48,48));
    if(tick>=4) tick=0;
}
