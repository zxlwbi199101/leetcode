/*
 * https://leetcode.com/problems/sum-of-left-leaves/#/description
 *
 * Find the sum of all left leaves in a given binary tree.
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
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    stack<TreeNode*> stk;
    stk.push(root);

    TreeNode* temp = NULL;
    int sum = 0;

    while (!stk.empty()) {
      temp = stk.top();
      stk.pop();

      if (temp -> left && !temp -> left -> left && !temp -> left -> right) {
        sum += temp -> left -> val;
      } else if (temp -> left) {
        stk.push(temp -> left);
      } else if (temp -> right) {
        stk.push(temp -> right);
      }
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_3 = {1};
  TreeNode l_2 = {2};
  TreeNode l_1 = {3};
  TreeNode root = {4};
  root.left = &l_1;
  root.right = &l_2;
  l_1.left = &l_3;

  cout << solution.sumOfLeftLeaves(&root) << endl;

  return 0;
}


