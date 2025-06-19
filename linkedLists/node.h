#include <iostream>
#include <cstring>

class Contact{

    friend ostream& operator<<(ostream& os, const Contact& c);
    
public:
Contact(string  name = "none");
private:
string name;
Contact* next;
};

using namespace std;



int main(){


    return 0;
}