#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string pierwszy[1000], drugi[1000];

int main()
{
  ifstream in("../dane_napisy.txt");
  ofstream out("../wyniki_anagramy.txt", ofstream::app);
  int ilosc = 0;
  for (int i = 0; i < 1000; i++)
  {
    in >> pierwszy[i];
    in >> drugi[i];
    if (pierwszy[i].length() == drugi[i].length())
    {
      for (unsigned int j = 0; j < pierwszy[i].length(); j++)
        for (unsigned int k = 0; k < pierwszy[i].length(); k++)
          if (pierwszy[i][j] == drugi[i][k])
          {
            drugi[i][k] = '0';
            break;
          }
      for (unsigned int j = 0; j < pierwszy[i].length(); j++)
      {
        if (drugi[i][j] == '0')
        {
          if (j == pierwszy[i].length() - 1)
            ilosc++;
        }
        else
          break;
      }
    }
  }
  out << "Zad2" << endl;
  out << ilosc << endl;
  in.close();
  out.close();
  system("pause");
  return 0;
}
