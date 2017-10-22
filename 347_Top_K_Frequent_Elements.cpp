/*
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int maxCount = INT_MIN;
    for (int n : nums) {
      m[n]++;
      maxCount = max(maxCount, m[n]);
    }

    vector<vector<int>> bucket(maxCount + 1);
    for (auto it = m.begin(); it != m.end(); it++) {
      bucket[it->second].push_back(it->first);
    }

    vector<int> result;
    for (int i = maxCount, count = 0; count < k; i--) {
      if (bucket[i].size() > 0) {
        for (int j = 0; j < bucket[i].size() && count < k; j++) {
          result.push_back(bucket[i][j]);
          count++;
        }
      }
    }

    return result;
  }
};


// test
int main() {
  return 0;
}


