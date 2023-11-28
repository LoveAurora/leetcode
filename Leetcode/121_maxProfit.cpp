#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int len = prices.size();
    int dp[len];
    if (len == 0)
      return 0;
    int maxPro = 0;
    dp[0] = prices[0];
    for (int i = 1; i < len; i++)
    {
      if (prices[i] > dp[i - 1])
        dp[i] = dp[i - 1];
      else
        dp[i] = prices[i];

      maxPro = maxPro > (prices[i] - dp[i - 1]) ? maxPro : prices[i] - dp[i - 1];
    }
    return maxPro;
  }
};

int main()
{
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution sol;
  sol.maxProfit(prices);
  return 0;
}