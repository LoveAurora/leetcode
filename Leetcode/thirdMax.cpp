#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int thirdMax(vector<int> &nums)
{
  set<int> seen;
  vector<int> uniqueVec;

  for (int val : nums)
  {
    if (seen.find(val) == seen.end())
    {
      uniqueVec.push_back(val);
      seen.insert(val);
    }
  }
  sort(uniqueVec.begin(), uniqueVec.end());
  int len = uniqueVec.size();
  if (len < 3)
  {
    return uniqueVec[len - 1];
  }
  else
  {
    return uniqueVec[len - 3];
  }
}