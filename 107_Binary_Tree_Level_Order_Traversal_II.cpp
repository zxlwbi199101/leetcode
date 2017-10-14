/*
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return vector<vector<int>> {};

    vector<vector<int>> result = {{}};
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    TreeNode* temp;

    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
      if (q1.empty()) {
        while (!q2.empty()) {
          temp = q2.front();
          q2.pop();

          if (temp->left) q1.push(temp->left);
          if (temp->right) q1.push(temp->right);
        }

        if (!q1.empty()) result.insert(result.begin(), vector<int>());
      } else {
        temp = q1.front();
        q1.pop();
        q2.push(temp);
        result[0].push_back(temp->val);
      }
    }

    return result;
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


