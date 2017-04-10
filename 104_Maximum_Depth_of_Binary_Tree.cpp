/*
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description
 *
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from
 * the root node down to the farthest leaf node.
 *
 */

#include <iostream>
#include <string>
#include <queue>
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
  int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);
    root -> val = 1;

    TreeNode* temp;

    while (!q.empty()) {
      temp = q.front();
      q.pop();

      if (temp -> left) {
        temp -> left -> val = temp -> val + 1;
        q.push(temp -> left);
      }
      if (temp -> right) {
        temp -> right -> val = temp -> val + 1;
        q.push(temp -> right);
      }
    }

    return temp -> val;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_3 = {0};
  TreeNode l_2 = {0};
  TreeNode l_1 = {0};
  TreeNode root = {0};
  root.left = &l_1;
  l_1.left = &l_2;
  l_2.left = &l_3;

  cout << solution.maxDepth(&root) << endl;

  return 0;
}


