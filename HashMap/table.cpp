#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class HashTable {
    static const int HASH_GROUPS = 10; // Number of hash groups
    vector<list<pair<int, string>>> table; // Vector of lists to handle collisions

    public:
      HashTable(){
        table.resize(HASH_GROUPS); // Initialize the hash table with empty lists
      }

      int hashFunction(int key) {
          return key % HASH_GROUPS; // Simple hash function
      }
      void insert(int key, const string& value) {
        int hashValue = hashFunction(key); // Get the hash value
        auto& cell = table[hashValue]; // Get the corresponding list
        for(auto& pair : cell) {
            if(pair.first == key) { // If key already exists, update the value
                pair.second = value;
                return;
            }
        }
        cell.emplace_back(key, value); // Otherwise, insert the new key-value pair
      }

      void remove(int key) {
          int hashValue = hashFunction(key); // Get the hash value
          auto& cell = table[hashValue]; // Get the corresponding list
          for(auto it = cell.begin(); it != cell.end(); ++it) {
              if(it->first == key) { // If key found, remove it
                  cell.erase(it);
                  return;
              }
          }
      }

      string search(int key) {
        int hashValue = hashFunction(key); // Get the hash value
        auto& cell = table[hashValue]; // Get the corresponding list
        for(const auto& pair : cell) {
            if(pair.first == key) { // If key found, return the value
              return pair.second;
            }
        }
        return "Key not found"; // If key not found, return a message
      }

      void display(){
        for(int i = 0; i < HASH_GROUPS; ++i) {
            cout << "Group " << i << ": ";
            for(const auto& pair : table[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
      }
    };

int main(){
   
    HashTable ht; 
    ht.insert(905, "John"); 
    ht.insert(201, "Jane");
    ht.insert(332, "Tom"); 
    ht.insert(32,"Ange");
    ht.insert(124,"Mike");
    ht.insert(154, "Michael"); 
    ht.insert(127, "Chael"); 
    ht.insert(107, "Alice"); 

    ht.display();
    cout << "Searching for key 201: " << ht.search(201) << endl;
    cout << "Searching for key 999: " << ht.search(999) << endl;
    ht.remove(201);
    cout << "After removing key 201:" << endl;
    ht.display();
  
    return 0; 
}