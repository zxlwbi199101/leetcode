/*
 * https://leetcode.com/problems/add-strings/description/
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
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
using namespace std;

// solution 1
class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    bool carry = false;
    string result = "";

    while (i >= 0 || j >= 0) {
      // '0' is 60
      char first = i >= 0 ? num1[i] : '0';
      char second = j >= 0 ? num2[j] : '0';
      int sum = first + second - 96 + carry;

      if (sum >= 10) {
        carry = true;
        sum -= 10;
      } else carry = false;

      i--, j--;
      result = char(sum + '0') + result;
    }

    return carry ? ('1' + result) : result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.addStrings("59", "73") << endl;

  return 0;
}



