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

int main()
{
  ofstream out("../wyniki.txt", ofstream::app);
  out << "Zad1" << endl;
  out << "fib(" << 10 << "): " << fibonacci(10) << endl;
  out << "fib(" << 20 << "): " << fibonacci(20) << endl;
  out << "fib(" << 30 << "): " << fibonacci(30) << endl;
  out << "fib(" << 40 << "): " << fibonacci(40) << endl;
  out.close();
  system("pause");
  return 0;
}