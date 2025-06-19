#include <iostream>
#include <map>
using namespace std;



int main(){

    //creating a map
    map<string, int> myStock;
     
    // inserting a key-value pair
    myStock.insert({"Apple", 100});
    myStock["banana"] = 200;
    myStock["cherry"] = 300;
  
   //retrieving  the value associated with a key
   int qty = myStock["banana"];
    cout << "Value of bananas: " << qty << endl;

    //updating the value associated with a key
    myStock["banana"] = 350; 
    cout << "Updated value for key banana: " << myStock["banana"] << endl;

    //removing a key-value pair
    myStock.erase("cherry");
    cout << "After removing cherry, size of map: " << myStock.size() << endl;

    //iterating through the map
    cout << "Key-Value pairs in the map:" << endl;
    for (const auto& pair : myStock) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}