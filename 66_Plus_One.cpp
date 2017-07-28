/*
 * https://leetcode.com/problems/plus-one/tabs/description
 *
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0
    }

    digits.insert(digits.begin(), 1);

    return digits;
  }
};


// test
int main() {
  Solution solution;

  vector<int> digits = {2,5,6,7,9,8,9};
  vector<int> res = solution.plusOne(digits);

  for (int i : res) cout << i << endl;

  return 0;
}


