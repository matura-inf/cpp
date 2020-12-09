#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream in("../dane_ulamki.txt");
  ofstream out("../wyniki_ulamki.txt", ofstream::app);

  float licznik, mianownik, iloraz;
  float min_wartosc = 99999;
  float min_mianownik = 99999;
  float p_licznik;

  while (in >> licznik >> mianownik)
  {
    iloraz = licznik / mianownik;
    if (iloraz < min_wartosc)
    {
      min_wartosc = iloraz;
      p_licznik = licznik;
      min_mianownik = mianownik;
    }
    else if (iloraz == min_wartosc)
    {
      if (min_mianownik > mianownik)
      {
        min_mianownik = mianownik;
        p_licznik = licznik;
      }
    }
  }
  out << "Zad1" << endl;
  out << p_licznik << " " << min_mianownik;
  in.close();
  out.close();
  system("pause");

  return 0;
}