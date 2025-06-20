// Operator overloading means providing a new implementation of an existing operator (like +, ==, [], etc.) for user-defined types.


// | Operator       | Overloadable    | Common Use          |                    |
// | -------------- | --------------- | ------------------- | ------------------ |
// | Arithmetic     | +, -, \*, /     | Vector/Complex math |                    |
// | Comparison     | ==, !=, <, >    | Sorting/searching   |                    |
// | Assignment     | =               | Deep copies         |                    |
// | Subscript      | \[]             | Container access    |                    |
// | Function call  | ()              | Functors            |                    |
// | Stream         | <<, >>          | Input/Output        |                    |
// | Increment/Decr | ++, --          | Iterators, Counters |                    |
// | Logical        | !, &&, \|\|     | Custom logic check  |                    |
// | Bitwise        | &,              | , ^, \~             | Flags, permissions |
// | Others         | ->, new, delete | Smart pointers      |                    |




// ❌ Operators That Cannot Be Overloaded

// :: (Scope resolution)
// . (Member access)
// .* (Pointer-to-member)
// sizeof
// typeid
// alignof
// decltype
// co_await



// ARITHMETIC OPERATOR OVERLOADING 

#include<iostream>
using namespace std;

class complex
{
    public:
    int img;
    int real;
    complex(int i=0 ,int  r=0 ) : img(i), real(r){}

    complex operator+(const complex& obj)          // To avoid unnecessary copies and protect the input from modification. const is added 
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
    complex c2(3,5);
    complex c3 = c1+c2;
    c3.display();
    return 0;
}

// Always make arithmetic operators const because they don’t modify the calling object.

//means 

// complex operator+(const complex &obj) const




// PREFIX POSTFIX INCREMENT DECREMENT


class MyClass
{
    int val;
    public:
    MyClass(int v=0) : val(v){};

    MyClass& operator ++()                  // here we use & as we will make cahnge in the original one 
    {
        ++val;
        return *this ;
    }

    MyClass operator ++(int )               // here int is used to distinguish 
    {
        MyClass temp= *this;    // save original
        val++;                  // make increment 
        return temp;            // then return 
    }

    void display()
    {
        cout<<"value"<<val<<endl;
    }
};


int main()
{
    MyClass mc1(5);
    mc1.display();
    ++mc1;
    mc1.display();
    mc1++;
    mc1.display();
    return 0;
}




// += -= OPERATOR OVERLOADING 

 class base 
 {
    int val;
    public :
    base(int v=0) : val(v) {};

    base & operator +=(const base & obj )       // with the help of & this helps in chaining 
    {
        val+=obj.val;
        return *this;
    }
    void display()
    {
        cout<<val<<endl;
    }
 };

 int main()
 {
    base b1(10);
    base b2(14);
    b1+=b2;
    b1.display();
    return 0;
 }

//  | Operator | Return type          | Modifies object? | Use `*this`? | Return temp?      |
// | -------- | -------------------- | ---------------- | ------------ | ----------------- |
// | `+=`     | `MyClass&`           | ✅ Yes            | ✅ Yes        | ❌ Don't use temp  |
// | `+`      | `MyClass` (by value) | ❌ No             | ❌ Not needed | ✅ Return new temp |



// RELATIONAL OPERATOR 


// bool operator ==(const base &b) const 
// {
//     return val=b.val;
// }



// ASSINGMENT OPERATOR 

//  base & operator =(const base &b) 
//  {
//     if(this!=&b)
//     {
//         val=b.val;
//     }
//     return *this;
//  }





// input output stream 


 // 4. Stream insertion <<
    // friend ostream& operator<<(ostream& out, const MyClass& obj) {
    //     out << "Value: " << obj.val;
    //     return out;
    // }

    // // 5. Stream extraction >>
    // friend istream& operator>>(istream& in, MyClass& obj) {
    //     in >> obj.val;
    //     return in;
    // }