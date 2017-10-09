#include "door_yellow.h"

door_yellow::door_yellow():unit('d',1,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/interact/yellowdoor.png").scaled(48,48));
}

