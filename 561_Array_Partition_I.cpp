 /*
 * https://leetcode.com/problems/array-partition-i/#/description
 *
 * Given an array of 2n integers, your task is to group these integers into
 * n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum
 * of min(ai, bi) for all i from 1 to n as large as possible.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    qsortIterative(nums);

    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }
    return sum;
  }

  int partition(vector<int>& v, int start, int end) {
    int pivot = v[end];
    int index = start;

    for (int i = start; i < end; i++) {
      if (v[i] <= pivot) swap(v[i], v[index++]);
    }

    if (v[index] > pivot) swap(v[index], v[end]);
    return index;
  }

  void qsortIterative(vector<int>& v) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(0, v.size() - 1));

    int start, end, pivotIndex;

    while (!stk.empty()) {
      start = stk.top().first;
      end = stk.top().second;
      stk.pop();

      pivotIndex = partition(v, start, end);

      if (pivotIndex - 1 > start) stk.push(make_pair(start, pivotIndex - 1));
      if (pivotIndex + 1 < end) stk.push(make_pair(pivotIndex + 1, end));
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,3,2};
  // int result = solution.arrayPairSum(nums);
  // cout << result << endl;

  solution.qsortIterative(nums);
  for (int i : nums) {
    cout << i << endl;
  }

  return 0;
}


