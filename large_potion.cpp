#include "large_potion.h"

large_potion::large_potion():unit('p',2,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/large potion.png").scaled(48,48));
}
