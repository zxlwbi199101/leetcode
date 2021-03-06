/*
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself.
 *
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * Example:
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * Note: The input number n will not exceed 100,000,000. (1e8)
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
  bool checkPerfectNumber(int num) {
    if (num == 1) return false;
    int sum = 0;

    for (int i = 2; i * i < num; i++) {
      if (num % i == 0) {
        sum += i + num / i;
      }
    }

    return sum + 1 == num;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.checkPerfectNumber(6) << endl;

  return 0;
}



