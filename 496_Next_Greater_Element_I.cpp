/*
 * https://leetcode.com/problems/next-greater-element-i/#/description
 *
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s
 * elements are subset of nums2. Find all the next greater numbers for nums1's
 * elements in the corresponding places of nums2.
 *
 * The Next Greater Number of a number x in nums1 is the first greater number
 * to its right in nums2. If it does not exist, output -1 for this number.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;


// solution 1
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    unordered_map<int, int> m;
    stack<int> s;

    for (int n : nums) {
      while (!s.empty() && n > s.top()) {
        m[s.top()] = n;
        s.pop();
      }
      s.push(n);
    }

    for (int i = 0, len = findNums.size(); i < len; i++) {
      findNums[i] = m.count(findNums[i]) ? m[findNums[i]] : -1;
    }

    return findNums;
  }
};


// test
int main() {
  Solution solution;

  vector<int> first = {4, 1, 2};
  vector<int> second = {1, 3, 4, 2};
  solution.nextGreaterElement(first, second);

  for (int i : first) {
    cout << i << ',';
  }
  cout << endl;


  vector<int> first2 = {2, 4};
  vector<int> second2 = {1, 2, 3, 4};
  solution.nextGreaterElement(first2, second2);

  for (int i : first2) {
    cout << i << ',';
  }
  cout << endl;

  return 0;
}
