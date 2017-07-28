/*
 * https://leetcode.com/problems/pascals-triangle-ii/tabs/description
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 *
 * 1  n  n(n-1)  n(n-1)(n-2)
 * 1  1  1*2     1*2*3
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    long comb = 1;

    vector<int> result (rowIndex + 1);

    for (int i = 0; i < rowIndex / 2 + 1; i++) {
      result[i] = result[rowIndex - i] = comb;
      comb *= rowIndex - i;
      comb /= i + 1;
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> res = solution.getRow(30);

  for (int i : res) cout << i << endl;

  return 0;
}


