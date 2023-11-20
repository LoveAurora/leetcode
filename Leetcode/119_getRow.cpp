#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    vector<vector<int>> vec(rowIndex);
    for (int i = 0; i < rowIndex; i++)
    {
      vec[i].resize(i + 1);
      vec[i][0] = vec[i][i] = 1;
      for (int j = 0; j <= i; j++)
      {
        vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
      }
    }
    return vec[rowIndex - 1];
  }
};
