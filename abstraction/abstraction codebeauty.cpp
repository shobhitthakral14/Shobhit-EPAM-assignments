#include<iostream>
using namespace std;

//It is the process of hiding implementation details from the user and exposing only the necessary functionality.
//There are two main ways to implement abstraction in C++:   //Using Classes (Data Abstraction)     //Using Abstract Classes and Pure Virtual Functions (Functional Abstraction)


//If the base class destructor is not virtual, only the base class's destructor will be called, potentially causing a memory leak.

// if the destructor is not virtual only the base is called due to early binding (compile time)
// if the destructor is virtual ony both the base and abstract is called due to late binding (run time)

class smartphone
{
    public :
    virtual void takeaselfie()=0;
    virtual void makeacall()=0;

    virtual ~smartphone()
    {
        cout<<"destructor of smartphone"<<endl;
    }
};


class android :public smartphone
{
    public:
    void takeaselfie() override
    {
        cout<<"android took a selfie"<<endl;
    }
    void makeacall()
    {
        cout<<"android calling"<<endl;
    }
    ~android()
    {
        cout<<"destructor of android"<<endl;
    }
};

class iphone :public smartphone
{
    public:
    void takeaselfie() override
    {
        cout<<"iphone selfie"<<endl;
    }
    void makeacall()
    {
        cout<<"iphone calling"<<endl;
    }
    ~iphone()
    {
        cout<<"destructor of iphone"<<endl;
    }
};

int main()
{
     smartphone* s1=new iphone();
     s1->takeaselfie();
     s1->makeacall();
     delete s1;
}  