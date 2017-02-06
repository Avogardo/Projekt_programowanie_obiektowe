#ifndef WEAPONITEM_H
#define WEAPONITEM_H

#pragma once
#include "item.h"
#include <QString>

class WeaponItem : public Item
{
public:
//Konstruktory i destruktor
    WeaponItem();
    WeaponItem(int weapondamage, QString Aitemname, int flag);

//Settery i Gettery
    int getWeapondamage();
    void setWeapondamage(int weapondamage);

private:
    int weapondamage;
};

#endif // WEAPONITEM_H
