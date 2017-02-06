#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QKeyEvent>
#include <vector>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "Character.h"
#include "hero.h"
#include "enemy.h"
#include "item.h"
#include "armoreitem.h"
#include "weaponitem.h"

using namespace std;

vector <ArmoreItem> hero_arm;
vector <WeaponItem> hero_wep;
vector <Enemy> przeciwnik;
QString imie = NULL;
Hero* hero;
Enemy* enemy;

//Przedmioty
ArmoreItem beczka(17, "Beczka na szelkach", 1);
ArmoreItem szata(20, "Szata maga", 2);
ArmoreItem Zbroja(30, "Zbroja rycerza", 1);

WeaponItem knife(17, "Noz na wilki", 1);
WeaponItem staff(20, "Kostur wiecznego wedrowca", 3);
WeaponItem sword(40, "Miecz", 1);
WeaponItem long_sword(55, "Dlugi miecz", 1);

Hero palladyn(80, 20, 100, 1, imie, "Palladyn");
Hero giermek(70, 30, 80, 1, imie, "Giermek");



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    podmenu = "menu";

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    blackpen.setWidth(2);

    //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_line_command_returnPressed()
{
    /////////////////////// MENU ////////////////////////

    if (podmenu == "o grze")
    {
        o_grze();
    }
    if (podmenu == "menu")
    {
    menu();
    }
    if (podmenu == "nowa gra")
    {
    nowa_gra();
    }
    if (podmenu == "wybor gildii")
    {
        wybor_gildii();
    }
    if (podmenu == "przejscie do losowania")
    {
        przejscie_do_losowania();
    }
    if (podmenu == "losowanie")
    {
        losowanie_przeciwnika();
    }
    if (podmenu == "walka")
    {
        walka();
    }
    if (podmenu == "zmiana_tury_tohero")
    {
        zmiana_tury_tohero();
    }
    if (podmenu == "zmiana_tury_toenemy")
    {
        zmiana_tury_toenemy();
    }
    if (podmenu == "wygrana")
    {
        wygrana();
    }
    if (podmenu == "przejscie_do_kolejnego_losowania")
    {
        przejscie_do_kolejnego_losowania();
    }
    if (podmenu == "kolejne_losowanie")
    {
        kolejne_losowanie();
    }

}


/////////////////////////////////////////////////////
////////////////////// KOMENDY //////////////////////
/////////////////////////////////////////////////////

/////////////////////// MENU ////////////////////////

void MainWindow::menu()
{
    //Przeciwnicy




    Enemy battlehelper(10, 10, 50, 1, "Battlehelper", "Warrior");
    Enemy Giermek(20, 20, 70, 1, "Giermek", "Warrior");
    Enemy mage_helper(30, 50, 80, 2, "Pomocnik maga", "Mage");
    Enemy Rycerz(50, 20, 150, 3, "Rycerz", "Warrior");
    Enemy Mag(50, 70, 140, 4, "Mag", "Mage");
    Enemy Boss(70, 70, 180, 5, "Twoja stara", "Boss");






    ui ->ekran ->setText("WITAJ W GRZE");

    ui ->available_commend ->setText("1. Nowa gra\n2. Wczytaj gre nazwa gry\n3. O grze\n4. Wyjscie");


    Enemy testmodel(8, 9, 90, 1, "Koles", 4, 8, "Ork");
    ArmoreItem a1(1, "Zbroja", 1);


    if(ui-> line_command ->text()== "2")
    {
    ui ->ekran ->setText(QStringLiteral("My magic number is %1. That's all!").arg(testmodel.getHitpoints()));
    clear();
    }



/////////////////////// Nowa gra ////////////////////
    if((ui-> line_command ->text()== "1")
    || (ui-> line_command ->text()== "Nowa gra")
    || (ui-> line_command ->text()== "nowa gra")
    || (ui-> line_command ->text()== "1. Nowa gra")
    || (ui-> line_command ->text()== "1. nowa gra")
    || (ui-> line_command ->text()== "1.Nowa gra" )
    || (ui-> line_command ->text()== "1.nowa gra" )
    || (ui-> line_command ->text()== "1 Nowa gra" )
    || (ui-> line_command ->text()== "1 nowa gra")
    || (ui-> line_command ->text()== "1nowa gra"))
    {
    podmenu = "nowa gra";
    clear();
    nowa_gra();
    }


/////////////////////// O grze //////////////////////
    if((ui-> line_command ->text()== "3")
    || (ui-> line_command ->text()== "O grze")
    || (ui-> line_command ->text()== "o grze")
    || (ui-> line_command ->text()== "3.O grze")
    || (ui-> line_command ->text()== "3.o grze" )
    || (ui-> line_command ->text()== "3. O grze" )
    || (ui-> line_command ->text()== "3. o grze"))
    {
    podmenu = "o grze";
    clear();
    o_grze();
    }

/////////////////////// Wyjscie //////////////////////
if((ui-> line_command ->text()== "4")
|| (ui-> line_command ->text()== "Wyjscie")
|| (ui-> line_command ->text()== "wyjscie")
|| (ui-> line_command ->text()== "4.Wyjscie")
|| (ui-> line_command ->text()== "4.wyjscie")
|| (ui-> line_command ->text()== "4. Wyjscie" )
|| (ui-> line_command ->text()== "4. wyjscie"))
{
    ui ->ekran ->setText("Wychodze");
    window()->close();
}

}

