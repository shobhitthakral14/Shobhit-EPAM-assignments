#include <iostream>
#include <list>
#include <string>
using namespace std;

class complex
{
    public:
    int real;
    int img;
    
    // constructor initalization list 
    complex(int r=0 ,int i=0) :real(r),img(i) {}
    
    // operator overloading 
    complex operator+(const complex& obj)
    {
        complex temp;
        temp.real=real+obj.real;
        temp.img=img+obj.img;
        return temp;
    }
    void display()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};

int main()
{
    complex c1(10,4);
    complex c2(4,5);
    complex c3=c1+c2;
    c3.display();
}