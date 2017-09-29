#include "green_slime.h"

green_slime::green_slime():unit('m',0,50,15,5,10,10)
{
    setPixmap(QPixmap(":/res/unit/green slime_1.png").scaled(48,48));
}
void green_slime::loop()
{
    if(tick==1) tick=2;
    else tick=1;
    setPixmap(QPixmap(":/res/unit/green slime_"+QString::number(tick)+".png").scaled(48,48));
}
