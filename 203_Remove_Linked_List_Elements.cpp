/*
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* h = NULL;

    while (head) {
      // skip heading values
      if (!h) {
        if (head->val == val) {
          head = head->next;
          continue;
        }
        h = head;
      }
      if (head->next && head->next->val == val) {
        head->next = head->next->next;
      } else {
        head = head->next;
      }
    }

    return h;
  }
};


// test
int main() {
  Solution solution;
  return 0;
}


