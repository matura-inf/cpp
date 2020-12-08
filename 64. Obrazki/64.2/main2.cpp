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
  string cz1[2][10], cz2[2][10];
  string pierwszy_cz1[2][10], pierwszy_cz2[2][10];
  int ile = 0;
  bool czy_znaleziono = false;

  for (int i = 0; i < 200; i++)
  {
    for (int j = 0; j < 21; j++)
    {
      in >> obrazek[j];
      if (j != 20)
      {
        sam_obrazek[j] = obrazek[j].substr(0, 20);
        string linia = sam_obrazek[j];
        if (j >= 0 && j <= 9)
        {
          cz1[0][j] = linia.substr(0, 10);
          cz2[0][j] = linia.substr(10, 10);
        }
        if (j >= 10 && j <= 19)
        {
          cz1[1][j - 10] = sam_obrazek[j].substr(0, 10);
          cz2[1][j - 10] = sam_obrazek[j].substr(10, 10);
        }
      }
    }

    //* Sprawdzanie
    for (int j = 0; j < 10; j++)
    {
      if (cz1[0][j] == cz2[0][j])
      // if (cz1[0][j].compare(cz2[0][j]) == 0)
      {
        if (cz1[0][j] == cz1[1][j] && cz2[0][j] == cz2[1][j])
        // if ((cz1[0][j].compare(cz1[1][j]) == 0) && (cz2[0][j].compare(cz2[1][j])) == 0)
        {
          if (j == 9)
          {
            ile++;
          }
          if (!czy_znaleziono)
          {
            pierwszy_cz1[0][j] = cz1[0][j];
            pierwszy_cz2[0][j] = cz2[0][j];
            pierwszy_cz1[1][j] = cz1[1][j];
            pierwszy_cz2[1][j] = cz2[1][j];
            if (j == 9)
              czy_znaleziono = true;
          }
        }
        else
          break;
      }
      else
        break;
    }
  }

  out << endl
      << endl
      << "Zad2" << endl;

  if (czy_znaleziono)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        out << pierwszy_cz1[i][j];
        out << pierwszy_cz2[i][j] << endl;
      }
    }
  }

  out << endl
      << "Ile: " << ile << endl;

  in.close();
  out.close();
  system("pause");
  return 0;
}