/////////////////////// O grze //////////////////////
void MainWindow::o_grze()
{

    ui ->ekran ->setText("Gra tekstowa, nie ma przyciskow");

    ui ->available_commend ->setText("1. Powrot");


        if((ui-> line_command ->text()== "powrot")
        || (ui-> line_command ->text()== "Powrot")
        || (ui-> line_command ->text()== "1.Powrot")
        || (ui-> line_command ->text()== "1.powrot")
        || (ui-> line_command ->text()== "1. powrot")
        || (ui-> line_command ->text()== "1. Powrot")
        || (ui-> line_command ->text()== "1"))
        {
        ui ->available_commend ->setText("Nowa gra");
        podmenu = "menu";
        clear();
        menu();
        }
}

void MainWindow::nowa_gra()
{
    ui ->ekran ->setText("NOWA GRA\n\nWpisz imie bohatera");

    ui ->available_commend ->setText("1. Powrot");

    if((ui-> line_command ->text()== "powrot")
    || (ui-> line_command ->text()== "Powrot")
    || (ui-> line_command ->text()== "1.Powrot")
    || (ui-> line_command ->text()== "1.powrot")
    || (ui-> line_command ->text()== "1. powrot")
    || (ui-> line_command ->text()== "1. Powrot")
    || (ui-> line_command ->text()== "1"))
    {
    ui ->available_commend ->setText("Nowa gra");
    podmenu = "menu";
    clear();
    menu();
    }


    imie = ui ->line_command ->text() ;
    palladyn.setName(imie);
    giermek.setName(imie);
    clear();

    if(imie !=NULL)
{
    ui ->ekran ->setText("NOWA GRA\n\nWpisz imie bohatera\nWybierz gildie");
    ui ->available_commend ->setText("1. Powrot\n\n2. Palladyn\n3.Giermek");
    podmenu = "wybor gildii";
    wybor_gildii();


}
}

