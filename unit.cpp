#include "unit.h"

unit::unit()
{
}
unit::unit(char type, int kind, int hp, int atk, int def, int gold, int exp)
{
    this->type=type;
    this->kind=kind;
    this->hp=hp;
    this->atk=atk;
    this->def=def;
    this->gold=gold;
    this->exp=exp;
}
