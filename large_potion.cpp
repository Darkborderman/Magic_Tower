#include "large_potion.h"

large_potion::large_potion():unit('p',2,50,15,5,10,10)
{
    setPixmap(QPixmap(":/res/item/large potion.png").scaled(48,48));
}
