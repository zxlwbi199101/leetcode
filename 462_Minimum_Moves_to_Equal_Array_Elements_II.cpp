/*
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 *
 * You may assume the array's length is at most 10,000.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// solution 1
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int mid = nums[nums.size() / 2];
    int result = 0;
    for (int n : nums) sum += abs(mid - n);

    return result;
  }
};


// test
int main() {
  return 0;
}


