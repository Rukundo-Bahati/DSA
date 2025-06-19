#include <iostream>

using namespace std;

class Rectangle{
    private:
    int width;
    int length;
    
    public:
    int area(){
        return width * length;
    }
    
    void setValues(int newWidth,int newLength){
       width = newWidth;
       length = newLength;
    }

    Rectangle(){

    }

    Rectangle(int width1,int length1){
        width = width1;
        length = length1;
    }
};

int main(){

  Rectangle recta;
  recta.setValues(20,10);
  Rectangle rectb(20,30);
  Rectangle rectc {10,40};
  Rectangle *rectd = new Rectangle(50,10);

  cout <<"Area1 is " <<recta.area()<<endl;
  cout << "Area 2 is: "<<rectb.area() <<endl;
  cout << "Area 3 "<<rectc.area()<<endl;
  cout << "Area 4 is "<<rectd->area()<<endl; 

 return 0;
}