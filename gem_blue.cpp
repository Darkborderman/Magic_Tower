#include "gem_blue.h"

gem_blue::gem_blue():unit('g',2,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/blue gem.png").scaled(48,48));
}
