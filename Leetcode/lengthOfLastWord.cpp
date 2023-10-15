#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lengthOfLastWord(string s)
{
  int len = s.size();
  int n = s.find_last_of(' ');
  if (len != n + 1)
  {
    return len - n - 1;
  }
  else
  {
    int count = 0;
    for (int i = len - 1; i >= 0; i--)
    {
      if (s.at(i) == ' ')
        count++;
      else
        break;
    }
    s = s.substr(0, len - count);
    cout << s<<endl;
    int m = s.find_last_of(' ');
    cout << m <<endl;
    return len - count - m - 1;
  }
}
int main()
{
  string s = "   fly me   to   the moon  ";
  int c = lengthOfLastWord(s);
  cout << c << endl;
}