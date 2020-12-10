#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

long long fibonacci(int n)
{
  long long a = 0, b = 1;
  for (int i = 0; i < n; i++)
  {
    b += a;
    a = b - a;
    if (i == n - 2)
      return b;
  }
}

int *to_bin(int n)
{
  int bin_s[27];
  for (int k = 0; k < 27; k++)
  {
    bin_s[k] = 0;
  }
  int a[100], i;
  for (i = 0; n > 0; i++)
  {
    a[i] = n % 2;
    n = n / 2;
  }
  int j = 0;
  for (i = i - 1; i >= 0; i--, j++)
  {
    bin_s[26 - i] = a[i];
  }
  return bin_s;
}

int main()
{
  ofstream out("../wyniki.txt", ofstream::app);
  int ilosc = 0;
  out
      << endl
      << "Zad4" << endl;
  for (int i = 1; i <= 40; i++)
  {
    for (int j = 0; j < 27; j++)
      if (to_bin(fibonacci(i))[j] == 1)
        ilosc++;
    if (ilosc == 6)
    {
      for (int j = 0; j < 27; j++)
        out << to_bin(fibonacci(i))[j];
      out << endl;
    }
    ilosc = 0;
  }

  out.close();
  system("pause");
  return 0;
}
