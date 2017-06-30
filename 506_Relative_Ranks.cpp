/*
 * https://leetcode.com/problems/relative-ranks/#/description
 *
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


// solution 1
class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<string> result;
    vector<int> copy (nums);
    map<int, int> scoreRank;

    qsortIterate(copy);

    for (int i = 0, len = nums.size(); i < len; i++) {
      scoreRank[copy[i]] = len - i - 1;
    }

    for (int i : nums) {
      int rankInt = scoreRank[i];
      string rank;

      if (rankInt == 0) rank = "Gold Medal";
      else if (rankInt == 1) rank = "Silver Medal";
      else if (rankInt == 2) rank = "Bronze Medal";
      else rank = to_string(rankInt + 1);

      result.push_back(rank);
    }

    return result;
  }

  void qsortIterate(vector<int>& nums) {
    queue<int> que;
    int all = 0;

    que.push(0);
    que.push(nums.size() - 1);

    while (!que.empty()) {
      int start = que.front();
      que.pop();

      int end = que.front();
      que.pop();

      if (start >= end) continue;

      int first = start;
      int last = end;
      int pivot = nums[start];

      while (first < last) {
        while (first < last && nums[last] > pivot) last--;
        while (first < last && nums[first] <= pivot) first++;

        if (first < last && nums[last] < nums[first]) swap(nums[last], nums[first]);
      }

      if (pivot > nums[first]) {
        swap(nums[start], nums[first]);
      }

      que.push(last + 1);
      que.push(end);
      que.push(start);
      que.push(first);
    }
  }
};

// test
int main() {
  Solution solution;

  vector<int> v = {2,5,4,3,6,7,8,0,9,13,76,15};
  vector<string> result = solution.findRelativeRanks(v);

  for (string s : result) {
    cout << s << endl;
  }

  // vector<int> nums = {2,5,4,3,6,7,8,0,9,13,76,15};

  // solution.qsortIterate(nums);
  // for (int i : nums) {
  //   cout << i << endl;
  // }

  return 0;
}


