#include <iostream>
#include <list>
#include <string>
using namespace std;


class calculator{

    public :
    
    int add(int a ,int b)
    {
        return a+b;
    }

    int add(int a ,int b,int c)
    {
        return a+b+c;
    }

    float add(float a ,int b)
    {
        return a+b;
    }

    float add(int a ,float b)
    {
        return a+b;
    }

    float add(float a ,float b)
    {
        return a+b;
    }

};

int main()
{
    calculator calc;
    float a=10.5;
    float b=20.6;
    int c=20;

    cout<<"add 2 int numbers = "<< calc.add(10,5)<<endl;
    cout<<"add 3 int numbers = "<< calc.add(10,5,20)<<endl;
    cout<<"add 1 int 1 float = "<< calc.add(c,a)<<endl;
    cout<<"add 1 float 1 int = "<<calc.add(a,c)<<endl;
    cout<<"add 2 float number = "<<calc.add(a,b)<<endl;
}



// OVERLOADING MAIN FUNCTION


// #include <iostream>
// #include <list>
// #include <string>
// using namespace std;

// class calculator{

//     public :
    
//     int main(int s)
//     {
//         cout<<s<<endl;
//         return 0;
//     }

//     int main(int a ,int b)
//     {
//         cout<<a <<" "<<b<<endl;
//         return 0;
//     }

//     int main(char *s)
//     {
//         cout<<s<<endl;
//         return 0;
//     }
// };

// int main()
// {
//     calculator calc;
//     calc.main(4);
//     calc.main(5,4);
//     calc.main("hello");
// }