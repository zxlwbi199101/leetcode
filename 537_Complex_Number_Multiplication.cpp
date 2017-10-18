/*
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * Given two strings representing two complex numbers.
 *
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 *
 * Example 1:
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * Example 2:
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * Note:
 *
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  string complexNumberMultiply(string a, string b) {
    int r1 = 0, r2 = 0, v1 = 0, v2 = 0;
    int start = 0;

    r1 = toInt(a, &start);
    v1 = toInt(a, &start);
    start = 0;
    r2 = toInt(b, &start);
    v2 = toInt(b, &start);

    return to_string(r1 * r2 - v1 * v2) + '+' + to_string(r1 * v2 + r2 * v1) + 'i';
  }

  int toInt(string s, int* pstart) {
    int sign = 1, ret = 0;

    for (int i = *pstart; i < s.size() - 1; i++, (*pstart)++) {
      char digit = s[i];

      if (digit == '-') sign = -1;
      else if (digit == '+') {
        (*pstart)++;
        return ret * sign;
      } else ret = ret * 10 + (digit - '0');
    }

    return ret * sign;
  }
};


// test
int main() {
  return 0;
}


