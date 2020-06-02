#ifndef KON_H
#define KON_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CKon : public CPionek
{

public:
    CKon (bool, string, CPlansza*);
    ~CKon();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