void MainWindow::wybor_gildii()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    blackpen.setWidth(2);


    bool mikze = false;
    if((ui-> line_command ->text()== "powrot")
    || (ui-> line_command ->text()== "Powrot")
    || (ui-> line_command ->text()== "1.Powrot")
    || (ui-> line_command ->text()== "1.powrot")
    || (ui-> line_command ->text()== "1. powrot")
    || (ui-> line_command ->text()== "1. Powrot")
    || (ui-> line_command ->text()== "1"))
    {
    ui ->available_commend ->setText("Nowa gra");
    podmenu = "nowa gra";
    clear();
    nowa_gra();
    }

    if(((ui-> line_command ->text()== "Palladyn")
    || (ui-> line_command ->text()== "palladyn")
    || (ui-> line_command ->text()== "2.Palladyn")
    || (ui-> line_command ->text()== "2.palladyn")
    || (ui-> line_command ->text()== "2. Palladyn")
    || (ui-> line_command ->text()== "2. palladyn")
    || (ui-> line_command ->text()== "2"))
    && mikze == false)
    {
    hero= &palladyn;
    hero_arm.push_back(beczka);
    hero_wep.push_back(knife);

//    biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
    pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, blackpen, grayBrush);
    pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, blackpen, grayBrush);
    pasek_bohatera_mana = scene->addRect(+10, -50, hero->getMana(), 10, blackpen, blueBrush);
    pasek_bohatera = scene->addRect(-10, -70, hero->getHitpoints(), 20, blackpen, redBrush);



    ui ->ekran ->setText("NOWA GRA\n\nWpisz imie bohatera\nWybierz gildie\n\nRozpoczynamy gre");
    ui ->available_commend ->setText("1. Czas rozpoczac pierwsza walke! (OK)");
    //ui ->textBrowser ->setText(hero->getName());
    ui->textBrowser->setText(QStringLiteral("%1").arg(hero->getHitpoints()));
    mikze = true;
    clear();
    podmenu = "przejscie do losowania";
    przejscie_do_losowania();
    }

    if(((ui-> line_command ->text()== "Giermek")
    || (ui-> line_command ->text()== "giermek")
    || (ui-> line_command ->text()== "3.Giermek")
    || (ui-> line_command ->text()== "3.giermek")
    || (ui-> line_command ->text()== "3. Giermek")
    || (ui-> line_command ->text()== "3. giermek")
    || (ui-> line_command ->text()== "3"))
    && mikze == false)
    {
    hero= &giermek;
    hero_arm.push_back(beczka);
    hero_wep.push_back(knife);

//    biala_plansza = scene->addRect(0, 0, 100, 100, whitepen, whiteBrush);
    pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, blackpen, grayBrush);
    pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, blackpen, grayBrush);
    pasek_bohatera_mana = scene->addRect(+10, -50, hero->getMana(), 10, blackpen, blueBrush);
    pasek_bohatera = scene->addRect(-10, -70, hero->getHitpoints(), 20, blackpen, redBrush);

    hero->setHealing(true);
    ui ->ekran ->setText("NOWA GRA\n\nWpisz imie bohatera\nWybierz gildie\n\nRozpoczynamy gre");
    ui ->available_commend ->setText("1. Czas rozpoczac pierwsza walke! (OK)");
    ui ->textBrowser ->setText(hero ->getName());
    mikze = true;
    clear();
    podmenu = "przejscie do losowania";
    przejscie_do_losowania();
    }
}

void MainWindow::przejscie_do_losowania()
{
    if((ui-> line_command ->text()== "OK")
    || (ui-> line_command ->text()== "Ok")
    || (ui-> line_command ->text()== "1 Ok")
    || (ui-> line_command ->text()== "1 OK")
    || (ui-> line_command ->text()== "1. ok")
    || (ui-> line_command ->text()== "ok")
    || (ui-> line_command ->text()== "1"))
    {
        clear();
        hero->setHitpoints(hero->getMax_hitpoints());
        hero->setMana(hero->getMax_mana());
        //ui->textBrowser->setText(hero->getName());
        //ui->textBrowser->setText(QStringLiteral("%1").arg(hero->getStrength()));
        podmenu = "losowanie";
        losowanie_przeciwnika();
    }
}

/////////////////////////////////////////////////////
///////////////////////// Walka /////////////////////
/////////////////////////////////////////////////////

/////////////////////// Losowanie ///////////////////
void MainWindow::losowanie_przeciwnika()
{
    srand(time(NULL));

    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    blackpen.setWidth(2);

    int strenght = (hero->getLevel() *10) + 10;
    int mana = (std::rand() % (hero->getLevel() * 10)) + (hero->getLevel() + 10);
    int hitpoints = (hero->getLevel() * 20) + 50;
    int level = (std::rand() % ((hero->getLevel() + 1))) + (hero->getLevel());
    QString guild;
    if (strenght > mana)
        guild = "Wojownik";
    else
        guild = "Mag";

    QString Eimie;
    if (strenght > mana && level == 1)
    {
        Eimie = "Rycerz";
    } else
        Eimie = "Mag";


    //przeciwnik.insert(przeciwnik.begin(), Enemy(strenght, mana, hitpoints, level, Eimie, guild));
    przeciwnik.push_back(Enemy(strenght, mana, hitpoints, level, Eimie, guild));
    enemy = &przeciwnik[0];

   // if(level == 1 || level == 2)
   // {
   //     enemy->setArmore(beczka.getProtection());
   //     enemy->setDamage(knife.getWeapondamage());
   // }
   //     else
        if(level == 3 || level == 4 || level == 1 || level == 2)
    {

        enemy->setArmore(szata.getProtection());
        enemy->setDamage(staff.getWeapondamage());
    } else
    {
        enemy ->setArmore(Zbroja.getProtection());
        enemy->setDamage(sword.getWeapondamage());
    }

//        biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
        pasek_wroga_mana_max = scene->addRect(10, 70, enemy->getMax_mana(), 10, blackpen, grayBrush);
        pasek_wroga_max = scene->addRect(-10, +50, enemy->getMax_hitpoints(), 20, blackpen, grayBrush);
        pasek_wroga_mana = scene->addRect(10, 70, enemy->getMana(), 10, blackpen, blueBrush);
        pasek_wroga = scene->addRect(-10, +50, enemy->getHitpoints(), 20, blackpen, greenBrush);


    ui ->ekran ->setText("Twoim pierwszym przeciwnikiem będzie: "  );
    ui ->textBrowser ->setText(Eimie);

   // ui->textBrowser->setText(hero->getName());
    //ui->textBrowser->setText(QStringLiteral("%1").arg(enemy->getHitpoints()));

    podmenu = "walka";
    walka();




}

