/*
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    vector<int> temp (1, 1);

    if (!numRows) return result;
    if (numRows >= 1) {
      result.push_back(temp);
    }

    for (int len = 2; len < numRows + 1; len++) {
      for (int i = (len + 1) / 2 - 1; i >= 1; i--) {
        temp[len - i - 1] = temp[i] = temp[i - 1] + temp[i];
      }

      temp.push_back(1);

      vector<int> newVec (temp);
      result.push_back(newVec);
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> res = solution.generate(10);

  for (vector<int> vec : res) {
    for (int i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}


