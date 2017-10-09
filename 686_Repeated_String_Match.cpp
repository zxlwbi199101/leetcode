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
    // build prefix table (of B)
    vector<int> prefix(B.size(), 0);
    for (int i = 1, j = 0; i < B.size(); i++) {
      if (B[i] == B[j]) {
        j++;
      } else {
        j = j ? prefix[j - 1] : 0;
        while (j) {
          if (B[i] == B[j]) {
            j++;
            break;
          }
          j--;
        }
      }

      prefix[i] = j;
    }

    // match from A
    // i: B starts from index of A
    // j: index of B
    for (int i = 0, j = 0; i < A.size();) {
      for (; j < B.size(); j++) {
        if (B[j] != A[(i + j) % A.size()]) {
          i += j + 1; // jump to the next
          j = j ? prefix[j] : 0;
          break;
        }
      }

      if (j == B.size()) {
        return (i ? 1 : 0) + ceil((B.size() * 1.0 - i) / A.size());
      }
    }

    return -1;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.repeatedStringMatch("ba", "ab") << endl;

  return 0;
}



