#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int max_dlugosc = 0;
int ilosc_genow[1000];
int max_genow = 0;

void liczenie(string do_sprawdzenia, int nr, int ktory)
{
  if (max_dlugosc < do_sprawdzenia.length() && do_sprawdzenia.find("BB") != -1)
    max_dlugosc = do_sprawdzenia.length();

  ilosc_genow[nr] = ktory;
}

void czy_gen(string linia, int nr)
{
  int ostatnie_A = linia.find("AA");
  int ostatnie_B = linia.find("BB");
  if (ostatnie_A > ostatnie_B)
    ostatnie_B = (linia.substr(ostatnie_A)).find("BB") + ostatnie_A;
  string do_sprawdzenia[1000];
  int i = 0;
  string odciete = linia.substr(0);
  while (odciete.find("BB") != -1 || odciete.find("AA") != -1)
  {
    if (ostatnie_A > ostatnie_B)
      ostatnie_B = (odciete.substr(ostatnie_A)).find("BB") + ostatnie_A;
    do_sprawdzenia[i] = odciete.substr(ostatnie_A, ostatnie_B - ostatnie_A + 2);
    liczenie(do_sprawdzenia[i], nr, i);
    odciete = odciete.substr(ostatnie_B);
    if (odciete.find("BB") == -1 || odciete.find("AA") == -1)
      break;
    ostatnie_A = odciete.find("AA");
    ostatnie_B = odciete.find("BB");
    i++;
  }
}

int main()
{
  ifstream in("../dane_geny.txt");
  ofstream out("../wyniki_geny.txt", ofstream::app);
  string linia;
  for (int i = 0; i < 1000; i++)
  {
    in >> linia;
    czy_gen(linia, i);
    if (ilosc_genow[i] > max_genow)
      max_genow = ilosc_genow[i];
  }
  out << endl;
  out << "Zad3" << endl;
  out << "Najwieksza ilosc genow: " << max_genow << endl;
  out << "Najwieksza dlugosc genu: " << max_dlugosc << endl;

  in.close();
  out.close();
  system("pause");
  return 0;
}