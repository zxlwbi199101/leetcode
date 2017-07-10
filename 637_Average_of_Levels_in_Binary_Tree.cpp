/*
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/#/description
 *
 * Given a non-empty binary tree, return the average value of the nodes on
 * each level in the form of an array.
 *
 */

#include <iostream>
#include <string>
#include <vector>
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
  vector<double> averageOfLevels(TreeNode* root) {
    if (!root) return vector<double> ();

    vector<double> result;

    TreeNode* temp;

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      double sum = 0;
      int len = que.size();

      for (int i = 0; i < len; i++) {
        temp = que.front();
        que.pop();

        sum += temp -> val;
        if (temp -> left) que.push(temp -> left);
        if (temp -> right) que.push(temp -> right);
      }

      result.push_back(sum * 1.0 / len);
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l3 = {5};
  TreeNode l2 = {2147483647};
  TreeNode l1 = {2147483647};
  TreeNode root = {2147483647};
  root.left = &l1;
  root.right = &l2;
  // l1.left = &l3;

  TreeNode r4 = {7};
  TreeNode r3 = {4};
  TreeNode r2 = {3};
  TreeNode r1 = {1};
  TreeNode root2 = {2};
  root2.left = &r1;
  root2.right = &r2;
  r1.right = &r3;
  r2.right = &r4;

  vector<double> result = solution.averageOfLevels(&root);

  for (double d : result) cout << d << endl;

  return 0;
}


