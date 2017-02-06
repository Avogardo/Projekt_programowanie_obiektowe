#include "item.h"
#include <QString>

Item::Item()
{

}

Item::Item(QString Aitemname, int flag)
{
    setItemname(Aitemname);
    setFlag(flag);
}

QString Item::getItemname()
{
    return itemname;
}
void Item::setItemname(QString Aitemname)
{
    this->itemname = Aitemname;
}

//efekty na przedmiocie
int Item::getFlag()
{
    return flag;
}
void Item::setFlag(int flag)
{
    this->flag = flag;
}
