#include<iostream>
using namespace std;


// template<typename T> is used to create the class of any data type 

// can also add multiple parameters to the template 


// setting the default as int 

template<typename T=int, typename U=string>
class box
{
private:
    T value;
    U name;
public:
    box(T val, U naam) : value(val), name(naam) {}  
    void show()
    {
        cout << "Value: " << value << ", Name: " << name << endl;
    }
};

int main()
{
    box<int, string> mybox(10, "IntegerBox");  
    mybox.show();

    box<float, char> myfloatbox(10.567, 'F');  
    myfloatbox.show();

    box<>defaultbox(1000,"shobhit");
    defaultbox.show();
    return 0;
}
