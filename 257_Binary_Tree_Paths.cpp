/*
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
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
  vector<string> result;

  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return result;
    walk(root, "");
    return result;
  }

  void walk(TreeNode* node, string parent) {
    parent += to_string(node->val);

    if (!node->left && !node->right) {
      result.push_back(parent);
      return;
    }
    if (node->left) walk(node->left, parent + "->");
    if (node->right) walk(node->right, parent + "->");
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


