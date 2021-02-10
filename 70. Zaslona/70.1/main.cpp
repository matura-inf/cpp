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

double pole()
{
  double pfgora, pfdol, pf;
  double pggora, pgdol, pg;
  double p;
  double h, x;
  int n = 10;

  do
  {
    h = 8.0 / n;
    x = 2;
    pfdol = 0;
    pfgora = 0;
    for (int i = 0; i < n; i++)
    {
      pfdol += f(x);
      x += h;
      pfgora += f(x);
    }
    pfdol *= h;
    pfgora *= h;
    n *= 2;
  } while (pfgora - pfdol > 0.001 / 2);
  pf = (pfdol + pfgora) / 2;

  n = 10;
  do
  {
    h = 8.0 / n;
    x = 2;
    pgdol = 0;
    pggora = 0;
    for (int i = 0; i < n; i++)
    {
      pgdol -= g(x);
      x += h;
      pggora -= g(x);
    }
    pgdol *= h;
    pggora *= h;
    n *= 2;
  } while (pggora - pgdol > 0.001 / 2);
  pg = (pgdol + pggora) / 2;

  p = pf + pg;
  return (p);
}

int main()
{
  ofstream out("../wyniki_zaslona.txt", ofstream::app);
  out << "Zad1" << endl;
  out << "Pozostalo: " << pole()
      << endl
      << endl;
  out.close();
  system("pause");
  return 0;
}