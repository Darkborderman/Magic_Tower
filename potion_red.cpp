#include "potion_red.h"

potion_red::potion_red():unit('p',1,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/small potion.png").scaled(48,48));
}
