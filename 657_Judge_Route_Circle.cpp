/*
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to the
 * original place.
 *
 * The move sequence is represented by a string. And each move is represent by
 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D
 * (down). The output should be true or false representing whether the robot
 * makes a circle.
 *
 * Example 1:
 * Input: "UD"
 * Output: true
 * Example 2:
 * Input: "LL"
 * Output: false
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
  bool judgeCircle(string moves) {
    int l = 0, u = 0;
    for (char c : moves) {
      if (c == 'L') l++;
      else if (c == 'R') l--;
      else if (c == 'U') u++;
      else if (c == 'D') u--;
    }

    return !l && !u;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.judgeCircle("LLUUDDRR") << endl;

  return 0;
}



