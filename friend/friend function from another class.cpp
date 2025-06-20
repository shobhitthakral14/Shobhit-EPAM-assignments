#include<iostream>
using namespace std;
 
class base;
class another
{
    public:
    void memberfunction(base &obj);
};

class base
{
    private:
    int private_v;
    protected:
    int protected_v;
    public:
    base()
    {
        private_v=20;
        protected_v=40;
    }
    friend void another :: memberfunction(base &b);

};


void another::memberfunction(base& obj)
{
    cout << "Private Variable: " << obj.private_v << endl;
    cout << "Protected Variable: " << obj.protected_v << endl;
}

int main()
{
    base obj1;
    another an1;
    an1.memberfunction(obj1);
    return 0;
}