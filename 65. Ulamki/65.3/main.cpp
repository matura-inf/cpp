#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int nwd(int x, int y)
{
  if (x < y)
  {
    return nwd(y, x);
  }
  if (y == 0)
  {
    return x;
  }
  return nwd(y, x % y);
}

int main()
{
  ifstream in("../dane_ulamki.txt");
  ofstream out("../wyniki_ulamki.txt", ofstream::app);
  int licznik, mianownik, suma = 0;
  while (in >> licznik >> mianownik)
  {
    if (nwd(licznik, mianownik) == 1)
      suma += licznik;
    else
      suma += licznik / nwd(licznik, mianownik);
  }
  out << endl
      << endl
      << "Zad3" << endl;
  out << suma << endl;
  in.close();
  out.close();
  system("pause");
  return 0;
}
