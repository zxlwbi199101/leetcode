/*
 * https://leetcode.com/problems/excel-sheet-column-number/#/description
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  int titleToNumber(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += pow(26, s.size() - i - 1) * (s[i] - 'A' + 1);
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.titleToNumber("C") << endl;
  cout << solution.titleToNumber("Z") << endl;
  cout << solution.titleToNumber("AB") << endl;
  cout << solution.titleToNumber("AZ") << endl;

  return 0;
}


