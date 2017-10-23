/*
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if
 * b < c. Chain of pairs can be formed in this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 *
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * Note:
 * The number of given pairs will be in the range [1, 1000].
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// solution 1
class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    if (pairs.size() <= 1) return pairs.size();
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
      return a[0] < b[0];
    });

    vector<int> dp(pairs.size());
    dp[0] = 1;
    dp[1] = pairs[1][0] > pairs[0][1] ? 2 : 1;

    int maxResult = 1;

    for (int i = 2; i < pairs.size(); i++) {
      dp[i] = 1;

      for (int j = i - 1; j >= 0; j--) {
        if (pairs[j][1] < pairs[i][0]) {
          dp[i] = max(dp[i], dp[j] + 1);
          maxResult = max(dp[i], maxResult);
          break;
        }
      }
    }

    return maxResult;
  }
};


// test
int main() {
  vector<vector<int>> pairs = {
    {1,2},
    {2,3},
    {3,4}
  };

  Solution solution;
  solution.findLongestChain(pairs);

  return 0;
}


