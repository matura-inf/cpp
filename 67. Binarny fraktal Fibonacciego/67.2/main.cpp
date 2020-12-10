#include <iostream>
#include <fstream>
#include <cmath>
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
  ofstream out("../wyniki.txt", ofstream::app);
  out << endl
      << "Zad2" << endl;

  for (int i = 1; i <= 40; i++)
    if (czy_pierwsza(fibonacci(i)))
      out << "fib(" << i << "): " << fibonacci(i) << endl;

  out.close();
  system("pause");
  return 0;
}