#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
  ifstream in("../ciagi.txt");
  ofstream out("../wynik1.txt", ofstream::app);
  int ciag[1000];
  int ile_arytm = 0;
  int max_roznica = 0;
  for (int i = 0; i < 100; i++) //* chodzenie po ciągach
  {
    int dlugosc = 0;
    in >> dlugosc;
    for (int j = 0; j < dlugosc; j++) //* Przypisywanie ciągu do tablicy
    {
      in >> ciag[j];
    }
    int roznica = ciag[1] - ciag[0];
    bool czy_arytm = true;
    for (int j = 0; j + 1 < dlugosc; j++)
    {
      if (ciag[j + 1] - ciag[j] != roznica) //* Warunek czy arytmetyczny
      {
        czy_arytm = false;
        break;
      }
    }
    if (czy_arytm)
    {
      ile_arytm++;
      if (roznica > max_roznica)
      {
        max_roznica = roznica;
      }
    }
  }
  in.close();
  out << "Ilosc ciagow: " << ile_arytm << endl
      << "maxroznica: " << max_roznica << endl;
  out.close();
  system("pause");

  return 0;
}
