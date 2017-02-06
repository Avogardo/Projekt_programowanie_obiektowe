#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include "character.h"
#include "interfacewalka.h"
#include <QString>

class Enemy: public Character, public Tura
{
public:
    Enemy();
    Enemy(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild);
    Enemy(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild);

    void tura();

    bool getPokonany();
    void setPokonany(bool pokonany);

private:
    bool pokonany;
};

#endif // ENEMY_H
