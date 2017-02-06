#include <QString>
#include "enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild) : Character(strength, mana, hitpoints, level, Aname, Aguild)
{
    setPokonany(false);
}

Enemy::Enemy(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild) : Character(strength, mana, hitpoints, level, Aname, armore, damage, Aguild)
{
    setPokonany(false);
}

void Enemy::tura()
{
    setPokonany(true);
}

bool Enemy::getPokonany()
{
    return pokonany;
}
void Enemy::setPokonany(bool pokonany)
{
    this->pokonany = pokonany;
}
