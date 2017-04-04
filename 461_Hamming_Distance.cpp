// solution 1

// class Solution {
// public:
//   int hammingDistance(int x, int y) {
//     int diff = x ^ y;
//     int count = 0;

//     while (diff > 0) {
//       if (diff & 1) {
//         count++;
//       }

//       diff >>= 1;
//     }

//     return count;
//   }
// };

// solution 2

class Solution {
public:
  int hammingDistance(int x, int y) {
    int diff = x ^ y;
    int count = 0;

    while (diff) {
      count++;
      diff &= diff - 1;
    }

    return count;
  }
};

// test case
#include <iostream>
using namespace std;

int main() {
  Solution solution;
  cout << solution.hammingDistance(1, 4) << endl;
  cout << solution.hammingDistance(2, 4) << endl;

  return 0;
}