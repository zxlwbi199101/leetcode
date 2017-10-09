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
  // string longestCommonPrefix(vector<string>& strs) {
  //   if (!strs.size()) return "";
  //   string result = "";

  //   for (int i = 0; ; i++) {
  //     char c = '\0';

  //     for (int j = 0; j < strs.size(); j++) {
  //       if (strs[j].size() <= i) return result;

  //       if (!j) c = strs[j][i];
  //       else if (c != strs[j][i]) return result;
  //     }

  //     result += c;
  //   }

  //   return result;
  // }

  string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) return "";

    for (int i = 0; i < strs[0].size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j].size() <= i || strs[j][i] != strs[0][i])
          return strs[0].substr(0, i);
      }
    }

    return strs[0];
  }
};

// test
int main() {
  Solution solution;

  vector<string> strs = {
    "asdf",
    "asdfa",
    "asdfbb"
  };

  cout << solution.longestCommonPrefix(strs) << endl;

  return 0;
}



