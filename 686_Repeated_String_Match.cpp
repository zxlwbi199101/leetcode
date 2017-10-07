/*
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 *
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 *
 * Note:
 * The length of A and B will be between 1 and 10000.
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
  int repeatedStringMatch(string A, string B) {
    int start = 0;
    for (; start < A.size(); start++) {
      if (A[start] == B[0]) break;
      else if (start == A.size() - 1) return -1;
    }

    int result = start ? 1 : 0;

    for (int i = 0; i < B.size(); i++, start++) {
      if (A[start % A.size()] != B[i]) return -1;
      else if (!(start % A.size())) result++;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.repeatedStringMatch("abcd", "cdabcdab") << endl;

  return 0;
}



