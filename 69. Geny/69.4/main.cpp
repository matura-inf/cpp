#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

bool czy_palindrom(string tab)
{
  int i = 0, j = tab.length() - 1;
  while (i < j)
  {
    if (tab[i] != tab[j])
      return false;
    ++i;
    --j;
  }
  return true;
}

bool czy_gen(string linia, string odwr_linia)
{
  regex wzorzec(".*AA.*BB.*");

  int ostatnie_A = linia.find("AA");
  int ostatnie_B = linia.find("BB");
  if (ostatnie_A > ostatnie_B)
    ostatnie_B = (linia.substr(ostatnie_A)).find("BB") + ostatnie_A;
  string do_sprawdzenia;
  string odciete = linia.substr(0);
  while (odciete.find("BB") != -1 || odciete.find("AA") != -1)
  {
    if (ostatnie_A > ostatnie_B)
      ostatnie_B = (odciete.substr(ostatnie_A)).find("BB") + ostatnie_A;
    smatch wynik;
    string tekst = odciete.substr(ostatnie_A, ostatnie_B - ostatnie_A + 2);
    if (regex_search(tekst, wynik, wzorzec))
      do_sprawdzenia += odciete.substr(ostatnie_A, ostatnie_B - ostatnie_A + 2);
    odciete = odciete.substr(ostatnie_B);
    if (odciete.find("BB") == -1 || odciete.find("AA") == -1)
      break;
    ostatnie_A = odciete.find("AA");
    ostatnie_B = odciete.find("BB");
  }

  int ostatnie_A_o = odwr_linia.find("AA");
  int ostatnie_B_o = odwr_linia.find("BB");
  if (ostatnie_A_o > ostatnie_B_o)
    ostatnie_B_o = (odwr_linia.substr(ostatnie_A_o)).find("BB") + ostatnie_A_o;
  string do_sprawdzenia_o;
  string odciete_o = odwr_linia.substr(0);
  while (odciete_o.find("BB") != -1 || odciete_o.find("AA") != -1)
  {
    if (ostatnie_A_o > ostatnie_B_o)
      ostatnie_B_o = (odciete_o.substr(ostatnie_A_o)).find("BB") + ostatnie_A_o;
    smatch wynik_o;
    string tekst_o = odciete_o.substr(ostatnie_A_o, ostatnie_B_o - ostatnie_A_o + 2);
    if (regex_search(tekst_o, wynik_o, wzorzec))
      do_sprawdzenia_o += odciete_o.substr(ostatnie_A_o, ostatnie_B_o - ostatnie_A_o + 2);
    odciete_o = odciete_o.substr(ostatnie_B_o);
    if (odciete_o.find("BB") == -1 || odciete_o.find("AA") == -1)
      break;
    ostatnie_A_o = odciete_o.find("AA");
    ostatnie_B_o = odciete_o.find("BB");
  }

  if (do_sprawdzenia == do_sprawdzenia_o)
    return true;

  else
    return false;
}

int main()
{
  int silnie_odp = 0;
  int odp = 0;
  ifstream in("../dane_geny.txt");
  ofstream out("../wyniki_geny.txt", ofstream::app);
  for (int i = 0; i < 1000; i++)
  {
    string linia;
    string odwr_linia;
    in >> linia;
    /* !!! Wg nas takie rozwiązanie jest poprawniejsze - odporne osobno i silnie odporne osobno !!!*/
    // if (czy_palindrom(linia))
    //   silnie_odp++;
    // else
    // {
    //   for (int i = linia.length() - 1; i >= 0; i--)
    //     odwr_linia += linia[i];
    //   if (czy_gen(linia, odwr_linia))
    //     odp++;
    // }

    /* !!! Wg CKE takie rozwiązanie jest poprawne - silnie odporne także wliczone do odpornych !!!*/
    if (czy_palindrom(linia))
      silnie_odp++;
    for (int i = linia.length() - 1; i >= 0; i--)
      odwr_linia += linia[i];
    if (czy_gen(linia, odwr_linia))
      odp++;
  }
  out << endl;
  out << "Zad4" << endl;
  out << "Odpornych: " << odp << endl;
  out << "Silnie odpornych: " << silnie_odp;

  in.close();
  out.close();
  system("pause");
  return 0;
}