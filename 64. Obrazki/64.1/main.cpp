#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream in("../dane_obrazki.txt");
  ofstream out("../wyniki_obrazki.txt", ofstream::app);
  string obrazek[21];
  string sam_obrazek[20];
  int ilosc_pixeli;
  int ilosc_obrazkow = 0;
  int najwieksza = 0;

  for (int i = 0; i < 200; i++)
  {
    ilosc_pixeli = 0;
    for (int j = 0; j < 21; j++)
    {
      in >> obrazek[j];
      if (j != 20)
      {
        sam_obrazek[j] = obrazek[j].substr(0, 20);
        string linia = sam_obrazek[j];
        for (int k = 0; k < 20; k++)
        {
          if (linia[k] == '1')
          {
            ilosc_pixeli++;
          }
        }
      }
    }
    if (ilosc_pixeli > 200)
    {
      ilosc_obrazkow++;
      if (ilosc_pixeli > najwieksza)
        najwieksza = ilosc_pixeli;
    }
  }
  out << "Zad1" << endl;
  out << "Ilosc obrazkow: " << ilosc_obrazkow << endl;
  out << "Najwieksza ilosc pixeli: " << najwieksza << endl;

  in.close();
  out.close();
  system("pause");
  return 0;
}