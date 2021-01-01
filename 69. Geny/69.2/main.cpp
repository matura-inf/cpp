#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool czy_odporny(string do_sprawdzenia)
{
  if (do_sprawdzenia.find("BCDDC") != -1)
    return true;
  else
    return false;
}

bool czy_gen(string linia)
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
    do_sprawdzenia[i] = odciete.substr(ostatnie_A, ostatnie_B - ostatnie_A);
    if (czy_odporny(do_sprawdzenia[i]))
      return true;
    odciete = odciete.substr(ostatnie_B + 2);
    if (odciete.find("BB") == -1 || odciete.find("AA") == -1)
      break;
    ostatnie_A = odciete.find("AA");
    ostatnie_B = odciete.find("BB");
    i++;
  }
  return false;
}

int main()
{
  ifstream in("../dane_geny.txt");
  ofstream out("../wyniki_geny.txt", ofstream::app);
  string linia;
  int ilosc = 0;
  for (int i = 0; i < 1000; i++)
  {
    in >> linia;
    if (czy_gen(linia))
      ilosc++;
  }
  out << endl;
  out << "Zad2" << endl;
  out << "Liczba gatunków odpornych: " << ilosc << endl;
  in.close();
  out.close();
  system("pause");
  return 0;
}