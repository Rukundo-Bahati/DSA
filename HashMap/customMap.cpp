#include <iostream>
#include <string>

using namespace std;

struct  Node {
    string key;
    int value;
    Node* left;
    Node* right;
    Node(string k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};
class CustomMap {
private:
    Node* root;

    Node* insert(Node* node, const string& key, int value) {
        if (!node) return new Node(key, value);
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value; // Update value if key already exists
        }
        return node;
    }

    Node* find(Node* node, const string& key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }
    Node* remove(Node* node, const string& key) {
        if (!node) return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            // Node with one child or no child
            if (!node->left) return node->right;
            if (!node->right) return node->left;

            // Node with two children: Get the inorder successor
            Node* successor = node->right;
            while (successor && successor->left) {
                successor = successor->left;
            }
            node->key = successor->key;
            node->value = successor->value;
            node->right = remove(node->right, successor->key);
        }
        return node;
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << ": " << node->value << endl;
        inorder(node->right);
    }
public:
    CustomMap() : root(nullptr) {}

    void insert(const string& key, int value) {
        root = insert(root, key, value);
    }

    int find(const string& key) {
        Node* node = find(root, key);
        if (node) return node->value;
        throw runtime_error("Key not found");
    }

    void remove(const string& key) {
        root = remove(root, key);
    }

    void display() {
        inorder(root);
    }
};
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>


int main(){
    
    CustomMap myMap;
    // Inserting key-value pairs
    myMap.insert("Apple", 100);
    myMap.insert("Banana", 200);
    myMap.insert("Cherry", 300);
    myMap.insert("Date", 400);
    myMap.insert("Elderberry", 500);
    myMap.insert("Fig", 600);
    // Displaying the map
    cout << "Initial map contents:" << endl;
    myMap.display();
    // Finding a value
    try {
        cout << "Value for 'Banana': " << myMap.find("Banana") << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    // Removing a key-value pair
    myMap.remove("Cherry");
    cout << "Map contents after removing 'Cherry':" << endl;
    myMap.display();
    // Inserting a duplicate key to update its value
    myMap.insert("Banana", 350);
    cout << "Map contents after updating 'Banana':" << endl;
    myMap.display();
    // Attempting to find a non-existent key
    try {
        cout << "Value for 'Grape': " << myMap.find("Grape") << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    // Final display of the map
    cout << "Final map contents:" << endl;
    myMap.display();
    // Example of inserting a new key
    myMap.insert("Honeydew", 700);      

    return 0;
}