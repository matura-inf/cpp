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
  string b_dolne[20];
  string b_boczne[20];
  char znak[20][20];
  int suma_obr_wiersz[20];
  int suma_obr_kolumna[20];
  int poprawne = 0;
  int naprawialne = 0;
  int nienaprawialne = 0;
  int max_blednych_bitow = 0;
  int n = 0, m = 0;

  out << endl
      << endl
      << "Zad4" << endl;
  out << "(numer obrazka, wiersz, kolumna)" << endl;

  for (int i = 0; i < 200; i++)
  {
    int bledne_bity_bok = 0;
    int bledne_bity_dol = 0;
    int suma_blednych_bitow = 0;
    for (int j = 0; j < 21; j++)
    {
      in >> obrazek[j];
      string linia = obrazek[j];
      if (j != 20)
      {
        b_boczne[j] = obrazek[j].substr(20, 1);
        sam_obrazek[j] = obrazek[j].substr(0, 20);
        int suma_w = 0;
        for (int k = 0; k < 20; k++)
        {
          znak[j][k] = sam_obrazek[j][k];
          suma_w += (int)(znak[j][k]) - 48;
        }
        suma_obr_wiersz[j] = suma_w;
      }
      if (j == 20)
      {
        for (int k = 0; k < 20; k++)
        {
          b_dolne[k] = linia[k];
        }
      }
    }
    for (int j = 0; j < 20; j++)
    {
      int suma_k = 0;
      for (int k = 0; k < 20; k++)
        suma_k += (int)(znak[k][j]) - 48;
      suma_obr_kolumna[j] = suma_k;

      if (to_string(suma_obr_wiersz[j] % 2) != b_boczne[j])
      {
        bledne_bity_bok++;
        n = j;
      }
      if (to_string(suma_obr_kolumna[j] % 2) != b_dolne[j])
      {
        bledne_bity_dol++;
        m = j;
      }
    }
    if (bledne_bity_bok <= 1 && bledne_bity_dol <= 1)
    {
      if (bledne_bity_bok == 1 && bledne_bity_dol == 0)
        out << "(" << i + 1 << ", " << n + 1 << ", " << 21 << ")" << endl;
      else if (bledne_bity_bok == 0 && bledne_bity_dol == 1)
        out << "(" << i + 1 << ", " << 21 << ", " << m + 1 << ")" << endl;
      else if (bledne_bity_bok == 1 && bledne_bity_dol == 1)
        out << "(" << i + 1 << ", " << n + 1 << ", " << m + 1 << ")" << endl;
    }
  }

  in.close();
  out.close();
  system("pause");
  return 0;
}
