/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions
 * as you like (ie, buy one and sell one share of the stock multiple times). However,
 * you may not engage in multiple transactions at the same time (ie, you must sell the stock
 * before you buy again).
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int sum = 0;

    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i + 1] > prices[i]) sum += prices[i + 1] - prices[i];
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v = {2,3,4,5,6,7,8,9,10};

  cout << solution.maxProfit(v) << endl;

  return 0;
}


