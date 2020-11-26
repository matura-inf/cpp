#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream in("../ciagi.txt");
  ofstream out("../wyniki_ciagi.txt", ofstream::app);
  string ciagi[1000];
  int ilosc;
  for (int i = 0; i < 1000; i++)
  {
    bool czy_dobre = true;
    in >> ciagi[i];
    string element = ciagi[i];
    for (int j = 1; j < element.length(); j++)
    {
      string pierwsza = element.substr(j - 1, 1);
      string druga = element.substr(j, 1);
      int int_pierwsza = stoi(pierwsza);
      int int_druga = stoi(druga);
      if (int_pierwsza + int_druga == 2)
      {
        czy_dobre = false;
        break;
      }
    }
    if (czy_dobre)
      ilosc++;
  }
  out << endl
      << endl
      << "Zad2" << endl;
  out << ilosc;
  in.close();
  out.close();
  system("pause");
  return 0;
}