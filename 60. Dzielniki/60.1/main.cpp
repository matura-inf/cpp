#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;
int ostatnia = 0, przedostatnia = 0;
int ilosc = 0;
int main()
{

  ifstream in("../liczby.txt");
  for (int i = 0; i < 200; i++)
  {
    int a;
    in >> a;
    if (a < 1000)
    {
      przedostatnia = ostatnia;
      ostatnia = a;
      ilosc++;
    }
  }
  ofstream out("../wyniki.txt", ofstream::app);
  out << "ZAD 60.1" << endl;
  out << "Ilosc: " << ilosc << ", ostatnia: " << ostatnia << ", przedostatnia: " << przedostatnia << endl;
  out.close();
  cout << "Dane zapisano do pliku." << endl;
  system("pause");
  return 0;
}
