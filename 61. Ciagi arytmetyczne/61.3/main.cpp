#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream in("../bledne.txt");
  ofstream out("../wynik3.txt", ofstream::app);
  int ciag[1000];
  int roznica[20][1000];

  for (int i = 0; i < 20; i++)
  {
    int dlugosc = 0;
    in >> dlugosc;
    for (int j = 0; j < dlugosc; j++)
    {
      in >> ciag[j];
    }
    for (int j = 0; j < dlugosc - 1; j++)
      roznica[i][j] = ciag[j + 1] - ciag[j];
    for (int j = 0; j < dlugosc - 1; j++)
    {
      if (roznica[i][0] == roznica[i][1]) //* Jeśli C0 C1 C2 są poprawne
      {
        if ((roznica[i][j] != roznica[i][0] && roznica[i][j + 1] != roznica[i][0]))
        {
          out << ciag[j + 1];
          break;
        }
      }
      else if (roznica[i][0] != roznica[i][1] && roznica[i][1] == roznica[i][2] && roznica[i][2] == roznica[i][3]) //* Jeśli C0 jest błędne
      {
        out << ciag[0];
        break;
      }
      else if (roznica[i][0] != roznica[i][1] && roznica[i][1] != roznica[i][2] && roznica[i][2] == roznica[i][3]) //* Jeśli C1 jest błędne
      {
        out << ciag[1];
        break;
      }
      else if (roznica[i][0] != roznica[i][1] && roznica[i][1] != roznica[i][2] && roznica[i][2] != roznica[i][3]) //* Jeśli C2 jest błędne
      {
        out << ciag[2];
        break;
      }
    }

    out << endl;
  }
  in.close();
  out.close();
  system("pause");
  return 0;
}