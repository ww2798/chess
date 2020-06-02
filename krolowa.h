#ifndef KROLOWA_H
#define KROLOWA_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CKrolowa : public CPionek
{

public:
    CKrolowa (bool, string, CPlansza *p);
    ~CKrolowa();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
