/*
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
 *
 * Examples 1
 * Input:
 *
 *   5
 *  /  \
 * 2   -3
 * return [2, -3, 4], since all the values happen only once, return all of them in any order.
 * Examples 2
 * Input:
 *
 *   5
 *  /  \
 * 2   -5
 * return [2], since 2 happens twice, however -5 only occur once.
 * Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
  unordered_map<int, int> m;
  int maxFreq = INT_MAX;

  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    calculate(root);
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second == maxFreq) result.push_back(it->first);
    }

    return result;
  }

  int calculate(TreeNode* root) {
    int sum = root->val;
    if (root->left) sum += calculate(root->left);
    if (root->right) sum += calculate(root->right);

    m[sum]++;
    maxFreq = max(maxFreq, m[sum]);
    return sum;
  }
};


// test
int main() {
  return 0;
}


