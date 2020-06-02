#ifndef WIEZA_H
#define WIEZA_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CWieza : public CPionek
{

public:
    CWieza (bool, string, CPlansza*);
    ~CWieza();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
