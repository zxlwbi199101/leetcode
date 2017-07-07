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

    qsortIterative(copy);

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

  vector<int> v = {2,5,4,3,6,7,8,0,9,13,76,15};
  vector<string> result = solution.findRelativeRanks(v);

  for (string s : result) {
    cout << s << endl;
  }

  // vector<int> nums = {2,5,4,3,6,7,8,0,9,13,76,15};

  // solution.qsortIterative(nums);
  // for (int i : nums) {
  //   cout << i << endl;
  // }

  return 0;
}


