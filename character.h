#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once
#include <QString>

class Character
{
public:
//Konstruktory i destruktor
    Character();
    Character(int strength, int mana, int hitpoints, int level, QString Aname, QString Aguild);
    Character(int strength, int mana, int hitpoints, int level, QString Aname, int armore, int damage, QString Aguild);

   // virtual void tura() = 0;

//Settery i Gettery
    int getStrength() ;
    void setStrength(int strength);

    int getMana() ;
    void setMana(int mana);

    int getMax_mana() ;
    void setMax_mana(int max_mana);

    int getHitpoints() ;
    void setHitpoints(int hitpoints);

    int getMax_hitpoints() ;
    void setMax_hitpoints(int max_hitpoints);

    int getLevel() ;
    void setLevel(int level);

    QString getName() ;
    void setName(QString Aname);

    int getArmore() ;
    void setArmore(int armore);

    int getDamage() ;
    void setDamage(int damage);

    QString getGuild() ;
    void setGuild(QString Aguild);

protected:
    //Glowne
    int strength;
    int mana;
    int max_mana;
    int hitpoints;
    int max_hitpoints;
    int level;
    QString name;
    //Dodatkowe
    int armore;
    int damage;
    QString guild;

};

#endif // CHARACTER_H
