/*
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description
 *
 * Given a non-empty integer array of size n, find the minimum number
 * of moves required to make all array elements equal, where a move is
 * incrementing n - 1 elements by 1.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int minMoves(vector<int>& nums) {
    if (!nums.size()) return 0;

    int result = 0;
    int m = nums[0];
    for (int i : nums) m = min(m, i);
    for (int i : nums) result += i - m;

    return result;
  }
};


// test
int main() {
  Solution solution;
  vector<int> v = {1,2,3};

  cout << solution.minMoves(v) << endl;

  return 0;
}


