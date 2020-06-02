#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <time.h>

#include "pionki.h"
#include "plansza.h"
#include "pion.h"
#include "wieza.h"
#include "kon.h"
#include "goniec.h"
#include "krolowa.h"
#include "krol.h"
#include "pionki.h"
#include "plansza.h"
#include "gracz.h"


int main(int argc, char *argv[])
{
    cout<<"Witaj w obiektowej szachownicy"<<endl;
    int wybor=0;
    while (wybor!=1 && wybor!=2)
    {
        cout<<"Jesli chcesz kontynuowac gre wybierz 1"<<endl;
        cout<<"Jesli chcesz rozpoczac gre wybierz 2"<<endl;
        cin>>wybor;
    }

    CGracz pierwszy(true, "A");
    CGracz drugi(false, "B");
    CPlansza t;

    clock_t start;
    clock_t stop;
    double czas;
    bool koniec = false;

    switch (wybor) {
    case 1: {
        cout<<"Podaj plik, w którym są dane gracza, którego była teraz kolej"<<endl;
        string nazwa_pliku;
        cin>>nazwa_pliku;

        while (pierwszy.wczytaj_gracza(nazwa_pliku)!=true)
        {
            cout<<"Podaj plik, w którym są dane gracza, którego była teraz kolej"<<endl;
            cin>>nazwa_pliku;
        }

        cout<<"Podaj plik, w którym są dane gracza, którego  nie była teraz kolej"<<endl;
        cin>>nazwa_pliku;

        while (drugi.wczytaj_gracza(nazwa_pliku)!=true)
        {
            cout<<"Podaj plik, w którym są dane gracza, którego  nie była teraz kolej"<<endl;
            cin>>nazwa_pliku;
        }

        cout<<"Podaj plik, w którym są dane z ostatniej gry"<<endl;
        cin>>nazwa_pliku;

        while (t.wczytaj_gre(nazwa_pliku)!=true)
        {
            cout<<"Podaj plik, w którym są dane z ostatniej gry"<<endl;
            cin>>nazwa_pliku;
        }

    } break;

    case 2:

        cout<<"Jak nazywa sie gracz, grajacy bialymi?"<<endl;
        pierwszy.nazwij_gracza();

        cout<<"Jak nazywa sie gracz, grajacy czarnymi?"<<endl;
        drugi.nazwij_gracza();


        break;
    default: {

        cout<<"Wystapil blad";
        break;
    }
    }

        cout<<"Czas na gre"<<endl;

        t.wyswietl_plansze();


        while (!koniec)
        {
            cout<<"Kolej: "<<pierwszy.zwroc_nazwe_gracza();

            int w=0;

            while (w!=1 && w!=2)
            {
                cout<<"Jesli chcesz wykonac stnadardowy ruch wybierz 1"<<endl;
                cout<<"Jesli chcesz wykonac roszade lub zapis gry wybierz 2"<<endl;
                cin>>w;
            }


            switch (w) {
            case 1:

                start=clock();

                int rzad_teraz;
                int rzad_potem;
                int kol_teraz;
                int kol_potem;

                pierwszy.wykonaj_ruch(rzad_teraz, kol_teraz, rzad_potem, kol_potem);
                while(t.czy_poprawny(rzad_teraz, kol_teraz, rzad_potem, kol_potem)!=true)
                    pierwszy.wykonaj_ruch(rzad_teraz, kol_teraz, rzad_potem, kol_potem);

                stop=clock();

                t.zamiana_piona(rzad_potem, kol_potem);

                czas=(double)(stop-start) /CLOCKS_PER_SEC;
                cout<<"Czas ruchu: "<<czas<<"s"<<endl;

                system("cls");
                t.wyswietl_plansze();

                break;

            case 2: {

                int dw=0;
                while (dw!=1 && dw!=2 && dw!=3)
                {
                    cout<<"Jesli chcesz roszade - 1"<<endl;
                    cout<<"Przerwanie i zapisanie gry do pliku -2"<<endl;
                    cout<<"Wyjdz bez zapisania - 3"<<endl;
                    cin>>dw;
                }

                switch (dw) {

                case 1:
                    int kol_wiezy, rzad_wiezy;
                    pierwszy.chce_roszade(rzad_wiezy, kol_wiezy);
                    t.roszada(rzad_wiezy, kol_wiezy);

                    system("cls");
                    t.wyswietl_plansze();

                    break;

                case 2: {
                    string nazwa_pliku_gry;
                    string nazwa_pliku_gracza1;
                    string nazwa_pliku_gracza2;

                    cout<<"Podaj nazwe pliku, gdzie bedzie przechowywana plansza"<<endl;
                    cin>>nazwa_pliku_gry;
                    t.zapisz_do_pliku(nazwa_pliku_gry);

                    cout<<"Podaj nazwe oliku, gdzie bedzie przechowywany gracz 1"<<endl;
                    cin>>nazwa_pliku_gracza1;
                    pierwszy.wczytaj_gracza(nazwa_pliku_gracza1);

                    cout<<"Podaj nazwe pliku, gdzie bedzie przechowywany fracz 2"<<endl;
                    cin>>nazwa_pliku_gracza2;
                    drugi.wczytaj_gracza(nazwa_pliku_gracza2);

                    koniec = true;

                    break;
                }

                case 3:

                    koniec=true;
                    break;

                }

            }
            default:

                cout<<"Wystapil blad";
                break;

            }

            cout<<"Kolej: "<<drugi.zwroc_nazwe_gracza();

            w=0;

            while (w!=1 && w!=2)
            {
                cout<<"Jesli chcesz wykonac stnadardowy ruch wybierz 1"<<endl;
                cout<<"Jesli chcesz wykonac roszade lub zapis gry wybierz 2"<<endl;
                cin>>w;
            }


            switch (w) {
            case 1:

                int rzad_teraz;
                int rzad_potem;
                int kol_teraz;
                int kol_potem;

                start=clock();

                drugi.wykonaj_ruch(rzad_teraz, kol_teraz, rzad_potem, kol_potem);
                while(t.czy_poprawny(rzad_teraz, kol_teraz, rzad_potem, kol_potem)!=true)
                    drugi.wykonaj_ruch(rzad_teraz, kol_teraz, rzad_potem, kol_potem);

                stop=clock();

                t.zamiana_piona(rzad_potem, kol_potem);

                czas=(double)(stop-start) /CLOCKS_PER_SEC;
                cout<<"Czas ruchu: "<<czas<<"s"<<endl;

                system("cls");
                t.wyswietl_plansze();

                break;

            case 2:
            {

                int dw=0;
                while (dw!=1 && dw!=2 && dw!=3)
                {
                    cout<<"Jesli chcesz roszade - 1"<<endl;
                    cout<<"Przerwanie i zapisanie gry do pliku -2"<<endl;
                    cout<<"Wyjdz bez zapisania - 3"<<endl;
                    cin>>dw;
                }

                switch (dw) {

                case 1:
                    int kol_wiezy, rzad_wiezy;
                    drugi.chce_roszade(rzad_wiezy, kol_wiezy);
                    t.roszada(rzad_wiezy, kol_wiezy);

                    system("cls");
                    t.wyswietl_plansze();

                    break;

                case 2: {
                    string nazwa_pliku_gry;
                    string nazwa_pliku_gracza1;
                    string nazwa_pliku_gracza2;

                    cout<<"Podaj nazwe pliku, gdzie bedzie przechowywana plansza"<<endl;
                    cin>>nazwa_pliku_gry;
                    t.zapisz_do_pliku(nazwa_pliku_gry);

                    cout<<"Podaj nazwe oliku, gdzie bedzie przechowywany gracz 1"<<endl;
                    cin>>nazwa_pliku_gracza1;
                    pierwszy.wczytaj_gracza(nazwa_pliku_gracza1);

                    cout<<"Podaj nazwe pliku, gdzie bedzie przechowywany fracz 2"<<endl;
                    cin>>nazwa_pliku_gracza2;
                    drugi.wczytaj_gracza(nazwa_pliku_gracza2);

                    koniec=true;
                    break;
                }

                case 3:

                    koniec=true;
                    break;

                }

            }
            default:

                cout<<"Wystapil blad";
                break;

            }
            break;
        }


    return 0;
}

