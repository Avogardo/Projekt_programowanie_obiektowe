#ifndef HERO_H
#define HERO_H

#pragma once
#include "character.h"
#include "interfacewalka.h"
#include "mainwindow.h"
#include <QString>
#include <iostream>

using namespace std;

class Hero : public Character, public Tura
{
public:
    Hero();
    Hero(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild);
    Hero(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild);

    void tura();

    int getExp() ;
    void setExp(int exp);

    bool getCritical();
    void setCritical(bool critical);

    bool getHealing();
    void setHealing(bool healing);

    bool getDooge();
    void setDooge(bool dooge);

    Hero & operator +=( const Hero & v )
    {
        this->exp += v.exp;
        return * this;
    }

private:
    int exp;
    //Umiejetnosci
    bool critical;
    bool healing;
    bool dooge;

};

#endif // HERO_H
