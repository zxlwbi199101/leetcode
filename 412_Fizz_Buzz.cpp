/*
 * https://leetcode.com/problems/fizz-buzz/#/description
 *
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  vector<string> fizzBuzz(int n) {
    const string THREE = "Fizz";
    const string FIVE = "Buzz";
    const string THREE_FIVE = "FizzBuzz";

    vector<string> result(n);

    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0) {
        result[i - 1] = i % 5 ? THREE : THREE_FIVE;
      } else if (i % 5 == 0) {
        result[i - 1] = FIVE;
      } else {
        result[i - 1] = to_string(i);
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<string> result1 = solution.fizzBuzz(15);
  for (int i = 0; i < result1.size(); ++i) {
    cout << result1[i] << endl;
  }

  return 0;
}
