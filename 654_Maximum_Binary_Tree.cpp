/*
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 *
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 *
 * Example 1:
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *
 *       6
 *     /   \
 *    3     5
 *     \    /
 *      2  0
 *        \
 *         1
 * Note:
 * The size of the given array will be in the range [1,1000].
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <link>
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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    list<TreeNode*> l;

    for (int i = 0; i < nums.size(); i++) {
      TreeNode* node = new TreeNode(nums[i]);

      if (i > 0 && nums[i] < nums[i - 1]) {
        l.back()->right = node;
      } else {
        TreeNode* last = NULL;

        while (!l.empty()) {
          if (l.back()->val > nums[i]) {
            l.back()->right = node;
            break;
          }
          last = l.back();
          l.pop_back();
        }

        node->left = last;
      }
      l.push_back(node);
    }

    return l.front();
  }
};


// test
int main() {
  Solution solution;
  return 0;
}


