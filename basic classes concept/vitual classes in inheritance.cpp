#include<iostream>
using namespace std;

class base{
    public:
    base ()
    {
        cout<<"base"<<endl;
    }
};


class derive1 : virtual public base 
{
   public: 
   derive1()
   {
       cout<<"derive1"<<endl;
   }
};


class derive2 : virtual public base 
{
    public:
    derive2()
   {
       cout<<"derive2"<<endl;
   }
};


class derive3 : public derive2 ,derive1
{
    public: 
    derive3()
   {
       cout<<"derive3"<<endl;
   }
};



int main()
{
    derive3* obj=new derive3();
}
