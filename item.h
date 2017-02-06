#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <QString>


class Item
{
public:
//Konstruktory i destruktor
    Item();
    Item(QString Aitemname, int flag);

//Settery i Gettery
    QString getItemname() ;
    void setItemname(QString Aitemname);

    int getFlag() ;
    void setFlag(int flag);

protected:
    QString itemname;
    //efekty na przedmiocie
    int flag;
};

#endif // ITEM_H
