#include "door_red.h"

door_red::door_red():unit('d',3,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/interact/reddoor.png").scaled(48,48));
}
