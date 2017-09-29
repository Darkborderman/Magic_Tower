#include "empty.h"

empty::empty():unit('e',0,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/unit/empty.png").scaled(48,48));
}
