/*
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return find(nums, 0, nums.size() - 1);
  }

  TreeNode* find(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    if (start == end) {
      return new TreeNode(nums[start]);
    }
    int mid = start + (end - start) / 2; // avoid overflow

    TreeNode* t = new TreeNode(nums[mid]);
    t->left = find(nums, start, mid - 1);
    t->right = find(nums, mid + 1, end);

    return t;
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


