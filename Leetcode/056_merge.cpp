#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  static bool compareSecondColumn(const vector<int> &a, const vector<int> &b)
  {
    return a[0] < b[0];
  }
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> res;
    int len = intervals.size();
    // 使用自定义比较函数进行排序
    sort(res.begin(), res.end(), compareSecondColumn);
    for (int i = 0; i < len - 1; i++)
    {
      if (intervals[i][1] >= intervals[i + 1][1])
      {
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = intervals[i][1];
      }
      else if (intervals[i][1] >= intervals[i + 1][0])
      {
        intervals[i + 1][0] = intervals[i][0];
      }
      else
        res.push_back(intervals[i]);
    }
    res.push_back(intervals[len - 1]);

    return res;
  }
};

int main()
{

  return 0;
}