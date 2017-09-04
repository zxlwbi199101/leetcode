/*
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval.
 * For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 *
 * Example 1:
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
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
  int leastInterval(vector<char>& tasks, int n) {
    int taskMap[26] = {};
    int maxCount = 0;

    for (char task : tasks) {
      maxCount = max(maxCount, ++taskMap[task - 'A']);
    }

    int idels = (maxCount - 1) * (n + 1);
    for (int i = 0; i < 26; i++) {
      if (maxCount == taskMap[i]) idels -= (maxCount - 1);
      else idels -= taskMap[i];
    }

    return idels > 0 ? (tasks.size() + idels) : tasks.size();
  }
};

// test
int main() {
  Solution solution;

  vector<char> nums = {'A','A','A','A','A','A','B','C','D','E','F','G'};
  cout << solution.leastInterval(nums, 2) << endl;

  vector<char> nums2 = {'A','A','A','B','B','B'};
  cout << solution.leastInterval(nums2, 2) << endl;

  return 0;
}


