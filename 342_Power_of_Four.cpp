/*
 * https://leetcode.com/problems/power-of-four/description/
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num <= 0) return false;
    return num == 1 || 1073741824 % num == 0 && (1431655765 | num) == 1431655765;
  }
};


// test
int main() {
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(1);

  Solution solution;
  solution.mergeTwoLists(l1, l2);
  return 0;
}


