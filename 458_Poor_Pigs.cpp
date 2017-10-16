/*
 * https://leetcode.com/problems/poor-pigs/description/
 *
 * There are 1000 buckets, one and only one of them contains poison, the rest
 * are filled with water. They all look the same. If a pig drinks that poison
 * it will die within 15 minutes. What is the minimum amount of pigs you need
 * to figure out which bucket contains the poison within one hour.
 *
 * Answer this question, and write an algorithm for the follow-up general case.
 *
 * Follow-up:
 *
 * If there are n buckets and a pig drinking poison will die within m minutes,
 * how many pigs (x) you need to figure out the "poison" bucket within p minutes?
 * There is exact one bucket with poison.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    // matrix scan by row and column, so it's
    // buckets <= times ^ pigs
    //
    if (buckets < 2) return 0;
    int times = minutesToTest / minutesToDie + 1;

    int result = times, pigs = 1;
    while (result < buckets) {
      result *= times;
      pigs++;
    }

    return pigs;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,3,2,2,5,2,3,7};
  cout << solution.findLHS(nums) << endl;

  return 0;
}



