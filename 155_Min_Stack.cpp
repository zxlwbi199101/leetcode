/*
 * https://leetcode.com/problems/min-stack/description/
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class MinStack {
public:
  list<int> l;
  int m;

  /** initialize your data structure here. */
  MinStack() {
    m = INT_MAX;
  }

  void push(int x) {
    l.push_back(x);
    m = min(x, m);
  }

  void pop() {
    if (l.empty()) return;

    int first = l.back();
    l.pop_back();

    if (first == m) {
      m = INT_MAX;
      for (auto it = l.begin(); it != l.end(); ++it) {
        m = min(*it, m);
      }
    }
  }

  int top() {
    return l.back();
  }

  int getMin() {
    return m;
  }
};

// test
int main() {
  MinStack obj = MinStack();
  obj.push(5);
  obj.pop();
  int param_3 = obj.top();
  int param_4 = obj.getMin();

  return 0;
}



