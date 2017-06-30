 /*
 * https://leetcode.com/problems/reshape-the-matrix/#/description
 *
 * In MATLAB, there is a very useful function called 'reshape', which can
 * reshape a matrix into a new one with different size but keep its original data.
 * You're given a matrix represented by a two-dimensional array, and two positive
 * integers r and c representing the row number and column number of the wanted
 * reshaped matrix, respectively.
 *
 * The reshaped matrix need to be filled with all the elements of the original
 * matrix in the same row-traversing order as they were.
 *
 * If the 'reshape' operation with given parameters is possible and legal,
 * output the new reshaped matrix; Otherwise, output the original matrix.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int width = nums.size();
    int height = nums[0].size();

    if (width * height != r * c) return nums;

    vector<vector<int>> result(r, vector<int>(c));
    vector<int>* temp = NULL;
    int count = 0;

    for (vector<int> row : nums) {
      for (int n : row) {
        result[count / c][count % c] = n;
        count++;
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> nums;
  vector<int> r1 = {1, 2};
  vector<int> r2 = {3, 2};
  nums.push_back(r1);
  nums.push_back(r2);

  vector<vector<int>> result = solution.matrixReshape(nums, 4, 1);

  for (vector<int> row : result) {
    for (int n : row) {
      cout << n << endl;
    }
    cout << endl;
  }

  return 0;
}


