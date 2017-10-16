/*
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// solution 1
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* origin = NULL;
    ListNode* temp = NULL;

    while (l1 || l2) {
      if (!l1) temp = l2;
      else if (!l2) temp = l1;
      else if (l1->val > l2->val) temp = l2;
      else temp = l1;

      if (head) head->next = temp;
      else {
        head = temp;
        origin = temp;
      }

      if (temp == l1) l1 = l1->next;
      else l2 = l2->next;

      head = temp;
    }

    return origin;
  }
};


// test
int main() {
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(1);

  Solution solution;
  solution.mergeTwoLists(l1, l2);
  return 0;
}


