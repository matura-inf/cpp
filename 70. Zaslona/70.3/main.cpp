#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x)
{
  return (pow(x, 4) / 500 - pow(x, 2) / 200 - 0.012);
}

double g(double x)
{
  return (-pow(x, 3) / 30 + x / 20 + 1.0 / 6);
}

double dlugosc()
{
  double dl = 0;
  for (double x = 9.75; x > 2; x -= 0.25)
    dl += floor(f(x) - g(x));
  return dl;
}

int main()
{
  ofstream out("../wyniki_zaslona.txt", ofstream::app);
  out << "Zad3" << endl;
  out << "Suma dlugosci pasow: " << dlugosc();
  out.close();
  system("pause");
  return 0;
}