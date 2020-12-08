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
  string cz1[21], cz2[21], cz3[21], cz4[21]; // cz3 i cz4 wypełniają się od połowy, ale da się żyć.
  string pierwszy_cz1[21], pierwszy_cz2[21], pierwszy_cz3[21], pierwszy_cz4[21];
  bool czy_znaleziono = false;
  int ile = 0;
  for (int i = 0; i < 200; i++)
  {
    for (int j = 0; j < 21; j++)
    {
      in >> obrazek[j];
      if (j != 20)
      {
        sam_obrazek[j] = obrazek[j].substr(0, 20);
        if (j >= 0 && j <= 9)
        {
          cz1[j] = sam_obrazek[j].substr(0, 10);
          cz2[j] = sam_obrazek[j].substr(10, 10);
        }
        if (j >= 10 && j <= 19)
        {
          cz3[j] = sam_obrazek[j].substr(0, 10);
          cz4[j] = sam_obrazek[j].substr(10, 10);
        }
      }
    }
    for (int j = 0; j < 10; j++)
    {
      // if (cz1[j] == cz2[j] && cz2[j] == cz3[j + 10] && cz3[j + 10] == cz4[j + 10]) //*daje taki sam efekt jak to niżej
      if ((cz1[j].compare(cz2[j]) == 0) && (cz2[j].compare(cz3[j + 10]) == 0) && (cz3[j + 10].compare(cz4[j + 10]) == 0))
      {
        if (!czy_znaleziono)
        {
          pierwszy_cz1[j] = cz1[j];
          pierwszy_cz2[j] = cz2[j];
          pierwszy_cz3[j + 10] = cz3[j + 10];
          pierwszy_cz4[j + 10] = cz4[j + 10];
          if (j == 9)
            czy_znaleziono = true;
        }
        if (j == 9)
        {
          ile++;
        }
      }
      else
        break;
    }
  }
  out << endl
      << endl
      << "Zad2" << endl;

  cout << "Ilosc: " << ile << endl;

  if (czy_znaleziono)
  {
    for (int i = 0; i < 10; i++)
    {
      cout << pierwszy_cz1[i];
      cout << pierwszy_cz2[i] << endl;
    }

    for (int i = 10; i < 20; i++)
    {
      cout << pierwszy_cz3[i];
      cout << pierwszy_cz4[i] << endl;
    }
  }

  in.close();
  out.close();
  system("pause");
  return 0;
}