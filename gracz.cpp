#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include "pionki.h"
#include "plansza.h"
#include "gracz.h"


using namespace std;


CGracz :: CGracz (bool k, string nazwa)
{
    kolor_gracza=k;
    nazwa_gracza=nazwa;

}

CGracz :: ~CGracz ()
{
    cout<<"Usunięto gracza"<<endl;
}

void CGracz ::nazwij_gracza()
{
    cout<<"Jak chcesz sie nazywac"<<endl;
    string n;
    cin>>n;
    nazwa_gracza=n;
}

bool CGracz ::zwroc_kolor()
{
    return kolor_gracza;
}

string CGracz :: zwroc_nazwe_gracza()
{
    return nazwa_gracza;
}

void CGracz ::wykonaj_ruch(int &rzad_teraz, int &kol_teraz, int &rzad_potem, int &kol_potem)
{
    char lit_t;
    char lit_p;
    char nr_t;
    char nr_p;

    cout<<"Wpisz pole pionka którym chcesz ruszyc, np E (enter) 4 (enter)"<<endl;
    cin>>lit_t;
    cin>>nr_t;

    cout<<"Wpisz pole, na którym chcesz postawic pionek, np E (enter) 4 (enter)"<<endl;
    cin>>lit_p;
    cin>>nr_p;

    rzad_teraz=nr_t-'0';
    kol_teraz=lit_t-'A';

    rzad_potem=nr_p-'0';
    kol_potem=lit_p-'A';

}

void CGracz::chce_roszade(int &rzad_wiezy, int &kol_wiezy)
{
    char lit_w;
    char nr_w;

    cout<<"Wpisz pole wiezy ktora chcesz wykonac roszade , np E (enter) 4 (enter)"<<endl;
    cin>>lit_w;
    cin>>nr_w;

    rzad_wiezy=nr_w-'0';
    kol_wiezy=lit_w-'A';
}


bool CGracz::zapisz_do_pliku(string nazwa_pliku)
{
  ofstream plik;
  plik.open(nazwa_pliku, ios::app);
  if (plik.is_open()==false)
  {
      cout<<"Błąd otwarcia pliku";
      return false;
  }

  if(kolor_gracza==true)
  {
      plik<<"1"<<endl;
  }
  else
  {
      plik<<"0"<<endl;
  }
  plik<<nazwa_gracza<<endl;

  plik.close();

  return true;
}

bool CGracz::wczytaj_gracza(string nazwa_pliku)
{
    ifstream plik;
    plik.open(nazwa_pliku, ios::app);
    if (plik.is_open()==false)
    {
        cout<<"Błąd otwarcia pliku";
        return false;
    }

    string linia;
    getline (plik, linia);

    if(linia=="0")
    {
        getline (plik, linia);
        kolor_gracza=false;
        nazwa_gracza=linia;
    }
    else
    {
        kolor_gracza=true;
        nazwa_gracza=linia;
    }
    plik.close();
    return true;
}
