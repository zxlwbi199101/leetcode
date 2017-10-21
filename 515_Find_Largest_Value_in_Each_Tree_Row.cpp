/*
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 * Input:
 *
 *           1
 *          / \
 *         3   2
 *        / \   \
 *       5   3   9
 *
 * Output: [1, 3, 9]
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> result;

    queue<TreeNode*> q;
    if (root) q1.push(root);

    while (!q.empty()) {
      int len = q.size(), m = INT_MIN;

      for (int i = 0; i < len; i++) {
        TreeNode* temp = q.front();
        q.pop();

        m = max(m, temp->val);
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
      }

      result.push_back(m);
    }

    return result;
  }
};


// test case
int main() {
  return 0;
}
