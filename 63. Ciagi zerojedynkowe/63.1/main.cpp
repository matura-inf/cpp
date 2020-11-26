#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream in("../ciagi.txt");
  ofstream out("../wyniki_ciagi.txt");
  string ciagi[1000];
  out << "Zad1" << endl;
  for (int i = 0; i < 1000; i++)
  {
    in >> ciagi[i];
    int dlugosc_ciagu = ciagi[i].length();
    if (dlugosc_ciagu % 2 == 0)
    {
      string element = ciagi[i];

      string first_half = element.substr(0, element.length() / 2);
      string second_half = element.substr(element.length() / 2);

      if (first_half == second_half)
      {
        out << ciagi[i] << endl;
      }
    }
  }
  in.close();
  out.close();
  system("pause");
  return 0;
}