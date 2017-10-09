#include "potion_blue.h"

potion_blue::potion_blue():unit('p',2,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/large potion.png").scaled(48,48));
}
