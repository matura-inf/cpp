#include <iostream>
#include <fstream>
using namespace std;

bool czy_pierwsza(int n)
{
  if (n < 2)
    return false;

  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main()
{
  ifstream in("../ciagi.txt");
  ofstream out("../wyniki_ciagi.txt", ofstream::app);

  string ciagi[1000];
  int ile = 0;
  int najwieksza = 0;
  int najmniejsza = 9999999;
  for (int i = 0; i < 1000; i++)
  {
    float dziesietna = 0;
    in >> ciagi[i];
    string element = ciagi[i];
    for (int j = 0; j < element.length(); j++)
    {
      if (element[j] == '1')
        dziesietna = dziesietna * 2 + 1;
      else
        dziesietna *= 2;
    }
    int inkrementator_pierwszych = 2;
    for (int j = 0; j < dziesietna; j++)
    {
      if (czy_pierwsza(inkrementator_pierwszych))
      {
        if (inkrementator_pierwszych > dziesietna)
          break;
        bool wynik_pierwszenstwa = czy_pierwsza(dziesietna / inkrementator_pierwszych);
        if ((dziesietna / inkrementator_pierwszych) != (int)(dziesietna / inkrementator_pierwszych))
        {
          inkrementator_pierwszych++;
          continue;
        }
        if (wynik_pierwszenstwa)
        {
          if (dziesietna >= najwieksza)
            najwieksza = dziesietna;
          else if (dziesietna <= najmniejsza)
            najmniejsza = dziesietna;

          ile++;
          break;
        }
      }
      else
        j--;
      inkrementator_pierwszych++;
    }
  }
  out << endl
      << endl
      << "Zad3" << endl;
  out << "Ile: " << ile << endl;
  out << "Najwieksza: " << najwieksza << endl;
  out << "Najmniejsza: " << najmniejsza;
  in.close();
  out.close();
  system("pause");
  return 0;
}
