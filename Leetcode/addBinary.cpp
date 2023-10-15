#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using namespace std;
string addBinary(string a, string b)
{
  string ans;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int len = max(a.size(), b.size()), carry = 0;
  for (int i = 0; i < len; i++)
  {
    carry += i < a.size() ? (a.at(i) == '1') : 0;
    carry += i < b.size() ? (b.at(i) == '1') : 0;
    
    ans.push_back((carry % 2) ? '1' : '0');
    carry /= 2;
  }
  if (carry)
  {
    ans.push_back('1');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  string a = "100";
  string b = "110010";
  string c = addBinary(a, b);
  cout << c << endl;
}