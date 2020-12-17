#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string pierwszy[1000], drugi[1000];

bool jednolity(string s)
{
  for (int i = 1; i < s.length(); i++)
    if (s[i] != s[i - 1])
      return false;
  return true;
}

int main()
{
  ifstream in("../dane_napisy.txt");
  ofstream out("../wyniki_anagramy.txt", ofstream::app);
  int ilosc = 0;
  for (int i = 0; i < 1000; i++)
  {
    in >> pierwszy[i];
    in >> drugi[i];

    if (jednolity(pierwszy[i]) && jednolity(drugi[i]))
      if (pierwszy[i][0] == drugi[i][0] && pierwszy[i].length() == drugi[i].length())
        ilosc++;
  }
  out << "Zad1" << endl;
  out << ilosc << endl;
  in.close();
  out.close();
  system("pause");
  return 0;
}
