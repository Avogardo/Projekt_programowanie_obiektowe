#include "hero.h"
#include <QString>



Hero::Hero()
{

}

Hero::Hero(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild) : Character(strength, mana, hitpoints, level, Aname, Aguild)
{
    setExp(0);
    setCritical(false);
    setHealing(false);
    setDooge(false);
}

Hero::Hero(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild) : Character(strength, mana, hitpoints, level, Aname, armore, damage, Aguild)
{
    setExp(0);
    setCritical(false);
    setHealing(false);
    setDooge(false);
}

int Hero::getExp()
{
    return exp;
}
void Hero::setExp(int exp)
{
    this->exp = exp;
}

//Umiejetnosci
bool Hero::getCritical()
{
    return critical;
}
void Hero::setCritical(bool critical)
{
    this->critical = critical;
}

bool Hero::getHealing()
{
    return healing;
}
void Hero::setHealing(bool healing)
{
    this->healing = healing;
}

bool Hero::getDooge()
{
    return dooge;
}
void Hero::setDooge(bool dooge)
{
    this->dooge = dooge;
}

void Hero::tura()
{
    this->level++;
}

