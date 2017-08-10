/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one
 * share of the stock), design an algorithm to find the maximum profit.
 *
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) return 0;

    int maxProfitVal = INT_MIN;
    int maxPriceVal = prices[len - 1];
    int temp = 0;

    for (int i = prices.size() - 2; i >= 0; i--) {
      temp = prices[i];

      maxProfitVal = max(maxPriceVal - temp, maxProfitVal);
      maxPriceVal = max(maxPriceVal, temp);
    }

    return maxProfitVal <= 0 ? 0 : maxProfitVal;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v1 = {7, 1, 5, 3, 6, 4};

  cout << solution.maxProfit(v1) << endl;

  return 0;
}


