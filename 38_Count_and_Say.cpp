/*
 * https://leetcode.com/problems/count-and-say/description/
 *
 * The count-and-say sequence is the sequence of integers with the first
 * five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
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
  string countAndSay(int n) {
    string result = "1";

    for (int i = 1; i < n; i++) {
      string cache = "";
      char c = result[0];
      int count = 1;

      for (int j = 1; j < result.size(); j++) {
        if (result[j] == c) count++;
        else {
          cache += to_string(count) + c;
          c = result[j];
          count = 1;
        }
      }
      result = cache + to_string(count) + c;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.countAndSay(6) << endl;

  return 0;
}



