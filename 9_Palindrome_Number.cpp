/*
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
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
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    if (x < 10) return true;

    int reverted = 0;

    // from back to front
    // compare with half of x
    while (reverted < x) {
      reverted = reverted * 10 + x % 10;
      x /= 10;
    }

    cout << reverted << endl;
    cout << x << endl;

    return reverted == x || reverted / 10 == x;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isPalindrome(12) << endl;

  return 0;
}



