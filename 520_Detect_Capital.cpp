/*
 * https://leetcode.com/problems/detect-capital/#/description
 *
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 *
 * We define the usage of capitals in a word to be right when one of the following
 * cases holds:
 *
 * 1. All letters in this word are capitals, like "USA".
 * 2 .All letters in this word are not capitals, like "leetcode".
 * 3. Only the first letter in this word is capital if it has more than one letter,
 * like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  bool detectCapitalUse(string word) {
    vector<int> pos;

    for (int i = 0, size = word.size(); i < size; i++) {
      if (word[i] <= 'Z') {
        pos.push_back(i);
      } else if (pos.size() > 1) {
        return false;
      }
    }

    if ((pos.size() == 1 && pos[0] > 0) ||
      (pos.size() > 1 && pos.size() != word.size())) {
      return false;
    }

    return true;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.detectCapitalUse("Google") << endl;
  cout << solution.detectCapitalUse("USA") << endl;
  cout << solution.detectCapitalUse("FlaG") << endl;
  cout << solution.detectCapitalUse("asdf") << endl;

  return 0;
}


