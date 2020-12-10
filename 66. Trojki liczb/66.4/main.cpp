#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream in("../trojki.txt");
  ofstream out("../wyniki_trojki.txt", ofstream::app);
  int pierwsza, druga, trzecia, ilosc = 0, seria = 0, max_seria = 0;
  while (in >> pierwsza >> druga >> trzecia)
  {
    if ((pierwsza + druga > trzecia) && (pierwsza + trzecia > druga) && (druga + trzecia > pierwsza))
    {
      ilosc++;
      seria++;
    }
    else
      seria = 0;
    if (max_seria < seria)
      max_seria = seria;
  }
  out << endl
      << "Zad4" << endl
      << endl;
  out << "Ilosc wierszy trojkatnych: " << ilosc << endl;
  out << "Najdluzszy ciag trojkatny: " << max_seria << endl;

  in.close();
  out.close();
  system("pause");

  return 0;
}
