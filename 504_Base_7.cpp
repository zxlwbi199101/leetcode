/*
 * https://leetcode.com/problems/base-7/#/description
 *
 * Given an integer, return its base 7 string representation.
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  string convertToBase7(int num) {
    if (num < 7 && num > -7) return to_string(num);

    string result = "";
    int temp = abs(num);
    int current = 7;

    while (temp) {
      result = to_string(temp % 7) + result;
      temp = temp / 7;
    }

    return (num > 0 ? "" : "-") + result;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.convertToBase7(-2) << endl;

  return 0;
}


