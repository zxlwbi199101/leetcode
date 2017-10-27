/*
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
#include <regex>
#include <stdlib.h>

using namespace std;

// solution 1
class Solution {
public:
  vector<string> result;

  vector<string> generateParenthesis(int n) {
    generate("", n, 0);
    return result;
  }

  void generate(string s, int l, int r) {
    if (l == 0 && r == 0) result.push_back(s);
    else {
      if (l > 0) generate(s + "(", l - 1, r + 1);
      if (r > 0) generate(s + ")", l, r - 1);
    }
  }
};

// test
int main() {
  return 0;
}



