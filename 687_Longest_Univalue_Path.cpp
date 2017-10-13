/*
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * Given a binary tree, find the length of the longest path where each node
 * in the path has the same value. This path may or may not pass through the
 * root.
 *
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 *
 * Example 1:
 *
 * Input:
 *
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 * Output:
 *
 * 2
 * Example 2:
 *
 * Input:
 *
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 * Output:
 *
 * 2
 * Note: The given binary tree has not more than 10000 nodes. The height of
 * the tree is not more than 1000.
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <set>
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
  int sum;
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    sum = 0;
    find(root);
    return sum;
  }

  int find(TreeNode* node) {
    int maxL = 0, maxR = 0;

    if (node->left) {
      int l = find(node->left);
      if (node->left->val == node->val) maxL += l + 1;
    }
    if (node->right) {
      int r = find(node->right);
      if (node->right->val == node->val) maxR += r + 1;
    }

    sum = max(sum, maxL + maxR);

    return max(maxL, maxR);
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_1 = {1};
  TreeNode l_2 = {4};
  TreeNode l_3 = {1};
  TreeNode l_4 = {2};
  TreeNode l_5 = {4};
  TreeNode l_6 = {1};

  l_2.left = &l_4;
  l_2.right = &l_5;
  l_3.right = &l_6;
  l_1.left = &l_2;
  l_1.right = &l_3;

  cout << solution.longestUnivaluePath(&l_1) << endl;

  return 0;
}


