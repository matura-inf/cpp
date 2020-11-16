#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int liczby_1;
  int liczby_2;
  int ile_rownych = 0;
  int liczb_wiekszych = 0;

  ifstream in1("../liczby1.txt");
  ifstream in2("../liczby2.txt");
  ofstream out("../wyniki.txt", ofstream::app);

  for (int i = 0; i < 1000; i++)
  {
    in1 >> oct >> liczby_1;
    in2 >> dec >> liczby_2;
    if (liczby_1 == liczby_2)
      ile_rownych++;
    else if (liczby_1 > liczby_2)
      liczb_wiekszych++;
  }

  out << endl
      << endl
      << "Zad3:" << endl;
  out << "liczby takie same: " << ile_rownych << endl;
  out << "liczby w pierwszym pliku wieksze: " << liczb_wiekszych;
  in1.close();
  in2.close();
  out.close();
  system("pause");
  return 0;
}
