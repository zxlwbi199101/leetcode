 /*
 * https://leetcode.com/problems/distribute-candies/#/description
 *
 * Given an integer array with even length, where different numbers in this
 * array represent different kinds of candies. Each number means one candy
 * of the corresponding kind. You need to distribute these candies equally in
 * number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    set<int> kinds;

    for (int c : candies) kinds.insert(c);

    int half = candies.size() / 2;
    int kindCount = kinds.size();

    return half > kindCount ? kindCount : half;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,1,2,2,3,3};

  cout << solution.distributeCandies(nums) << endl;
  return 0;
}


