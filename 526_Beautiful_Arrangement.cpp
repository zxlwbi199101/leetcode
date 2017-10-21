/*
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement
 * as an array that is constructed by these N numbers successfully if one of the
 * following is true for the ith position (1 <= i <= N) in this array:
 *
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 * Now given N, how many beautiful arrangements can you construct?
 *
 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation:
 *
 * The first beautiful arrangement is [1, 2]:
 *
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 *
 * The second beautiful arrangement is [2, 1]:
 *
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 * Note:
 * N is a positive integer and will not exceed 15.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<bool> visited = vector<bool> (16, false);
  int result = 0;

  int countArrangement(int N) {
    check(0, N);
    return result;
  }

  void check(int pos, int N) {
    if (pos == N) {
      result++;
      return;
    }

    for (int i = 1; i <= N; i++) {
      int p = pos + 1;
      if (!visited[i] && (i % p == 0 || p % i == 0)) {
        visited[i] = true;
        check(p, N);
        visited[i] = false;
      }
    }
  }
};


// test case
int main() {
  return 0;
}
