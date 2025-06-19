#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Creating an unordered_map with integer
    unordered_map<int, string> um = {{6, "Rwanda"}, {10, "Coding"}, {3, "Academy"}, {5, "C++"}, {1, "Hello"}, {2, "World"}};
    // Inserting a key-value pair
    um.insert({4, "Programming"});
    um[7] = "Data Structures";

    for(auto i : um) {
        cout << i.first << " : " << i.second << endl;
    }

  
    return 0;
}