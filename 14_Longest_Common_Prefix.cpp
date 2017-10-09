/*
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * Write a function to find the longest common prefix string amongst an
 * array of strings.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = "";

    for (int i = 0; ; i++) {
      char c = '\0';

      for (int j = 0; j < strs.size(); j++) {
        if (strs[j].size() <= i) return result;

        if (!j) c = strs[j][i];
        else if (c != strs[j][i]) return result;
      }

      result += c;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.longestCommonPrefix(vector<string> {
    "asdf",
    "asdfa",
    "asdfbb"
  }) << endl;

  return 0;
}



