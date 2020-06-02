#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <string>

#include "pionki.h"
#include "wieza.h"
#include "plansza.h"


CWieza :: CWieza (bool k, string n, CPlansza *p) : CPionek(p)
{
    kolor=k;
    nazwa_pionka=n;
}

CWieza :: ~CWieza ()
{
    cout<<"Zbito wieze"<<endl;
}

bool CWieza :: sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem)
{
    CPionek* ter;
    CPionek* pot;
    ter=plansza->zwroc_pionek(rzad_teraz, kol_teraz);
    pot=ter=plansza->zwroc_pionek(rzad_potem, kol_potem);
    if((pot==nullptr) || (ter->zdobadz_kolor() != pot->zdobadz_kolor()))
    {
        if(abs(kol_potem-kol_teraz)==0 || abs(rzad_potem-rzad_teraz)==0)
        {
            delete ter;
            delete pot;
            return true;
        }
        else
        {
            delete ter;
            delete pot;
            return false;
        }
    }
    else
    {
        delete ter;
        delete pot;
        return false;
    }
}
