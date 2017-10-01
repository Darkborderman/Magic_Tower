#include "yellow_door.h"

yellow_door::yellow_door():unit('d',1,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/interact/yellowdoor.png").scaled(48,48));
}
