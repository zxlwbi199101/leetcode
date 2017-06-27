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
    // qsort(nums, 0, nums.size() - 1);
    qsortIterate(nums);

    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }
    return sum;
  }

  void qsort(vector<int>& nums, int start, int end) {
    if (start >= end) return;

    int pivot = nums[start];
    int low = start;
    int high = end;

    while (low < high) {
      while (low < high && nums[high] >= pivot) high--;
      while (low < high && nums[low] < pivot) low++;

      if (low == high) break;
      swap(nums[low], nums[high]);
    }

    if (nums[start] > nums[low]) {
      swap(nums[start], nums[low]);
    }

    qsort(nums, start, low);
    qsort(nums, high + 1, end);
  }

  void qsortIterate(vector<int>& nums) {
    // store position of each partial qsort
    queue<int> que;

    que.push(0);
    que.push(nums.size() - 1);

    while (!que.empty()) {
      int start = que.front();
      que.pop();

      int end  = que.front();
      que.pop();

      int pivot = nums[start];
      int low = start;
      int high = end;

      if (start >= end) continue;

      while (true) {
        while (low < high && nums[high] >= pivot) high--;
        while (low < high && nums[low] < pivot) low++;

        if (low == high) break;
        swap(nums[low], nums[high]);
      }

      if (nums[start] > nums[low]) {
        swap(nums[start], nums[low]);
      }

      que.push(high + 1);
      que.push(end);
      que.push(start);
      que.push(low);
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,3,2};
  // int result = solution.arrayPairSum(nums);
  // cout << result << endl;

  solution.qsortIterate(nums);
  // solution.qsort(nums, 0, nums.size() - 1);
  for (int i : nums) {
    cout << i << endl;
  }

  return 0;
}


