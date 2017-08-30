/*
 * https://leetcode.com/problems/image-smoother/description/
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you need
 * to design a smoother to make the gray scale of each cell becomes the average
 * gray scale (rounding down) of all the 8 surrounding cells and itself. If a
 * cell has less than 8 surrounding cells, then use as many as you can.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (!M.size() || !M[0].size()) {
      return vector<vector<int>> (0);
    }

    int h = M.size();
    int w = M[0].size();

    vector<vector<int>> result;
    for (int i = 0; i < h; i++) {
      result.push_back(vector<int> (w));
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int sum = 0;
        int counter = 0;

        for (int m = i - 1; m <= i + 1; m++) {
          for (int n = j - 1; n <= j + 1; n++) {
            if (m >= 0 && m < h && n >= 0 && n < w) {
              sum += M[m][n];
              counter++;
            }
          }
        }

        result[i][j] = sum / counter;
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,1,1};
  vector<int> nums2 = {1,0,1};
  vector<int> nums3 = {1,1,1};
  vector<vector<int>> matrix = {nums1, nums2, nums3};

  vector<vector<int>> result = solution.imageSmoother(matrix);
  for (vector<int> i : result) {
    for (int j : i) {
      cout << j << ",";
    }
    cout << endl;
  }
  return 0;
}


