#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static bool compared(const vector<int> &a, const vector<int> &b)
  {
    return a[0] < b[0];
  }
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), compared);
    vector<vector<int>> res;
    int len = intervals.size() - 1;
    for (int i = 0; i < len; i++)
    {
      if (intervals[i][1] < intervals[i + 1][0])
      {
        res.push_back(intervals[i]);
      }
      else if (intervals[i][1] >= intervals[i + 1][0])
      {
        if (intervals[i][1] <= intervals[i + 1][1])
          intervals[i + 1][0] = intervals[i][0];
        else if (intervals[i][1] > intervals[i + 1][1])
        {
          intervals[i + 1][0] = intervals[i][0];
          intervals[i + 1][1] = intervals[i][1];
        }
      }
    }
    res.push_back(intervals[len]);
    return res;
  }
};
vector<vector<int>> insertanotherSolution(vector<vector<int>> &intervals, vector<int> &newInterval)
{
  int len = intervals.size();
  int left = newInterval[0], right = newInterval[1];
  bool placed = false;
  vector<vector<int>> res;

  for (int i = 0; i < len; i++)
  {
    if (intervals[i][1] < left) // 该子集在插入区间的左侧且无交集
    {
      res.push_back(intervals[i]);
    }
    else if (intervals[i][0] > right) // 该子集在插入区间的右侧且无交集
    {
      // if成立，表示前面产生过区间的合并,并且现在这个合并的区间在intervals[i]的左边，
      // 先加入合并的区间到res中，再把intervals[i]加入到res中
      if (!placed)
      {
        res.push_back({left, right});
        placed = true;
      }
      res.push_back(intervals[i]);
    }
    else // 与插入区间有交集，计算它们的并集
    {
      left = min(intervals[i][0], left);
      right = max(intervals[i][0], right);
    }
  }
  // 如果一直合并到循环结束，placed就为false
  if (!placed)
  {
    res.push_back({left, right});
  }
  return res;
}

int main()
{
  return 0;
}