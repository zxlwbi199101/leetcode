/*
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists
 * is not allowed.
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// solution 1
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return NULL;
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }

    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }

    bool carry = false;
    while (!s1.empty() || !s2.empty()) {
      int sum = carry;

      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }
      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }

      if (sum >= 10) {
        carry = true;
        sum -= 10;
      } else carry = false;

      s3.push(sum);
    }

    if (carry) s3.push(1);

    ListNode* result = new ListNode(s3.top());
    ListNode* temp = result;
    s3.pop();

    while (!s3.empty()) {
      temp->next = new ListNode(s3.top());
      s3.pop();

      temp = temp->next;
    }

    return result;
  }
};


// test
int main() {
  return 0;
}

