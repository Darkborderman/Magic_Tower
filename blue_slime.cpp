#include "blue_slime.h"

blue_slime::blue_slime():unit('m',0,50,15,5,10,10)
{
    setPixmap(QPixmap(":/res/unit/blue slime_1.png").scaled(48,48));
}
