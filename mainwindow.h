#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>



namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /////////////////////////////////////////////////////
    ////////////////////// KOMENDY //////////////////////
    /////////////////////////////////////////////////////

    /////////////////////// MENU ////////////////////////



private slots:
    void on_line_command_returnPressed();

    void on_actionWyjscie_triggered();

    void on_actionNowa_gra_triggered();

    void on_actionZapisz_gre_triggered();

    void on_actionWczytaj_gre_triggered();

    void on_actionMenu_triggered();

protected:
    Ui::MainWindow *ui;

    QString podmenu;

    QGraphicsScene *scene;
    QGraphicsRectItem *pasek_bohatera;
    QGraphicsRectItem *pasek_bohatera_max;
    QGraphicsRectItem *pasek_bohatera_mana;
    QGraphicsRectItem *pasek_bohatera_mana_max;

    QGraphicsRectItem *pasek_wroga;
    QGraphicsRectItem *pasek_wroga_max;
    QGraphicsRectItem *pasek_wroga_mana;
    QGraphicsRectItem *pasek_wroga_mana_max;

    QGraphicsRectItem *biala_plansza;



    void menu();
    void o_grze();
    void clear();
    void nowa_gra();
    void wybor_gildii();
    void przejscie_do_losowania();
    void losowanie_przeciwnika();
    void walka();
    void przeciwnika_tura();
    void zmiana_tury_tohero();
    void zmiana_tury_toenemy();
    void wygrana();
    void przegrana();
    void przejscie_do_kolejnego_losowania();
    void kolejne_losowanie();
    void write(QString aktualny_stan);
    void read(QString Filename);
    void wyswietl_paski_wroga();
    void wyswietl_paski_bohatera();
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
