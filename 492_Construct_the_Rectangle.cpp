/*
 * https://leetcode.com/problems/construct-the-rectangle/#/description
 *
 * For a web developer, it is very important to know how to design a web page's size.
 * So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page,
 * whose length L and width W satisfy the following requirements:
 *
 * 1. The area of the rectangular web page you designed must equal to the given target area.
 * 2. The width W should not be larger than the length L, which means L >= W.
 * 3. The difference between length L and width W should be as small as possible.
 *
 * You need to output the length L and the width W of the web page you designed in sequence.
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


// solution 1
class Solution {
public:
  vector<int> constructRectangle(int area) {
    int l = pow(area, 0.5);

    while (area % l != 0) {
      l++;
    }

    if (l < area / l) {
      l = area / l;
    }

    vector<int> result = {l, area / l};
    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> result = solution.constructRectangle(20);

  for (int i : result) {
    cout << i << ',';
  }
  cout << endl;

  return 0;
}
