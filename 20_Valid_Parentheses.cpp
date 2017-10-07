/*
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * Given a string containing just the characters '(', ')', '{', '}',
 * '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
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
  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if (c == '{' || c == '(' || c == '[') stk.push(c);
      else if (
        !stk.empty() &&
        ((c == '}' && stk.top() == '{') ||
        (c == ')' && stk.top() == '(') ||
        (c == ']' && stk.top() == '['))
      ) {
        stk.pop();
      } else return false;
    }

    return stk.empty();
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isValid("()[]{}") << endl;

  return 0;
}



