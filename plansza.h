#ifndef PLANSZA_H
#define PLANSZA_H

using namespace std;

class CPionek; 

class CPlansza
{
private:
    CPionek* tab[8][8];

public:

    CPlansza ();
    ~CPlansza ();

   void wyswietl_plansze ();

   CPionek* zwroc_pionek(int x, int y);
   bool czy_poprawny(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
   void zamiana_piona (int rzad_potem, int kol_potem);
   bool roszada (int rzad_wiezy, int kol_wiezy);
   bool zapisz_do_pliku(string nazwa_pliku);
   bool wczytaj_gre (string nazwa_pliku);
};

#endif
