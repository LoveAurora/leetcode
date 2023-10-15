#include <bits/stdc++.h>
using namespace std;
int distributeCandies(vector<int> &candyType)
{
  map<int, int> m;
  int len = candyType.size();
  for (int key : candyType)
  {
    auto it = m.find(key);
    // 查找键
    if (it != m.end())
      // 如果找到键，则增加其值
      it->second += 1;
    else
      // 如果键不存在，则可以选择插入该键，并初始化其值为1（或任何其他适当的初始值）
      m[key] = 1;
  }
  int temp = m.size();
  return temp > len / 2 ? len / 2 : temp;
}
