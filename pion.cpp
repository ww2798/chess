#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <string>

#include "pionki.h"
#include "pion.h"
#include "plansza.h"

CPion::CPion (bool k, string n, CPlansza *p) : CPionek(p)
{
    kolor=k;
    nazwa_pionka=n;
}

CPion ::~CPion ()
{
    cout<<"Zbito piona"<<endl;
}

bool CPion :: sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem)
{
    CPionek* ter;
    CPionek* pot;
    ter=plansza->zwroc_pionek(rzad_teraz, kol_teraz);
    pot=ter=plansza->zwroc_pionek(rzad_potem, kol_potem);
    if (ter->zdobadz_kolor()==true)
    {
        if (pot==nullptr)
        {
            if (kol_potem==kol_teraz && rzad_potem==rzad_teraz-1)
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
            if(ter->zdobadz_kolor() != pot->zdobadz_kolor() )
            {
                if (rzad_potem==rzad_teraz-1 && (kol_potem==kol_teraz+1 || kol_potem==kol_teraz-1))
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
    else
        if (ter->zdobadz_kolor()==false)
        {
            if (pot==nullptr)
            {
                if (kol_potem==kol_teraz && rzad_potem==rzad_teraz+1)
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
                if(ter->zdobadz_kolor() != pot->zdobadz_kolor() )
                {
                    if (rzad_potem==rzad_teraz+1 && (kol_potem==kol_teraz+1 || kol_potem==kol_teraz-1))
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


}
