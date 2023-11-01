#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> fizzBuzz(int n)
{
  vector<string> f(n);
  for (int i = 1; i <= n; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      f[i - 1] = "FizzBuzz";
    }
    else if (i % 3 == 0)
    {
      f[i - 1] = "Fizz";
    }
    else if (i % 5 == 0)
    {
      f[i - 1] = "Buzz";
    }
    else
    {
      f[i - 1] = to_string(i);
    }
  }
  return f;
}
int main()
{
  vector<string> f;
  f = fizzBuzz(3);
  for (string i : f)
  {
    cout << i << " ";
  }
}