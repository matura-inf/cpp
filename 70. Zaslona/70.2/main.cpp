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

double obwod()
{
  double h, x;
  double dl_f = 0, dl_g = 0;
  double ob = 8 + 8 + f(10) - g(10);
  h = 8.0 / 1000;
  x = 2;
  for (int i = 0; i < 1000; i++)
  {
    dl_f += sqrt(pow(x - (x + h), 2) + pow(f(x) - f(x + h), 2));
    x += h;
  }

  x = 2;
  for (int i = 0; i < 1000; i++)
  {
    dl_g += sqrt(pow(x - (x + h), 2) + pow(g(x) - g(x + h), 2));
    x += h;
  }

  ob += dl_f + dl_g;
  ob = ceil(ob);
  return ob;
}

int main()
{
  ofstream out("../wyniki_zaslona.txt", ofstream::app);
  out << "Zad2" << endl;
  out << "Ilosc tasmy do kupienia: " << obwod()
      << endl
      << endl;
  out.close();
  system("pause");
  return 0;
}