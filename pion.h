#ifndef PION_H
#define PION_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CPion : public CPionek
{

public:
    CPion (bool, string, CPlansza*);
    ~CPion();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