/////////////////////// Walka ///////////////////
void MainWindow::walka()
{
    int critic;
    int a;

    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);


    blackpen.setWidth(2);

    int enemy_zdrowie = enemy->getHitpoints();
    //int hero_zdrowie = hero->getHitpoints();

    QString Aflaga = " ";
    QString Wflaga = " ";
    QString critical = "Nienauczony";
    QString leczenie = "Nienauczony";
    QString unik = "Nienauczony";




    hero->setArmore(hero_arm[0].getProtection());
    hero->setDamage(hero_wep[0].getWeapondamage());

//while (enemy->getHitpoints() > 0 || hero->getHitpoints() > 0)
//{

    ui->ekran ->setText("Twoj ruch!");
    ui ->available_commend ->setText("1. Zwykly atak\n2. Silny atak\n3. Leczenie\n4. Wyswietl informacje o sobie\n5. Wyswietl informacje o przeciwniku\n6. Pomoc");

    a = ui->line_command ->text().toInt();

    switch(a)
    {
    case 1:
        critic = (std::rand() % (9));
         if(((enemy->getArmore() - (hero->getDamage() + 0.1 * hero->getStrength())) < 0) && (critic == 0 || critic == 1))
         {
            enemy->setHitpoints(enemy->getHitpoints() + (enemy->getArmore() - (hero->getDamage() + 0.1 * hero->getStrength())));

                    ui->textBrowser->setText("10");

            ui ->ekran ->setText(QStringLiteral("Zadalez %1 punktow obrazen z trafieniem krytycznym").arg(enemy_zdrowie - enemy->getHitpoints()));

            //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_wroga();

            clear();
         }  else if(((enemy->getArmore() - hero->getDamage()) < 0) && critic > 1)
         {
            enemy->setHitpoints(enemy->getHitpoints() + (enemy->getArmore() - hero->getDamage()));

                    ui->textBrowser->setText("11");

            ui ->ekran ->setText(QStringLiteral("Zadalez %1 punktow obrazen").arg(enemy_zdrowie - enemy->getHitpoints()));

            //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_wroga();

            clear();
         }            else
         {
                     ui->textBrowser->setText("12");
             ui ->ekran->setText("Nie zadales obrazen");
         clear();
         }
         if(enemy->getHitpoints() <= 0)
         {
             podmenu = "wygrana";
         wygrana();
         }
         podmenu = "zmiana_tury_toenemy";
         zmiana_tury_toenemy();
        break;

    case 2:
        critic = (std::rand() % (9));
         if(((enemy->getArmore() - (hero->getDamage() + 0.2 * hero->getStrength())) < 0) && critic == 0 )
         {
            enemy->setHitpoints(enemy->getHitpoints() + (enemy->getArmore() - (hero->getDamage() + 0.2 * hero->getStrength())));

            ui->textBrowser->setText(QStringLiteral("%1").arg(enemy->getHitpoints()));

            ui ->ekran ->setText(QStringLiteral("Zadalez %1 punktow obrazen z trafieniem krytycznym").arg(enemy_zdrowie - enemy->getHitpoints()));

            //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_wroga();

            clear();
         }  else if(((enemy->getArmore() - (hero->getDamage() + 0.1 * hero->getStrength())) < 0) && critic > 0)
         {
            enemy->setHitpoints(enemy->getHitpoints() + (enemy->getArmore() - (hero->getDamage() + 0.1 * hero->getStrength())));

            ui->textBrowser->setText(QStringLiteral("%1").arg(enemy->getHitpoints()));

            ui ->ekran ->setText(QStringLiteral("Zadalez %1 punktow obrazen").arg(enemy_zdrowie - enemy->getHitpoints()));

            //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
 wyswietl_paski_wroga();

            clear();
         }            else
         {
             ui ->ekran->setText("Nie zadales obrazen");
         clear();
         }
         if(enemy->getHitpoints() <= 0)
         {
             podmenu = "wygrana";
         wygrana();
         }
         podmenu = "zmiana_tury_toenemy";
         zmiana_tury_toenemy();
         clear();
        break;

    case 3:
        if(hero->getHealing() == false)
            ui->ekran->setText("Nie jestes nauczony leczenia!");
        else if (hero->getHealing() == true && hero->getMana() > 4 && (hero->getHitpoints() < (hero->getMax_hitpoints() - 15)))
        {
            hero->setMana(hero->getMana()-5);
            hero->setHitpoints(hero->getHitpoints()+15);
            ui->ekran->setText("Leczysz sie! \n+15 Punkty trafien\n-5 Mana");

wyswietl_paski_bohatera();
podmenu = "zmiana_tury_toenemy";
zmiana_tury_toenemy();
clear();
        }
        else if (hero->getHealing() == true && hero->getMana() > 4 && (hero->getHitpoints() > (hero->getMax_hitpoints() - 15)))
        {
            hero->setMana(hero->getMana()-5);
            hero->setHitpoints(hero->getMax_hitpoints());

            ui->ekran->setText("Leczysz sie! \nMax Punkty trafien\n-5 Mana");

            //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_bohatera();
podmenu = "zmiana_tury_toenemy";
zmiana_tury_toenemy();
clear();
        }

        else if (hero->getHealing() == true && hero->getMana() < 4 )
        {
            ui->ekran->setText("Nie masz wystarczajaco many!");

            wyswietl_paski_bohatera();
            podmenu = "zmiana_tury_toenemy";
            zmiana_tury_toenemy();
            clear();
        }

        break;

    case 4:

        if (hero_arm[0].getFlag() == 2)
            Aflaga = "\nSpecjalna zdolnosc: +10 Mana";

        if (hero_wep[0].getFlag() ==3)
            Wflaga = "\nSpecjalna zdolnosc: +10 obrazenia od ognia";

        if (hero->getCritical() == true)
            critical = "Nauczony";

        if (hero->getHealing() == true)
            leczenie = "Nauczony";

        if (hero->getDooge() == true)
            unik = "Nauczony";


        ui ->ekran ->setText(hero->getName() +
                             QStringLiteral("\n\nPoziom: %1\nSila: %2\nPunkty doswiadczenia: %3\n").arg(hero->getLevel()).arg(hero->getStrength()).arg(hero->getExp()) +
                             "Gildia: " + hero->getGuild() +
                             QStringLiteral("\nMana: %1/%2").arg(hero->getMana()).arg(hero->getMax_mana()) +
                             QStringLiteral("\nPunkty trafien: %1/%2").arg(hero->getHitpoints()).arg(hero->getMax_hitpoints()) +
                             "\n\nZalozona zbroja: " + hero_arm[0].getItemname() + QStringLiteral("\nObrona: %1").arg(hero_arm[0].getProtection()) + Aflaga +
                             "\n\nZalozony orez: " + hero_wep[0].getItemname() + QStringLiteral("\nObrazenia: %1").arg(hero_wep[0].getWeapondamage()) + Wflaga +
                             "\n\nUmiejetnosci:\n" + "Cios krytyczny: " + critical + "\nLeczenie: " + leczenie + "\nUnik: " + unik);
        clear();
        break;

    case 5:
        ui ->ekran ->setText(enemy->getName() +
                             QStringLiteral("\n\nPoziom: %1\nSila: %2\n").arg(enemy->getLevel()).arg(enemy->getStrength()) +
                             "Gildia: " + enemy->getGuild() +
                             QStringLiteral("\nMana: %1/%2").arg(enemy->getMana()).arg(enemy->getMax_mana()) +
                             QStringLiteral("\nPunkty trafien: %1/%2").arg(enemy->getHitpoints()).arg(enemy->getMax_hitpoints())
                             //"\n\nZalozona zbroja: " + hero_arm[0].getItemname() + QStringLiteral("\nObrona: %1").arg(hero_arm[0].getProtection()) + Aflaga +
                             //"\n\nZalozony orez: " + hero_wep[0].getItemname() + QStringLiteral("\nObrazenia: %1").arg(hero_wep[0].getWeapondamage()) + Wflaga
                             );
        clear();

        break;
    }
