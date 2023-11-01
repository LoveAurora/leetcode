#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2)
{
  string str;
  int carry = 0;
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  int m = num1.size();
  int n = num2.size();
  if (m > n)
    num2.append(m - n, '0');
  if (m < n)
    num1.append(n - m, '0');
  int temp, len;

  len = max(m, n);
  for (int i = 0; i < len; i++)
  {
    temp = carry + (num1[i]- '0') + (num2[i] - '0');
    carry = temp / 10;
    str.append(to_string(temp % 10));
  }
  if (carry != 0)
    str.append(1, '1');
  reverse(str.begin(), str.end());
  return str;
}
int main()
{
  string s;
  string num1 = "11", num2 = "123";
  s = addStrings(num1, num2);
  cout << s << " ";
}