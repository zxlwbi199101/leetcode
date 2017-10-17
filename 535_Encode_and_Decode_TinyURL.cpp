/*
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL
 * such as http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  string TABLE = "qrsLM456CnoNfghijkOPm3RwFyzAvelIJDpGHxQtuXYZ1278KEabcdSTUVWB9";
  unordered_map<string, string> db;

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    int idx = db.size() + 1;
    string s = "";

    while (!idx) {
      s += TABLE[idx % 61];
      idx /= 61;
    }

    db[s] = longUrl;
    return s;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return db[shortUrl];
  }
};

// test
int main() {
  return 0;
}


