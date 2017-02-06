#ifndef ARMOREITEM_H
#define ARMOREITEM_H

#include <QString>
#include "item.h"

class ArmoreItem : public Item
{
public:
    //Konstruktory i destruktor
    ArmoreItem();
    ArmoreItem(int protection, QString Aitemname, int flag);

    //Settery i Gettery
    int getProtection() ;
    void setProtection(int protection);



private:
    int protection;
};

#endif // ARMOREITEM_H
