#include <iostream>
#include <fstream>
using namespace std;

bool czy_pierwsza(int n)
{
  if (n < 2)
    return false;

  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main()
{
  ifstream in("../trojki.txt");
  ofstream out("../wyniki_trojki.txt", ofstream::app);
  int pierwsza, druga, trzecia;
  out << endl
      << "Zad2" << endl
      << endl;
  while (in >> pierwsza >> druga >> trzecia)
    if (czy_pierwsza(pierwsza) && czy_pierwsza(druga) && pierwsza * druga == trzecia)
      out << pierwsza << " " << druga << " " << trzecia << endl;

  in.close();
  out.close();
  system("pause");
  return 0;
}