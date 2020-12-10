#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in("../trojki.txt");
  ofstream out("../wyniki_trojki.txt", ofstream::app);
  int pierwsza, druga, trzecia;
  out << "Zad1" << endl
      << endl;
  while (in >> pierwsza >> druga >> trzecia)
  {
    int cyfra_p;
    int cyfra_d;
    int pierwsza_k = pierwsza, druga_k = druga;
    int suma = 0;

    while (pierwsza_k > 0)
    {
      cyfra_p = pierwsza_k % 10;
      pierwsza_k /= 10;
      suma += cyfra_p;
    }
    while (druga_k > 0)
    {
      cyfra_d = druga_k % 10;
      druga_k /= 10;
      suma += cyfra_d;
    }
    if (suma == trzecia)
      out << pierwsza << " " << druga << " " << trzecia << endl;
  }

  in.close();
  out.close();
  system("pause");
  return 0;
}