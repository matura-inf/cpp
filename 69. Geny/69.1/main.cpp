#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countDistinct(int arr[], int n)
{
  int res = 1;
  for (int i = 1; i < n; i++)
  {
    int j = 0;
    for (j = 0; j < i; j++)
      if (arr[i] == arr[j])
        break;

    if (i == j)
      res++;
  }
  return res;
}

int main()
{
  ifstream in("../dane_geny.txt");
  ofstream out("../wyniki_geny.txt", ofstream::app);
  string ciag[1000];
  int dlugosc[1000];
  int ile_takich_co_index[501];
  int n = sizeof(dlugosc) / sizeof(dlugosc[0]);
  int max_ilosc = 0;
  for (int i = 0; i < 1000; i++)
  {
    in >> ciag[i];
    dlugosc[i] = ciag[i].length();
  }
  for (int i = 0; i < 501; i++)
  {
    for (int j = 0; j < 1000; j++)
      ile_takich_co_index[i] += i == dlugosc[j];
    if (max_ilosc < ile_takich_co_index[i])
      max_ilosc = ile_takich_co_index[i];
  }
  out << "Zad1" << endl;
  out << "Ilosc gatunkow: " << countDistinct(dlugosc, n) << endl;
  out << "Wielkosc najwiekszego gatunku: " << max_ilosc << endl;
  in.close();
  out.close();
  system("pause");
  return 0;
}