//}


}

void MainWindow::przeciwnika_tura()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    blackpen.setWidth(2);

    //int enemy_zdrowie = enemy->getHitpoints();
    int hero_zdrowie = hero->getHitpoints();

    int atack = (std::rand() % (2));
    int critic = (std::rand() % (9));

    ui->textBrowser->setText("Przeciwnika tura");

     if((((hero->getArmore() - (enemy->getDamage() + 0.1 * enemy->getStrength())) < 0) && (critic == 0 || critic == 1)) && atack == 0)
     {
        hero->setHitpoints(hero->getHitpoints() + (hero->getArmore() - (enemy->getDamage() + 0.1 * enemy->getStrength())));

        ui->textBrowser->setText("1");

        ui ->ekran ->setText(QStringLiteral("Przeciwnik zadal %1 punktow obrazen").arg(hero_zdrowie - hero->getHitpoints()));

        //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_bohatera();

        clear();
     }  else if((((hero->getArmore() - hero->getDamage()) < 0) && critic > 1) && atack == 0)
     {
        hero->setHitpoints(hero->getHitpoints() + (hero->getArmore() - enemy->getDamage()));

        ui->textBrowser->setText("2");

        ui ->ekran ->setText(QStringLiteral("Przeciwnik zadal %1 punktow obrazen").arg(hero_zdrowie - hero->getHitpoints()));

       // biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_bohatera();

        clear();
     }            else
     {
                 ui->textBrowser->setText("3");
         ui ->ekran->setText("Nie otrzymujesz obrazen");
     clear();
     }
     if((hero->getHitpoints() <= 0) && atack == 0)
     {
         podmenu = "przegrana";
        przegrana();
     }


      if((((hero->getArmore() - (enemy->getDamage() + 0.2 * enemy->getStrength())) < 0) && (critic == 0 || critic == 1)) && atack == 1)
      {
         hero->setHitpoints(hero->getHitpoints() + (hero->getArmore() - (enemy->getDamage() + 0.2 * enemy->getStrength())));

                 ui->textBrowser->setText("4");

         ui ->ekran ->setText(QStringLiteral("Przeciwnik zadal %1 punktow obrazen").arg(hero_zdrowie - hero->getHitpoints()));

         //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_bohatera();

         clear();
      }  else if((((hero->getArmore() - (enemy->getDamage() + 0.1 * enemy->getStrength())) < 0) && critic > 0) && atack == 1)
      {
         hero->setHitpoints(hero->getHitpoints() + (hero->getArmore() - (enemy->getDamage() + 0.1 * enemy->getStrength())));

                 ui->textBrowser->setText("5");

         ui ->ekran ->setText(QStringLiteral("Przeciwnik zadal %1 punktow obrazen").arg(hero_zdrowie - hero->getHitpoints()));

         //biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
wyswietl_paski_bohatera();

         clear();
      }            //else
     // {
                //  ui->textBrowser->setText("6");
        //  ui ->ekran->setText("Nie otrzymujesz obrazen");
    //  clear();
     // }
      if((hero->getHitpoints() <= 0))
      {
          podmenu = "przegrana";
         przegrana();
      }


      if(enemy->getMana() > 4 && atack == 2)
      {
                  ui->textBrowser->setText("7");
          enemy->setMana(enemy->getMana() - 5);
          hero ->setHitpoints(hero->getHitpoints() - 12);

          ui->ekran->setText("Przeciwnik zadaje 12 punktow obrazen kula ognia");

          biala_plansza = scene->addRect(0, 0, 252, 197, whitepen, whiteBrush);
          pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, blackpen, grayBrush);
          pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, blackpen, grayBrush);
          pasek_bohatera_mana = scene->addRect(+10, -50, hero->getMana(), 10, blackpen, blueBrush);
          pasek_bohatera = scene->addRect(-10, -70, hero->getHitpoints(), 20, blackpen, redBrush);
      }

    podmenu = "zmiana_tury_tohero";
    zmiana_tury_tohero();
}

