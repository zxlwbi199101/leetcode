/*
 * https://leetcode.com/problems/maximum-product-of-three-numbers/#/description
 *
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int maxes[3] = {INT_MIN, INT_MIN, INT_MIN};
    int mins[2] = {INT_MAX, INT_MAX};

    for (int i : nums) {
      if (i < mins[0]) {
        mins[1] = mins[0];
        mins[0] = i;
      } else if (i < mins[1]) {
        mins[1] = i;
      }

      if (i > maxes[0]) {
        maxes[2] = maxes[1];
        maxes[1] = maxes[0];
        maxes[0] = i;
      } else if (i > maxes[1]) {
        maxes[2] = maxes[1];
        maxes[1] = i;
      } else if (i > maxes[2]) {
        maxes[2] = i;
      }
    }

    int negProduct = maxes[0] * mins[0] * mins[1];
    int posProduct = maxes[0] * maxes[2] * maxes[1];

    return max(negProduct, posProduct);
  }
};


// test
int main() {
  Solution solution;
  vector<int> v = {9,1,5,6,7,2};

  cout << solution.maximumProduct(v) << endl;

  return 0;
}


