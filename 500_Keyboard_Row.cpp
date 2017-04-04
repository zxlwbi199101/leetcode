/*
 * https://leetcode.com/problems/keyboard-row/#/description
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image below.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
private:
  const char* keyboard;

public:
  Solution() {
    keyboard = "23321222122233111121131313";
  }

  vector<string> findWords(vector<string>& words) {
    vector<string> result;

    for (int i = 0, len = words.size(); i < len; i++) {
      if (isInSameLine(words[i])) {
        result.push_back(words[i]);
      }
    }

    return result;
  }

  bool isInSameLine(string& word) {
    const char* str = word.c_str();
    char same = '\0';
    short current;

    for (int i = 0, len = word.size(); i < len; ++i) {
      current = str[i] - (str[i] >= 'a' ? 'a' : 'A');
      if (same != '\0' && same != keyboard[current]) {
        return false;
      }
      same = keyboard[current];
    }

    return true;
  }
};


// test
int main() {
  Solution solution;

  vector<string> test1;
  test1.push_back("asdf");
  test1.push_back("Hello");
  test1.push_back("asdq");
  test1.push_back("asdz");
  vector<string> result1 = solution.findWords(test1);
  for (int i = 0; i < result1.size(); ++i) {
    cout << result1[i] << endl;
  }

  return 0;
}
