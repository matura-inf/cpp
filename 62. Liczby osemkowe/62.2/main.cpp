#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream in("../liczby2.txt");
  ofstream out("../wyniki.txt", ofstream::app);
  int liczba = 0;
  int stara_liczba = 0;
  int dlugosc = 0;
  int max_dlugosc, pierwszy, max_pierwszy;

  int i = 0;
  for (int j = 0; j < 1000; j++)
  {
    in >> liczba;

    if (liczba >= stara_liczba)
      dlugosc++;
    else
    {
      pierwszy = liczba;
      dlugosc = 1;
    }

    if (dlugosc > max_dlugosc)
    {
      max_dlugosc = dlugosc;
      max_pierwszy = pierwszy;
    }
    stara_liczba = liczba;
  }
  out << endl
      << endl
      << "Zad2:" << endl;
  out << "Najwieksza pierwsza: " << max_pierwszy << " dlugosc: " << max_dlugosc;

  in.close();
  out.close();
  system("pause");
  return 0;
}
