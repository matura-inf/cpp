#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream in("../liczby2.txt");
  ofstream out("../wyniki.txt", ofstream::app);

  int liczba_d = 0;
  string s_liczba_d;
  int ilosc_d = 0;
  int liczba_o = 0;
  string s_liczba_o;
  int ilosc_o = 0;

  for (int i = 0; i < 1000; i++)
  {
    in >> liczba_d;
    s_liczba_d = to_string(liczba_d);
    for (int i = 0; i < s_liczba_d.length(); i++)
    {
      if (s_liczba_d[i] == '6')
      {
        ilosc_d++;
      }
    }

    int placeValue = 1;
    liczba_o = 0;
    while (liczba_d != 0)
    {
      liczba_o += (liczba_d % 8) * placeValue;
      liczba_d /= 8;
      placeValue *= 10;
    }

    s_liczba_o = to_string(liczba_o);
    for (int i = 0; i < s_liczba_o.length(); i++)
    {
      if (s_liczba_o[i] == '6')
      {
        ilosc_o++;
      }
    }
  }
  in.close();

  out << endl
      << endl
      << "Zad4:" << endl;
  out << "Ilosc szostek dziesietnie: " << ilosc_d << ", ilosc szostek osemkowo: " << ilosc_o;

  out.close();
  system("pause");
  return 0;
}