void MainWindow::zmiana_tury_tohero()
{
    ui->textBrowser->setText("To hero");
    ui->available_commend->setText("0. Przejdz do swojego ruchu");
    if(ui->line_command->text()== "0")
    {
        clear();
        podmenu = "walka";
        walka();
    }
}

void MainWindow::zmiana_tury_toenemy()
{
        ui->textBrowser->setText("To enemy");
    ui->available_commend->setText("0. Przejdz do ruchu przeciwnika");
    if(ui->line_command->text()== "0")
    {
        clear();
        przeciwnika_tura();
    } else if(enemy->getHitpoints() <= 0)
    {
        podmenu = "wygrana";
        wygrana();
     }
}

void MainWindow::wygrana()
{


    if(enemy->getLevel() == 1 || enemy->getLevel() == 2 || enemy->getLevel() == 3 || enemy->getLevel() == 4)
    {
        //enemy->setPokonany(true);
        enemy->tura();
        ui->ekran->setText("Wygrales\n\nOtrzymujesz: " + szata.getItemname() + " oraz " + staff.getItemname());
        ui ->available_commend ->setText("1. Losuj kolejnego przeciwnika");
        hero_arm.push_back(szata);
        hero_wep.push_back(staff);
        //hero_arm.insert(hero_arm.begin(), szata);
        //hero_wep.insert(hero_wep.begin(), staff);

        hero += enemy->getLevel() * 10;
    //hero->tura();
        clear();
        podmenu = "przejscie_do_kolejnego_losowania";
        przejscie_do_kolejnego_losowania();

    }
     else
    {
        enemy->setPokonany(true);
        ui->ekran->setText("Wygrales\n\nOtrzymujesz: " + Zbroja.getItemname() + " oraz " + sword.getItemname());
        ui ->available_commend ->setText("1. Losuj kolejnego przeciwnika");
        //hero_arm.insert(hero_arm.begin(), Zbroja);
        //hero_wep.insert(hero_wep.begin(), sword);
        hero_arm.push_back(szata);
        hero_wep.push_back(staff);
        hero += enemy->getLevel() * 10;

        clear();
        podmenu = "przejscie_do_kolejnego_losowania";
        przejscie_do_kolejnego_losowania();

    }
}

