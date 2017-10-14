/*
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *       10
 *      /  \
 *     5   -3
 *    / \    \
 *   3   2   11
 *  / \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
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
  unordered_map<int, int> m;

  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    m[0] = 1;

    return find(root, sum, 0);
  }

  int find(TreeNode* node, int sum, int current) {
    current += node->val;

    int prev = m[current];
    int count = m[current - sum]; // allsum - sum = from top to any nodes
    m[current] = prev + 1;

    if (node->left) count += find(node->left, sum, current);
    if (node->right) count += find(node->right, sum, current);

    m[current] = prev;

    return count;
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


