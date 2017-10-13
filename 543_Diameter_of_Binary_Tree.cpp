/*
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through
 * the root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
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
  int length;
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    find(root);
    return length;
  }

  int find(TreeNode* root) {
    int maxL = 0, maxR = 0, m = 0;

    if (root->left) {
      maxL = find(root->left) + 1;
      m += maxL;
    }
    if (root->right) {
      maxR = find(root->right) + 1;
      m += maxR;
    }

    length = max(length, m);
    return max(maxR, maxL);
  }
};


// test
int main() {
  Solution solution;

  // TreeNode l_1 = {3};
  // TreeNode l_2 = {0};
  // TreeNode l_3 = {4};
  // TreeNode l_4 = {2};
  // TreeNode l_5 = {4};
  // TreeNode l_6 = {1};

  // l_2.left = &l_4;
  // l_2.right = &l_5;
  // l_3.right = &l_6;
  // l_1.left = &l_2;
  // l_1.right = &l_3;

  // cout << solution.longestUnivaluePath(&l_1) << endl;

  return 0;
}


