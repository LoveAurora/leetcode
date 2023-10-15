#include <bits/stdc++.h>
using namespace std;
// int maxProfit(vector<int> &prices)
// {
//   int maxprofit = 0, temp;
//   int len = prices.size();

//   for (int i = 0; i < len - 1; i++)
//   {
//     for (int j = i + 1; j < len; j++)
//     {
//       temp = prices[j] - prices[i];
//       if (maxprofit < temp)
//         maxprofit = temp;
//     }
//   }
//   return maxprofit;
// }
int maxProfit(vector<int> &prices)
{
  int maxprofit = 0, minprince = 1e9;
  for (int price : prices)
  {
    maxprofit = max(maxprofit, price - minprince);
    minprince = min(minprince, price);
  }
  return maxprofit;
}