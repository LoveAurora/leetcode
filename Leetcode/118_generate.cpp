#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> vec(numRows);
  vec[0].resize(1);
  vec[0][0] = 1;
  for (int i = 1; i < numRows; i++)
  {
    vec[i].resize(i + 1);
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
        vec[i][j] = 1;
      else
        vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
    }
  }
  return vec;
}
