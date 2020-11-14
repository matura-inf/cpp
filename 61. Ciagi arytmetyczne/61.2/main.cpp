#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream in("../ciagi.txt");
  ofstream out("../wynik2.txt", ofstream::app);
  int ciag[1000];
  int najwieksza;
  for (int i = 0; i < 100; i++)
  {
    int dlugosc = 0;
    in >> dlugosc;
    for (int j = 0; j < dlugosc; j++)
    {
      in >> ciag[j];
    }

    for (int j = 0; j < dlugosc; j++)
    {
      float liczba_f;
      liczba_f = pow(ciag[j], 1.0 / 3.0);
      int liczba_i = (int)liczba_f;

      if (liczba_f == liczba_i)
      {
        najwieksza = ciag[j];
        if (ciag[j] > najwieksza)
        {
          najwieksza = ciag[j];
        }
      }
    }
    for (int j = 0; j < dlugosc; j++)
    {
      float liczba_f;
      liczba_f = pow(ciag[j], 1.0 / 3.0);
      int liczba_i = (int)liczba_f;

      if (liczba_f == liczba_i)
      {
        if (najwieksza == ciag[j])
        {
          out << najwieksza << endl;
        }
      }
    }
  }
  in.close();
  out.close();
  system("pause");
  return 0;
}