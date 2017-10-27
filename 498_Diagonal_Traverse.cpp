/*
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements
 * of the matrix in diagonal order as shown in the below image.
 *
 * Example:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 * Explanation:
 *
 * Note:
 * The total number of elements of the given matrix will not exceed 10,000.
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (!matrix.size()) return result;

    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = 0;
    bool isUp = true;

    while (true) {
      if (i == m - 1 && j == n - 1) {
        result.push_back(matrix[i][j]);
        return result;
      }
      result.push_back(matrix[i][j]);

      if (isUp) {
        // normal
        if (j < n - 1 && i > 0) {
          j++;
          i--;
        } else {
          if (j == n - 1) i++;
          else j++;
          isUp = false;
        }
      } else {
        // normal
        if (i < m - 1 && j > 0) {
          j--;
          i++;
        } else {
          if (i == m - 1) j++;
          else i++;
          isUp = true;
        }
      }
    }

    return result;
  }
};


// test
int main() {
  return 0;
}

