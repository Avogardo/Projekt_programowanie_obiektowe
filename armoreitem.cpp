#include "armoreitem.h"

ArmoreItem::ArmoreItem()
{

}

ArmoreItem::ArmoreItem(int protection, QString Aitemname, int flag) : Item(Aitemname, flag)
{
    setProtection(protection);
}


int ArmoreItem::getProtection()
{
    return protection;
}
void ArmoreItem::setProtection(int protection)
{
    this->protection = protection;
}