void MainWindow::przegrana()
{
    ui->ekran->setText("Przegrales");
    ui->available_commend->setText("Koniec gry");
}

void MainWindow::przejscie_do_kolejnego_losowania()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    blackpen.setWidth(2);

    if(ui-> line_command ->text()== "1")
    {
        hero->setHitpoints(hero->getMax_hitpoints());
        hero->setMana(hero->getMax_mana());

        pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, whitepen, whiteBrush);
        pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, whitepen, whiteBrush);
        pasek_bohatera_mana = scene->addRect(+10, -50, hero->getMana(), 10, blackpen, blueBrush);
        pasek_bohatera = scene->addRect(-10, -70, hero->getHitpoints(), 20, blackpen, redBrush);

        //ui->textBrowser->setText(hero->getName());
        //ui->textBrowser->setText(QStringLiteral("%1").arg(hero->getStrength()));
        clear();
        podmenu = "kolejne_losowanie";
        kolejne_losowanie();
    }


}

void MainWindow::kolejne_losowanie()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);

    int strenght = (hero->getLevel() *10) + 10;
    int mana = (hero->getLevel() *15) + 5;
    int hitpoints = (hero->getLevel() * 20) + 50;
    int level = (std::rand() % ((hero->getLevel() + 1))) + (hero->getLevel());
    QString guild;
    if (strenght > mana)
        guild = "Wojownik";
    else
        guild = "Mag";

    QString Eimie;
    if (strenght > mana && level == 1)
    {
        Eimie = "Battlehelper";
    } else
        Eimie = "Testmodel";


    //przeciwnik.insert(przeciwnik.begin(), Enemy(strenght, mana, hitpoints, level, Eimie, guild));
    przeciwnik.push_back(Enemy(strenght, mana, hitpoints, level, Eimie, guild));
    enemy = &przeciwnik[1];


        if(level == 3 || level == 4 || level == 1 || level == 2)
    {

        enemy->setArmore(szata.getProtection());
        enemy->setDamage(staff.getWeapondamage());
    } else
    {
        enemy ->setArmore(Zbroja.getProtection());
        enemy->setDamage(sword.getWeapondamage());
    }


    ui ->textBrowser ->setText(Eimie);

    pasek_wroga_mana_max = scene->addRect(10, 70, enemy->getMax_mana(), 10, blackpen, grayBrush);
    pasek_wroga_max = scene->addRect(-10, +50, enemy->getMax_hitpoints(), 20, blackpen, grayBrush);
    pasek_wroga_mana = scene->addRect(10, 70, enemy->getMana(), 10, blackpen, blueBrush);
    pasek_wroga = scene->addRect(-10, +50, enemy->getHitpoints(), 20, blackpen, greenBrush);

   // ui->textBrowser->setText(hero->getName());
    //ui->textBrowser->setText(QStringLiteral("%1").arg(enemy->getHitpoints()));

    podmenu = "walka";
    walka();
}

