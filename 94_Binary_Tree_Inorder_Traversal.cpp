/*
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 *
 * Example 1:
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * Note: The length of the input array will not exceed 20,000.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    TreeNode* cur = root;

    while (cur) {
      s.push(cur);
      cur = cur->left;
    }

    while (!s.empty()) {
      cur = s.top();
      s.pop();
      result.push_back(cur->val);

      if (cur->right) {
        cur = cur->right;

        while (cur) {
          s.push(cur);
          cur = cur->left;
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



