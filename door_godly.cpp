#include "door_godly.h"

door_godly::door_godly():unit('d',4,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/interact/squaredoor.png").scaled(48,48));
}
