#ifndef KROL_H
#define KROL_H

#include <string>

using namespace std;

class CPionek;

class CPlansza;

class CKrol : public CPionek
{

public:
    CKrol (bool, string, CPlansza*);
    ~CKrol();
    bool sprawdz(int rzad_teraz, int kol_teraz, int rzad_potem, int kol_potem);
};

#endif
