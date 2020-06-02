#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>

#include "pionki.h"
#include "plansza.h"
#include "pion.h"
#include "wieza.h"
#include "kon.h"
#include "goniec.h"
#include "krolowa.h"
#include "krol.h"
#include "pionki.h"
#include "plansza.h"

using namespace std;



CPlansza :: CPlansza ( )
{

    for (int i=2; i<6; i++)
        for (int j=0; j<8; j++)
        {
            tab[i][j]=nullptr;
        }

    tab[0][0]=new CWieza(false, "B_r", this);
    tab[0][7]=new CWieza(false, "B_r", this);
    tab[0][1]=new CKon(false, "B_k", this);
    tab[0][6]=new CKon(false, "B_k", this);
    tab[0][2]=new CGoniec(false, "B_b", this);
    tab[0][5]=new CGoniec(false, "B_b", this);
    tab[0][3]=new CKrolowa(false, "B_Q", this);
    tab[0][4]=new CKrol(false, "B_K", this);

    for (int j=0; j<8; j++)
    {
        int i=1;
        tab[i][j]=new CPion(0, "B_p", this);
    }

    for (int j=0; j<8; j++)
    {
        int i=6;
        tab[i][j]=new CPion(1, "W_p", this);
    }

    tab[7][0]=new CWieza(true, "W_r", this);
    tab[7][7]=new CWieza(true, "W_r", this);
    tab[7][1]=new CKon(true, "W_k", this);
    tab[7][6]=new CKon(true, "W_k", this);
    tab[7][2]=new CGoniec(true, "W_b", this);
    tab[7][5]=new CGoniec(true, "W_b", this);
    tab[7][3]=new CKrolowa(true, "W_Q", this);
    tab[7][4]=new CKrol(true, "W_K", this);

}

CPlansza :: ~CPlansza ()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {

            if(tab[i][j] !=nullptr)
                delete tab[i][j];
        }

    }

}

void CPlansza :: wyswietl_plansze( )
{
    string tab_plansza[19][27];


    for (int i=2; i<19; i+=2)
        for (int j=0; j<27; j+=3)
            tab_plansza[i][j]="I_";

    for (int i=0; i<1; i+=2)
        for (int j=0; j<27; j+=3)
            tab_plansza[i][j]=" _";

    for (int i=0; i<19; i+=2)
        for (int j=1; j<27; j+=3)
            tab_plansza[i][j]="___";

    for (int i=0; i<19; i+=2)
        for (int j=2; j<27; j+=3)
            tab_plansza[i][j]="_ ";

    for (int i=1; i<19; i+=2)
        for (int j=0; j<27; j+=3)
            tab_plansza[i][j]="I ";

    for (int i=1; i<19; i+=2)
        for (int j=2; j<27; j+=3)
            tab_plansza[i][j]="  ";
    for (int i=1; i<19; i+=2)
        for (int j=26; j<27; j+=3)
            tab_plansza[i][j]=" I";

    for (int i=2; i<19; i+=2)
        for (int j=26; j<27; j+=3)
            tab_plansza[i][j]="_I";

    tab_plansza[1][1]="   ";
    tab_plansza[1][4]=" A ";
    tab_plansza[1][7]=" B ";
    tab_plansza[1][10]=" C ";
    tab_plansza[1][13]=" D ";
    tab_plansza[1][16]=" E ";
    tab_plansza[1][19]=" F ";
    tab_plansza[1][22]=" G ";
    tab_plansza[1][25]=" H ";

    tab_plansza[3][1]=" 1 ";
    tab_plansza[5][1]=" 2 ";
    tab_plansza[7][1]=" 3 ";
    tab_plansza[9][1]=" 4 ";
    tab_plansza[11][1]=" 5 ";
    tab_plansza[13][1]=" 6 ";
    tab_plansza[15][1]=" 7 ";
    tab_plansza[17][1]=" 8 ";

    int n=5;
    int m=4;
    string nazwa;

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {

            if(tab[i][j]==nullptr)
                tab_plansza[n][m]="   ";
            else
            {
                nazwa=tab[i][j]->pobierz_nazwe();
                tab_plansza[n][m]=nazwa;
            }
            m+=3;
        }

        n+=2;

    }


    for (int i=0; i<19; i++)
       { cout<<endl;
        for(int j=0; j<27; j++)
            cout << tab_plansza[i][j];
    }



    cout<<endl<<endl;

}

CPionek* CPlansza ::zwroc_pionek(int x, int y)
{
   return tab[x][y];
}

