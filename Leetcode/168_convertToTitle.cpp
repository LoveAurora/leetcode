#include <bits/stdc++.h>
using namespace std;
string convertToTitle(int columnNumber)
{
  // 转26进制，特别的是[1,26]，而不是[0,25] 所以多减一
  string str;
  int temp;
  while (columnNumber > 0)
  {
    temp = (columnNumber - 1) % 26 + 1;
    // 通过取模操作来确定当前位置的字母。因为我们的索引从1开始（而不是从0开始），
    // 所以先减1。然后 % 26 会得到一个0到25之间的数，加1后再次变为1到26。
    str += temp + 'A' - 1;
    columnNumber = (columnNumber - temp) / 26;
    // 更新 columnNumber 以进行下一次迭代。我们减去 temp 是因为我们已经考虑过它了。然后我们除以26来进入下一个“位置”。
  }
  reverse(str.begin(), str.end());
  return str;
}
int main()
{
  string s = convertToTitle(52);
  cout << s << endl;
}