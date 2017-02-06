
#include "character.h"
#include <QString>

Character::Character()
{

}

Character::Character(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild)
{
    setStrength(strength);
    setMana(mana);
    setMax_mana(mana);
    setHitpoints(hitpoints);
    setMax_hitpoints(hitpoints);
    setLevel(level);
    setName(Aname);
    setGuild(Aguild);
}

Character::Character(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild)
{
    setStrength(strength);
    setMana(mana);
    setMax_mana(mana);
    setHitpoints(hitpoints);
    setMax_hitpoints(hitpoints);
    setLevel(level);
    setName(Aname);
    setArmore(armore);
    setDamage(damage);
    setGuild(Aguild);
}

//Glowne
int Character::getStrength()
{
    return strength;
}
void Character::setStrength(int strength)
{
    this->strength = strength;
}

int Character::getMana()
{
    return mana;
}
void Character::setMana(int mana)
{
    this->mana = mana;
}

int Character::getMax_mana()
{
    return max_mana;
}
void Character::setMax_mana(int max_mana)
{
    this->max_mana = max_mana;
}

int Character::getHitpoints()
{
    return hitpoints;
}
void Character::setHitpoints(int hitpoints)
{
    this->hitpoints = hitpoints;
}

int Character::getMax_hitpoints()
{
    return max_hitpoints;
}
void Character::setMax_hitpoints(int max_hitpoints)
{
    this->max_hitpoints = max_hitpoints;
}

int Character::getLevel()
{
    return level;
}
void Character::setLevel(int level)
{
    this->level = level;
}

QString Character::getName()
{
    return name;
}
void Character::setName(QString Aname)
{
    this->name = Aname;
}

//Dodatkowe
int Character::getArmore()
{
    return armore;
}
void Character::setArmore(int armore)
{
    this->armore = armore;
}

int Character::getDamage()
{
    return damage;
}

void Character::setDamage(int damage)
{
    this->damage = damage;
}

QString Character::getGuild()
{
    return guild;
}
void Character::setGuild(QString Aguild)
{
    this->guild = Aguild;
}
