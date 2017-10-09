#include "door_blue.h"

door_blue::door_blue():unit('d',2,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/interact/bluedoor.png").scaled(48,48));
}
