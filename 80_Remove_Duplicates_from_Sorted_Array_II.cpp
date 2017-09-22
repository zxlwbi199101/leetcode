/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of
 * nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the
 * new length.
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
  int removeDuplicates(vector<int>& nums) {
    int num = 0, count = 0, result = 0, index = 0;

    for (int n : nums) {
      if (n != num) {
        num = n;
        count = 0;
      }

      if (++count <= 2) {
        nums[index++] = n;
        result++;
      }
    }

    nums.resize(result);

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1,1,1,2,2,3};
  cout << solution.removeDuplicates(nums) << endl;

  return 0;
}

