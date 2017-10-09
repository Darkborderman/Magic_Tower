#include "key_yellow.h"

key_yellow::key_yellow():unit('k',1,0,0,0,0,0)
{
    setPixmap(QPixmap(":/res/item/yellow key.png").scaled(48,48));
}