void MainWindow::wyswietl_paski_wroga()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);


    pasek_wroga_mana_max = scene->addRect(10, 70, enemy->getMax_mana(), 10, whitepen, whiteBrush);
    pasek_wroga_max = scene->addRect(-10, +50, enemy->getMax_hitpoints(), 20, whitepen, whiteBrush);
    pasek_wroga_mana_max = scene->addRect(10, 70, enemy->getMax_mana(), 10, blackpen, grayBrush);
    pasek_wroga_max = scene->addRect(-10, +50, enemy->getMax_hitpoints(), 20, blackpen, grayBrush);
    pasek_wroga_mana = scene->addRect(10, 70, enemy->getMana(), 10, blackpen, blueBrush);
    pasek_wroga = scene->addRect(-10, +50, enemy->getHitpoints(), 20, blackpen, greenBrush);
}

void MainWindow::wyswietl_paski_bohatera()
{
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QBrush whiteBrush(Qt::white);
    QPen blackpen(Qt::black);
    QPen whitepen(Qt::white);


    pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, whitepen, whiteBrush);
    pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, whitepen, whiteBrush);
    pasek_bohatera_mana_max = scene->addRect(+10, -50, hero->getMax_mana(), 10, blackpen, grayBrush);
    pasek_bohatera_max = scene->addRect(-10, -70, hero->getMax_hitpoints(), 20, blackpen, grayBrush);
    pasek_bohatera_mana = scene->addRect(+10, -50, hero->getMana(), 10, blackpen, blueBrush);
    pasek_bohatera = scene->addRect(-10, -70, hero->getHitpoints(), 20, blackpen, redBrush);
}


/////////////////////////////////////////////////////
////////////////////// Pasek menu ///////////////////
/////////////////////////////////////////////////////

/////////////////////// Nowa gra ////////////////////
void MainWindow::on_actionNowa_gra_triggered()
{

    if(podmenu == "o grze" || podmenu == "menu")
    {
        podmenu = "nowa gra";
        nowa_gra();
    } else
    {
        QMessageBox::information(this, tr("Uwaga"), tr("Niezapisany postep zostanie utracony"));
    }
}

/////////////////////// Zapis gry /////////////////////
void MainWindow::on_actionZapisz_gre_triggered()
{
    QString aktualny_stan = "C:/projekt/save.txt";
    write(aktualny_stan);
}

void MainWindow::write(QString aktualny_stan)
{
    QFile stan(aktualny_stan);

    if(!stan.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Nie mozna otworzyc pliku";
        return;
    }

    QTextStream out(&stan);
    out << podmenu;


    stan.flush();
    stan.close();
}

/////////////////////// Wczytanie gry ///////////////////
void MainWindow::on_actionWczytaj_gre_triggered()
{
        QString aktualny_stan = "C:/projekt/save.txt";
        read(aktualny_stan);
}

void MainWindow::read(QString aktualny_stan)
{
    QFile stan(aktualny_stan);

    if(!stan.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Nie mozna otworzyc pliku dla czytania";
        return;
    }

    QTextStream in(&stan);
    QString text_stan = in.readAll();

    qDebug() << text_stan;
    podmenu = text_stan;

    stan.close();
}

/////////////////////// Wyjscie ///////////////////////
void MainWindow::on_actionWyjscie_triggered()
{
    window()->close();
}


/////////////////////////////////////////////////////
////////////////// Czyszczenie ekranu ///////////////
/////////////////////////////////////////////////////
void MainWindow::clear()
{
   ui ->line_command ->clear();
}


/////////////////////////////////////////////////////
/////////////////// Przycisk delete /////////////////
/////////////////////////////////////////////////////
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event ->key() == Qt::Key_Delete)
    {
        ui ->line_command ->clear();
    }
}

void MainWindow::on_actionMenu_triggered()
{
    podmenu = "menu";
    menu();
}
