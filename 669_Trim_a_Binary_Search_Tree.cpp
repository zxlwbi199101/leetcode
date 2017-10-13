/*
 * https://leetcode.com/problems/trim-a-binary-search-tree/description/
 *
 * Given a binary search tree and the lowest and highest boundaries as L
 * and R, trim the tree so that all its elements lies in [L, R] (R >= L). You
 * might need to change the root of the tree, so the result should return the
 * new root of the trimmed binary search tree.
 *
 * Example 1:
 * Input:
 *     1
 *    / \
 *   0   2
 *
 *   L = 1
 *   R = 2
 *
 * Output:
 *     1
 *       \
 *        2
 * Example 2:
 * Input:
 *     3
 *    / \
 *   0   4
 *    \
 *     2
 *    /
 *   1
 *
 *   L = 1
 *   R = 3
 *
 * Output:
 *       3
 *      /
 *    2
 *   /
 *  1
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
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) return NULL;
    if (root->val < L) return trimBST(root->right, L, R);
    if (root->val > R) return trimBST(root->left, L, R);

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_1 = {3};
  TreeNode l_2 = {0};
  TreeNode l_3 = {4};
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