bool CPlansza ::czy_poprawny (int rzad_teraz, int rzad_potem, int kol_teraz, int kol_potem)
{
    if(!(rzad_teraz==rzad_potem && kol_teraz==kol_potem))
    {
        if ((rzad_teraz>0 && rzad_teraz<9)&&(kol_teraz>0 && kol_teraz<9)&&(rzad_potem>0 && rzad_potem<9)&&(kol_potem>0 && kol_potem<9))
        {
            if (tab[rzad_teraz][kol_teraz]->sprawdz(rzad_teraz, kol_teraz, rzad_potem, kol_potem) == true)
            {
                if (tab[rzad_potem][kol_potem] !=nullptr)
                   delete tab[rzad_potem][kol_potem];
                tab[rzad_potem][kol_potem]=tab[rzad_teraz][kol_teraz];
                tab[rzad_teraz][kol_teraz]=nullptr;
                return true;
            }
            else
            {
                cout<<"Ruch niepoprawny"<<endl;
                return false;
            }

        }
        else
        {
            cout<<"Ruch niepoprawny"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Ruch niepoprawny"<<endl;
        return false;
    }
}

void CPlansza ::zamiana_piona(int rzad_potem, int kol_potem)
{
    if ((tab[rzad_potem][kol_potem]->pobierz_nazwe())=="W_p" || (tab[rzad_potem][kol_potem]->pobierz_nazwe()=="B_p"))
    {
        int wybor_do_zamiany;
        cout<<"Wybierz na jakiego pionka chcesz zamienic piona"<<endl;
        cout<<"r-1,  k-2,  b-3,   Q-4,  K-5, wpisz odpowiedni nr"<<endl;
        cin>>wybor_do_zamiany;
        while(wybor_do_zamiany<0 || wybor_do_zamiany>5)
        {
            cout<<"r-1,  k-2,  b-3,   Q-4,  K-5, wpisz odpowiedni nr"<<endl;
            cin>>wybor_do_zamiany;
        }

        switch (wybor_do_zamiany)
        {
        case 1:
            tab[rzad_potem][kol_potem]->~CPionek();
            if(rzad_potem==0)
            tab[rzad_potem][kol_potem]=new CWieza(false, "B_r", this);
            else
              tab[rzad_potem][kol_potem]=new CWieza(true, "W_r", this);
            break;

        case 2:
            tab[rzad_potem][kol_potem]->~CPionek();
            if(rzad_potem==0)
            tab[rzad_potem][kol_potem]=new CKon(false, "B_k", this);
            else
              tab[rzad_potem][kol_potem]=new CKon(true, "W_k", this);
            break;

        case 3:
            tab[rzad_potem][kol_potem]->~CPionek();
            if(rzad_potem==0)
            tab[rzad_potem][kol_potem]=new CGoniec(false, "B_b", this);
            else
              tab[rzad_potem][kol_potem]=new CGoniec(true, "W_b", this);
            break;

        case 4:
            tab[rzad_potem][kol_potem]->~CPionek();
            if(rzad_potem==0)
            tab[rzad_potem][kol_potem]=new CKrolowa(false, "B_Q", this);
            else
              tab[rzad_potem][kol_potem]=new CKrolowa(true, "W_Q", this);
            break;

        case 5:
            tab[rzad_potem][kol_potem]->~CPionek();
            if(rzad_potem==0)
            tab[rzad_potem][kol_potem]=new CKrol(false, "B_K", this);
            else
              tab[rzad_potem][kol_potem]=new CKrol(true, "W_K", this);
            break;

        }
    }
}

bool CPlansza::roszada(int rzad_wiezy, int kol_wiezy)
{
    if(tab[rzad_wiezy][kol_wiezy]!=nullptr)
    {
        if(tab[rzad_wiezy][kol_wiezy]->zdobadz_kolor()==true)
        {
            if((rzad_wiezy==7)&&((kol_wiezy==0)||(kol_wiezy==7)))
            {
                if((tab[rzad_wiezy][kol_wiezy]->pobierz_nazwe()=="W_r")&&(tab[7][4]->pobierz_nazwe()=="W_K"))
                {
                    if(kol_wiezy==7)
                    {
                        if(tab[rzad_wiezy][5]==nullptr && tab[rzad_wiezy][6]==nullptr)
                        {
                            tab[rzad_wiezy][5]=tab[rzad_wiezy][kol_wiezy];
                            tab[rzad_wiezy][kol_wiezy]=nullptr;
                            tab[rzad_wiezy][6]=tab[rzad_wiezy][4];
                            tab[rzad_wiezy][4]=nullptr;
                            return true;
                        }
                        else
                        {
                            cout<<"Roszada niedozwolona";
                            return false;
                        }
                    }
                    else
                        if (kol_wiezy==0)
                        {
                            if(tab[rzad_wiezy][1]==nullptr && tab[rzad_wiezy][2]==nullptr && tab[rzad_wiezy][3]==nullptr)
                            {
                                tab[rzad_wiezy][3]=tab[rzad_wiezy][kol_wiezy];
                                tab[rzad_wiezy][kol_wiezy]=nullptr;
                                tab[rzad_wiezy][2]=tab[rzad_wiezy][4];
                                tab[rzad_wiezy][4]=nullptr;
                                return true;
                            }
                            else
                            {
                                cout<<"Roszada niedozwolona";
                                return false;
                            }
                        }
                }
                else
                {
                    cout<<"Roszada niedozwolona";
                    return false;
                }

            }
            else
            {
                cout<<"Roszada niedozwolona";
                return false;
            }
        }
        else
        {
            if (tab[rzad_wiezy][kol_wiezy]->zdobadz_kolor()==false)
            {
                if((rzad_wiezy==0)&&((kol_wiezy==0)||(kol_wiezy==7)))
                {
                    if((tab[rzad_wiezy][kol_wiezy]->pobierz_nazwe()=="B_r")&&(tab[0][4]->pobierz_nazwe()=="B_K"))
                    {
                        if(kol_wiezy==7)
                        {
                            if(tab[rzad_wiezy][5]==nullptr && tab[rzad_wiezy][6]==nullptr)
                            {
                                tab[rzad_wiezy][5]=tab[rzad_wiezy][kol_wiezy];
                                tab[rzad_wiezy][kol_wiezy]=nullptr;
                                tab[rzad_wiezy][6]=tab[rzad_wiezy][4];
                                tab[rzad_wiezy][4]=nullptr;
                                return true;
                            }
                            else
                            {
                                cout<<"Roszada niedozwolona";
                                return false;
                            }
                        }
                        else
                            if (kol_wiezy==0)
                            {
                                if(tab[rzad_wiezy][1]==nullptr && tab[rzad_wiezy][2]==nullptr && tab[rzad_wiezy][3]==nullptr)
                                {
                                    tab[rzad_wiezy][3]=tab[rzad_wiezy][kol_wiezy];
                                    tab[rzad_wiezy][kol_wiezy]=nullptr;
                                    tab[rzad_wiezy][2]=tab[rzad_wiezy][4];
                                    tab[rzad_wiezy][4]=nullptr;
                                    return true;
                                }
                                else
                                {
                                    cout<<"Roszada niedozwolona";
                                    return false;
                                }
                            }
                    }
                    else
                    {
                        cout<<"Roszada niedozwolona";
                        return false;
                    }
                }
                else
                {
                    cout<<"Roszada niedozwolona";
                    return false;
                }
            }
        }
    }
    else
    {
        cout<<"Roszada niedozwolona"<<endl;
        return false;
    }
}

bool CPlansza::zapisz_do_pliku(string nazwa_pliku)
{
  ofstream plik;
  plik.open(nazwa_pliku, ios::app);
  if (plik.is_open()==false)
  {
      cout<<"Błąd otwarcia pliku";
      return false;
  }

  for (int i=0; i<8; i++)
      for (int j=0; j<8; j++)
      {
          if (tab[i][j]==nullptr)
              plik<<"0"<<endl;
          else
              plik<<tab[i][j]->pobierz_nazwe()<<endl;
      }

  plik.close();

  return true;
}

bool CPlansza::wczytaj_gre(string nazwa_pliku)
{
    string linia;

    ifstream plik;
    plik.open(nazwa_pliku, ios::app);
    if (plik.is_open()==false)
    {
        cout<<"Błąd otwarcia pliku";
        return false;
    }

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            getline (plik, linia);

            if (linia=="W_p")
                tab[i][j]=new CPion (true, linia, this);
            else
                if (linia=="B_p")
                    tab[i][j]=new CPion (false, linia, this);
                else
                    if (linia=="W_k")
                        tab[i][j]=new CKon (true, linia, this);
                    else
                        if (linia=="B_k")
                            tab[i][j]=new CKon (false, linia, this);
                        else
                            if (linia=="W_r")
                                tab[i][j]=new CWieza (true, linia, this);
                            else
                                if (linia=="B_r")
                                    tab[i][j]=new CWieza (false, linia, this);
                                else
                                    if (linia=="W_b")
                                        tab[i][j]=new CGoniec (true, linia, this);
                                    else
                                        if (linia=="B_b")
                                            tab[i][j]=new CGoniec (false, linia, this);
                                        else
                                            if (linia=="W_Q")
                                                tab[i][j]=new CKrolowa (true, linia, this);
                                            else
                                                if(linia=="B_Q")
                                                    tab[i][j]=new CKrolowa (false, linia, this);
                                                else
                                                    if (linia=="W_K")
                                                        tab[i][j]=new CKrol (true, linia, this);
                                                    else
                                                        if (linia=="B_K")
                                                            tab[i][j]=new CKrol (false, linia, this);
                                                        else
                                                            if (linia=="0")
                                                                tab[i][j]=nullptr;
                                                            else
                                                                return false;


        }
    }
    return true;

}

