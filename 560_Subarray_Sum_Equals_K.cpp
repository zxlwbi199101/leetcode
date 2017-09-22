/*
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Design a data structure that supports all following operations in
 *  average O(1) time.
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element
 * must have the same probability of being returned.
 * Example:
 *
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
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

class RandomizedSet {
private:
  unordered_map<int, int> m;
  vector<int> v;
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (m.find(val) == m.end()) {
      v.push_back(val);
      m[val] = v.size() - 1;
      return false;
    }

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end()) return false;

    int last = v.back();
    v[it->second] = v.back();
    m[last] = it->second;
    v.pop_back();

    return m.erase(val) > 0;
  }

  /** Get a random element from the set. */
  int getRandom() {
    if (!m.size()) return 0;
    return v[rand() % v.size()];
  }
};

// test
int main() {
  RandomizedSet obj = RandomizedSet();
  cout << obj.insert(1) << endl;
  cout << obj.remove(2) << endl;
  cout << obj.insert(2) << endl;
  cout << "get: " << obj.getRandom() << endl;
  cout << obj.remove(1) << endl;
  cout << obj.insert(2) << endl;
  cout << "get: " << obj.getRandom() << endl;

  return 0;
}


