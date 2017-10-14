/*
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * For example:
 * Given BST [1,null,2,2],
 *    1
 *     \
 *      2
 *     /
 *    2
 * return [2].
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space? (Assume that
 * the implicit stack space incurred due to recursion does not count).
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
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
  vector<int> result;
  int maxCount;
  int count;
  int value;

  vector<int> findMode(TreeNode* root) {
    if (!root) return result;
    value = root->val;

    walk(root);
    return result;
  }

  void walk(TreeNode* node) {
    if (node->left) walk(node->left);

    if (value == node->val) {
      count++;
    } else {
      value = node->val;
      count = 1;
    }

    if (count > maxCount) {
      result.clear();
      result.push_back(value);
      maxCount = count;
    } else if (count == maxCount) {
      result.push_back(value);
    }

    // value will not lost after walk-left
    // because BST cannot have the same value when
    // right = left && left.right > left
    if (node->right) walk(node->right);
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


