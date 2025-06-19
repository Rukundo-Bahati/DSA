#include <iostream>

using namespace std;

int main(){
    
    int number  = 30;
    int* ptr = &number;

    // cout << "Number address: " << ptr <<endl;
    // cout << "Value of number variable: "<<*ptr << endl;
    // cout << "Address of number: " <<&number << endl;
    // cout << "Address of ptr: "<<ptr<<endl;

    double k=50;
    double *p = &k;
    cout <<k << endl;
    cout <<*p <<endl;

    int t = 55;
    int *s = &t;
    cout << *p<<endl;
    cout << t << endl;

    cout << "Sizeof int pointer: "<<sizeof(s) <<endl;
    cout << "Sizeof double pointer: "<<sizeof(p)<<endl;

    int arr[5] = {10,20,30,40,50};
    int *parr = arr;
    cout << "The first element is " << arr[0]<<endl;
    cout  << "The first element is "<<*parr<<endl;
    cout << "The first element is "<<*arr<<endl;

    for (int i = 0; i < 5; i++)
    {
      cout << "Element at index i= "<<i << " is " << arr[i]<<endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Element at index i="<<i<<" is "<<*(parr+i)<<endl;
    }

    cout << "Using array name as a pointer"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Element at index i=" <<i<< " is "<<*(arr+i)<<endl;
    }

    cout << "using a pointer incremented"<<endl;
    for (int i = 0; i < 5; i++,parr++)
    {
        cout<<"Element at index i= " <<i << *parr<<endl;
        // parr++;
    }
    cout << "---------------------------------------------------------------------------"<<endl;

    int b=20;
    int *pb = &b;
    cout << *pb++ << endl;
    cout << (*pb)++ <<endl;
    cout <<++(*pb)<<endl;

    cout << "----------------------"<<endl;
    
    
    int a = 20;
    int *pta = &a;
    int *q = pta;
    (*q)++;
    cout << a <<endl;

   

    return 0;
}
