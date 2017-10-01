#include "yellow_key.h"

yellow_key::yellow_key():unit('k',1,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/yellow key.png").scaled(48,48));
}
