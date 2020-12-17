#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string pierwszy[2000];

bool czy_anagram(string s1, string s2)
{
  if (s1.length() == s2.length())
  {
    for (unsigned int j = 0; j < s1.length(); j++)
      for (unsigned int k = 0; k < s1.length(); k++)
        if (s1[j] == s2[k])
        {
          s2[k] = '0';
          break;
        }
    for (unsigned int j = 0; j < s1.length(); j++)
    {
      if (s2[j] == '0')
      {
        if (j == s1.length() - 1)
          return true;
      }
      else
        return false;
    }
  }
}

int main()
{
  ifstream in("../dane_napisy.txt");
  ofstream out("../wyniki_anagramy.txt", ofstream::app);
  int max_ilosc = 0;
  for (int i = 0; i < 2000; i++)
    in >> pierwszy[i];
  for (int i = 0; i < 1000; i++)
  {
    int ilosc = 0;
    for (int j = 0; j < 1000; j++)
      if (czy_anagram(pierwszy[i], pierwszy[j]))
        ilosc++;
    if (max_ilosc < ilosc)
      max_ilosc = ilosc;
  }

  out << "Zad3" << endl;
  out << max_ilosc;
  in.close();
  out.close();
  system("pause");
  return 0;
}
