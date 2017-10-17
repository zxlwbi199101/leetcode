/*
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* next = head->next;
    ListNode* prev = NULL;

    while (fast && slow) {
      fast = fast->next->next;

      // reverse first half
      slow->next = prev;
      prev = slow;
      slow = next;
      next = slow->next;

      if (!fast) {
        next = slow;
        slow = prev;
        break;
      }
      if (!fast->next) {
        slow = prev;
        break;
      }
    }

    while (next || slow) {
      if (!next || !slow) return false;
      if (next->val != slow->val) return false;
      next = next->next;
      slow = slow->next;
    }

    return true;
  }
};


// test
int main() {
  Solution solution;
  // cout << solution.wordPattern("abba", "dog cat cat dog") << endl;
  return 0;
}


