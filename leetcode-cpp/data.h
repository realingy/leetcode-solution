#ifndef __DATA_H__
#define __DATA_H__

#include <deque>
#include <functional>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

namespace myleet {

class MyHashSet {
 private:
  std::vector<std::list<int>> data;
  static const int base = 769;
  static int hash(int i) { return i % base; }

 public:
  MyHashSet() : data(base) {}

  void add(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) {
        return;
      }
    }
    data[h].push_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) {
        data[h].erase(it);
        return;
      }
    }
  }

  bool contains(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) {
        return true;
      }
    }
    return false;
  }
};

class MyHashMap {
 private:
  std::vector<std::list<std::pair<int, int>>> data;
  static const int base = 769;
  static int hash(int key) { return key % base; }

 public:
  MyHashMap() : data(base) {}

  void put(int key, int value) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        (*it).second = value;
        return;
      }
    }
    data[h].push_back(std::make_pair(key, value));
  }

  int get(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        return (*it).second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        data[h].erase(it);
        return;
      }
    }
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

}  // namespace myleet

#endif