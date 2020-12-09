#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  ifstream in("../dane_ulamki.txt");
  ofstream out("../wyniki_ulamki.txt", ofstream::app);
  long long b = pow(2, 2) * pow(3, 2) * pow(5, 2) * pow(7, 2) * 13;
  long long licznik, mianownik, suma = 0;
  while (in >> licznik >> mianownik)
    suma += (licznik * b) / mianownik;

  out << endl
      << endl
      << "Zad4" << endl;
  out << suma;

  in.close();
  out.close();
  system("pause");
  return 0;
}
