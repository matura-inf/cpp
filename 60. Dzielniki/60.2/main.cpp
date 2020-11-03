#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  ifstream in("../liczby.txt");
  ofstream out("../wyniki.txt", fstream::app);
  out << endl
      << endl
      << "ZAD 60.2" << endl;
  int dzielniki[200];
  int dzielnik = 0;
  string dzielniki_str = "";
  for (int i = 0; i < 200; i++)
  {
    int ile = 0;
    int a;
    in >> a;
    for (int j = a; j >= 1; j--)
    {
      if (a % j == 0)
      {
        dzielnik = a / j;
        dzielniki[ile] = dzielnik;
        ile++;
      }
    }

    if (ile == 18)
    {
      for (int k = 0; k < ile; k++)
      {
        dzielniki_str += to_string(dzielniki[k]) + ", ";
      }
      out << "Liczba majaca 18 dzielnikow to: " << a << ", a jej dzielniki to: " << dzielniki_str << endl
          << endl;
    }
  }
  out.close();
  cout << "Dane zapisano do pliku." << endl;
  system("pause");
  return 0;
}