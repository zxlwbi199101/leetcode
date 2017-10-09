/*
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * Count the number of segments in a string, where a segment is defined to
 * be a contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  int countSegments(string s) {
    int result = 0;
    bool entered = false;

    for (char c : s) {
      if (isspace(c)) {
        entered = false;
      } else {
        if (!entered) result++;
        entered = true;
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.countSegments("Hello, my name is John") << endl;

  return 0;
}



