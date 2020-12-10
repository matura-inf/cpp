#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream in("../trojki.txt");
  ofstream out("../wyniki_trojki.txt", ofstream::app);
  long long pierwsza, druga, trzecia, nr_linii = 0;
  long long pierwsza_p = 1, druga_p = 2, trzecia_p = 3;
  long long pierwsza_n = 1, druga_n = 2, trzecia_n = 3;
  out << endl
      << "Zad3" << endl
      << endl;
  while (in >> pierwsza >> druga >> trzecia)
  {
    if (nr_linii % 2 == 0)
    {
      pierwsza_p = pierwsza;
      druga_p = druga;
      trzecia_p = trzecia;
    }
    if (nr_linii % 2 == 1)
    {
      pierwsza_n = pierwsza;
      druga_n = druga;
      trzecia_n = trzecia;
    }

    if (((pow(pierwsza_p, 2) + pow(druga_p, 2) == pow(trzecia_p, 2)) || (pow(pierwsza_p, 2) + pow(trzecia_p, 2) == pow(druga_p, 2)) || (pow(trzecia_p, 2) + pow(druga_p, 2) == pow(pierwsza_p, 2))) && ((pow(pierwsza_n, 2) + pow(druga_n, 2) == pow(trzecia_n, 2)) || (pow(pierwsza_n, 2) + pow(trzecia_n, 2) == pow(druga_n, 2)) || (pow(trzecia_n, 2) + pow(druga_n, 2) == pow(pierwsza_n, 2))))
    {
      out << pierwsza_n << " " << druga_n << " " << trzecia_n << endl;
      out << pierwsza_p << " " << druga_p << " " << trzecia_p << endl
          << endl;
    }

    nr_linii++;
  }

  in.close();
  out.close();
  system("pause");

  return 0;
}