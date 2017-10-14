/*
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 *
 * Example 1:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * Example 2:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return false.
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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    string source = formString(s);
    string target = formString(t);

    return source.find(target) != string::npos;
  }

  string formString(TreeNode* root) {
    string l = root->left ? formString(root->left) : "l";
    string r = root->right ? formString(root->right) : "r";

    return "v" + to_string(root->val) + " " + l + " " + r;
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


