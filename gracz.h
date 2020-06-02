#ifndef GRACZ_H
#define GRACZ_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CGracz
{
    bool kolor_gracza;
    string nazwa_gracza;

public:

    CGracz (bool k, string nazwa);
    ~CGracz ();

    bool zwroc_kolor ();
    string zwroc_nazwe_gracza () ;
    void nazwij_gracza ();

    void wykonaj_ruch(int &rzad_teraz, int &kol_teraz, int &rzad_potem, int &kol_potem);
    void chce_roszade (int &rzad_wiezy, int &kol_wiezy);

    bool zapisz_do_pliku(string nazwa_pliku);
    bool wczytaj_gracza (string nazwa_pliku);
};

#endif
