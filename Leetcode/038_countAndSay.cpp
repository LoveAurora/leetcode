#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{

  if (n == 1)
    return "1";
  if (n == 2)
    return "11";
  string temp = "11";
  string s;
  for (int i = 3; i <= n; i++)
  {
    s = "";
    int count = 1;
    int top = temp.size();
    for (int j = 1; j < top; j++)
    {
      if (temp[j] == temp[j - 1])
      {
        if (j != top - 1)
          count++;
        else
        {
          count++;
          s = s + to_string(count) + temp[j - 1];
          count = 1;
        }
      }
      else
      {
        if (j != top - 1)
        {
          s = s + to_string(count) + temp[j - 1];
          count = 1;
        }
        else
        {
          s = s + to_string(count) + temp[j - 1];
          s = s + "1" + temp[j];
          count = 1;
        }
      }
    }
    temp = s;
  }
  return s;
}
int main()
{
  cout << countAndSay(6);
}
