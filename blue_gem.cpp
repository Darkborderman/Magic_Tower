#include "blue_gem.h"

blue_gem::blue_gem():unit('g',2,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/blue gem.png").scaled(48,48));
}
