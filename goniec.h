#ifndef GONIEC_H
#define GONIEC_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CGoniec : public CPionek
{

public:
    CGoniec (bool, string, CPlansza*);
    ~CGoniec();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
