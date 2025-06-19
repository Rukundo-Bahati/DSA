#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
  static const int hashGroups = 10;
  list<pair<int, string>> table[hashGroups];

public:
  bool isEmpty() const;
  int hashFunction(int key);
  void insertItem(int key, string value);
  void removeItem(int key);
  string searchTable(int key) const;
  void printTable() const;
};

bool HashTable::isEmpty() const {
  int sum{};
  for (int i = 0; i < hashGroups; ++i) {
    sum += table[i].size();
  }
  return sum == 0;
}

int HashTable::hashFunction(int key) {
  return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
  int hashValue = hashFunction(key);
  auto &cell = table[hashValue];
  for (auto &pair : cell) {
    if (pair.first == key) {
      pair.second = value;  // Update existing key
      cout << "[INFO] Key exists. Value replaced." << endl;
      return;
    }
  }
  cell.emplace_back(key, value);  // Insert new key-value
  cout << "[INFO] Pair inserted." << endl;
}

void HashTable::removeItem(int key) {
  int hashValue = hashFunction(key);
  auto &cell = table[hashValue];
  for (auto it = cell.begin(); it != cell.end(); ++it) {
    if (it->first == key) {
      cell.erase(it);
      cout << "[INFO] Pair removed." << endl;
      return;
    }
  }
  cout << "[WARNING] Key not found. Nothing removed." << endl;
}

string HashTable::searchTable(int key) const {
  int hashValue = key % hashGroups;
  const auto &cell = table[hashValue];
  for (const auto &pair : cell) {
    if (pair.first == key) {
      return pair.second;
    }
  }
  return "Not found";
}

void HashTable::printTable() const {
  for (int i = 0; i < hashGroups; ++i) {
    if (!table[i].empty()) {
      cout << "Group " << i << ": ";
      for (const auto &pair : table[i]) {
        cout << "[" << pair.first << " : " << pair.second << "] ";
      }
      cout << endl;
    }
  }
}

int main() {
  HashTable ht;

  ht.insertItem(905, "John");
  ht.insertItem(201, "Kelly");
  ht.insertItem(329, "Jim");
  ht.insertItem(777, "Jane");

  ht.printTable();

  cout << "Searching key 329: " << ht.searchTable(329) << endl;

  ht.removeItem(201);
  ht.printTable();

  cout << "Is hash table empty? " << (ht.isEmpty() ? "Yes" : "No") << endl;

  return 0;
}
