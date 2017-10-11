/*
 * https://leetcode.com/problems/count-primes/description/
 *
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
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
  int countPrimes(int n) {
    if (n <= 2) return 0;
    if (n % 2 == 0) n++;
    // 0 1 2 3 4
    // 1 3 5 7 9
    vector<bool> isPrime ((n + 1) / 2, true);

    for (int i = 1; i < (n + 1) / 2; i++) {
      int realIndex = (i * 2) + 1;
      if (!isPrime[i] || realIndex > n / realIndex) continue;

      for (int j = realIndex * realIndex; j > 0 && j <= n; j += 2 * realIndex) {
        isPrime[(j - 1) / 2] = false;
      }
    }

    int result = 0; // 2 is a prime, but 1 is not
    for (int i = 0; i < isPrime.size() - 1; i++) {
      if (isPrime[i]) result++;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.countPrimes(10) << endl;

  return 0;
}



