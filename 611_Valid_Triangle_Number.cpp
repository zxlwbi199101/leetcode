/*
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * Given an array consists of non-negative integers, your task is to count
 * the number of triplets chosen from the array that can make triangles if we
 * take them as side lengths of a triangle.
 *
 * Example 1:
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are:
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * Note:
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  // O(n3)
  //
  // int triangleNumber(vector<int>& nums) {
  //   sort(nums.begin(), nums.end());
  //   int result = 0;

  //   if (nums.size() < 3) return 0;

  //   for (int i = 0; i < nums.size() - 2; i++) {
  //     for (int j = i + 1; j < nums.size() - 1; j++) {
  //       for (int k = j + 1; k < nums.size(); k++) {
  //         if (nums[k] < nums[i] + nums[j]) result++;
  //         else break;
  //       }
  //     }
  //   }

  //   return result;
  // }

  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    int len = nums.size();

    for (int i = len - 1; i > 1; i--) {
      for (int j = i - 1, k = 0; j > k;) {
        if (nums[i] < nums[j] + nums[k]) {
          result += j - k;
          j--;
        } else {
          k++;
        }
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {2,2,3,4};
  cout << solution.triangleNumber(nums);

  return 0;
}

