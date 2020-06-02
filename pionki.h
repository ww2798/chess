#ifndef PIONKI_H
#define PIONKI_H

#include <string>
using namespace std;

class CPlansza;

class CPionek
{
protected:
    CPlansza *plansza = nullptr;
    string nazwa_pionka;
    bool kolor; //białe 1 czarne 0

public:
    CPionek(CPlansza *p) : plansza(p) {}
    virtual ~CPionek() {}
    virtual bool zdobadz_kolor();
    virtual string pobierz_nazwe();
    virtual bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem)=0;
};


#endif

