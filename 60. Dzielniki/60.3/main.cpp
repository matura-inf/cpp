#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int nwd(int x, int y)
{
  if (x < y)
  {
    return nwd(y, x);
  }
  if (y == 0)
  {
    return x;
  }
  return nwd(y, x % y);
}

int main()
{
  ifstream in("../liczby.txt");
  ofstream out("../wyniki.txt", ofstream::app);

  int liczby[200];
  int najwieksza = 0;
  for (int i = 0; i < 200; i++)
  {
    in >> liczby[i];
  }
  for (int i = 0; i < 200; i++)
  {
    bool czy_dobra = true;
    for (int j = 1; j < 200; j++)
    {
      if (i != j && nwd(liczby[i], liczby[j]) > 1)
      {
        czy_dobra = false;
      }
      if (czy_dobra && nwd(liczby[i], liczby[j]) > najwieksza)
      {
        najwieksza = liczby[i];
      }
    }
  }
  in.close();
  out << endl
      << endl
      << "ZAD 60.3" << endl;
  out << najwieksza;
  out.close();
  cout << "Dane zapisano do pliku." << endl;
  system("pause");
  return 0;
}