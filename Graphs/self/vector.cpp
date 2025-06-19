#include <iostream>
#include <vector>
using namespace std;

int main(){
   
    vector<int> vector1 = {1,2,3,4,5};
    vector<int> vector2{6,7,8,9,10};
    vector<int> vector3(5,2);


     cout <<"Vector from method 1=";
     for (int i = 0; i < vector1.size(); i++)
     {
        cout <<vector1[i] << " ";
     }
     cout <<"\nVector from method 2=";
     for (int i = 0; i < vector2.size(); i++)
     {
        cout <<vector2[i] << " ";
     }
     
     cout <<"\nVector from method 3=";
     for (int i = 0; i < vector3.size(); i++)
     {
        cout <<vector3[i] << " ";
        
     }

     //vector functions
     vector<int> g1;
     for (int i = 1; i <=5; i++)
      g1.push_back(i);

     cout <<"\noutput of begin and end: ";
     for(auto i=g1.begin(); i !=g1.end(); i++)
      cout << *i << " ";

     cout <<"\noutput of cbegin and cend: ";
      for(auto i=g1.cbegin(); i != g1.cend(); i++)
       cout << *i << " ";  

     cout <<"\noutput of rbegin and rend: ";
      for(auto ir=g1.rbegin(); ir != g1.rend(); ir++)
       cout << *ir << " ";

     cout <<"\noutput of crbegin and crend: ";
      for(auto ir=g1.crbegin(); ir != g1.crend(); ir++)
       cout << *ir << " ";

     cout <<"\nSize: "<<g1.size();
     cout <<"\nCapacity: "<<g1.capacity(); 
     
     g1.resize(4);
     cout << "\nSize after resize: "<<g1.size();
     if (g1.empty() == false)
     {
       cout << "\nVector isn't empty";
     } else {
        cout << "\nVector is empty";
     }

     g1.shrink_to_fit();
     cout << "\nVector elements are: ";
     for(auto it=g1.begin(); it !=g1.end(); it++)
       cout << *it<<" ";

     cout << "\nReference operator [g]:g1[2]="<<g1[2];
     cout <<"\nat:g1.at(2)="<<g1.at(2);
     cout <<"\nfront():g1.front()"<< g1.front();
     cout << "\nback():g1.back()="<<g1.back();
     
     //pointer to the first element
     int *pos= g1.data();
     cout << "\nThe first element is "<<*pos;
     
     //modifiers
     g1.insert(g1.begin(),0);
     cout << "\nThe first element is "<<g1[0];
     
    return 0;
}