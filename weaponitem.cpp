#include "weaponitem.h"


WeaponItem::WeaponItem()
{

}

WeaponItem::WeaponItem(int weapondamage, QString Aitemname, int flag) : Item(Aitemname, flag)
{
    setWeapondamage(weapondamage);
}

int WeaponItem::getWeapondamage()
{
    return weapondamage;
}
void WeaponItem::setWeapondamage(int weapondamage)
{
    this->weapondamage = weapondamage;
}
