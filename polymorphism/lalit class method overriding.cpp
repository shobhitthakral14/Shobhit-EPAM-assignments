#include<iostream>
using namespace std;

class base{
    public:
      void display()
     {
        cout<<"this is base class";
     }
};

class derive : public base 
{
    public: 
    void display()
    {
        cout<<"this is derive class";
    }
};

int main()
{
    base *b=new derive();
    b->display();
}
