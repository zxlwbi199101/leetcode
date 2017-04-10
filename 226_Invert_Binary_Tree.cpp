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
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;

    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      temp = q.front();
      swap(temp);
      q.pop();

      if (temp -> left) q.push(temp -> left);
      if (temp -> right) q.push(temp -> right);
    }

    return root;
  }

private:
  void swap(TreeNode* target) {
    TreeNode* temp;

    temp = target -> right;
    target -> right = target -> left;
    target -> left = temp;
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

  cout << solution.invertTree(&root) -> right -> val << endl;

  return 0;
}


