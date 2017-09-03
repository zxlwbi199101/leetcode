/*
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should
 * be a unique set of numbers.
 *
 * Example 1:
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 * Example 2:
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
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
  struct Meta {
    int sum;
    int num;
    int len;
    vector<int> list;
    Meta(int s, int n, int l, vector<int> list) :
    sum(s), num(n), len(l), list(list) {};
  };

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    stack<Meta> s;

    s.push(Meta(0, 0, 0, vector<int>(k)));

    while (!s.empty()) {
      Meta m = s.top();
      s.pop();

      if (m.len == k - 1) {
        if (n - m.sum > m.num && n - m.sum <= 9) {
          m.list[m.len] = n - m.sum;
          result.push_back(m.list);
        }

        continue;
      }

      for (int i = m.num + 1; i < 10; i++) {
        vector<int> l = vector<int> (m.list);
        l[m.len] = i;
        s.push(Meta(m.sum + i, i, m.len + 1, l));
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  for (vector<int> row : solution.combinationSum3(1, 1)) {
    for (int i : row) cout << i << " ";
    cout << endl;
  }

  return 0;
}


