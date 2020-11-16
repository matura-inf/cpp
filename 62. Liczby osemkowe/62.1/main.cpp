#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in("../liczby1.txt");
  ofstream out("../wyniki.txt", ofstream::app);
  int liczba = 0;
  int min = 999999;
  int max = 0;

  for (int i = 0; i < 1000; i++)
  {
    in >> liczba;
    if (liczba > max)
      max = liczba;

    if (liczba < min)
      min = liczba;
  }
  out << "Zad1:" << endl;
  out << "Min: " << min << ", max: " << max;

  in.close();
  out.close();
  system("pause");
  return 0;
}
