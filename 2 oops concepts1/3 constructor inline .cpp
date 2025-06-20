

// ------------------------------------------------------------------CONSTRUCTOR-------------------------------------------------


// A constructor is a special member function of a class that is automatically invoked when an object is created. It initializes the object’s data members.
// same name as class
// no return type 
// not even void 
// once defined parametrized explicitly we cannot use default 
// there is no concept of virtual constructor as virtual works with objects that are already created 



// TYPES

// 1.) Default 

// class A
// {
//     A()
//     {
//         cout<<"default";
//     }
// };


// 2.) parameterized 


// #include<iostream>
// using namespace std;

// class A
// {
//     public:
//     A(int x)
//     {
//         cout<<"paramterized"<<endl;
//     }
// };

// int main()
// {
//     A a(50);
// }


// 3.) copy


// class A
// {

//     public :
//     A(const A& obj) 
//     {
//         cout<<"copy constructor" <<endl;
//     }
// };


        // SHALLOW COPY

//     Copies only the pointer values, not the memory they point to.
// So, two objects share the same memory.

// ⚠️ Problem:
// If one object deletes the memory, the other has a dangling pointer, causing undefined behavior.


// DEEP COPY    

// ✅ What It Does:
// Allocates new memory and copies the content, not the pointer.
// Each object has its own memory, so no accidental sharing.


// #include<iostream>
// using namespace std;


// class myclass
// {
//     public:
//     int *data;
//     myclass(int val=0): data(new int (val)){}
    
//     // myclass (const myclass&obj)
//     // {
//     //     data=new int (*obj.data);
//     // }
    
//     void display()
//     {
//         cout<<"value = "<<*data<<endl;
//     }
// };


// int main()
// {
//     myclass mc1(10);
//     myclass mc2=mc1;
    
//     mc1.display();
//     mc2.display();
    
//     *mc2.data=20;
    
//     mc2.display();
//     mc1.display();
    
//     return 0;
// }

// 4.) move 

// class A
// {
//     public:
//     A(A &&obj) 
//     {
//         cout<<"move constructor"<<endl;
//     }  
// };



// 5.) constructor with default

// class A
// {
//     public:
//     A(int x=10)
//     {
//         cout<<"default value"<<endl;
//     }
// };



//       explict constructor 


// class A {
// public:
//     explicit A(int x) { cout << "Explicit constructor\n"; }
// };

// An explicit constructor is a constructor that cannot be used for implicit conversions or copy-initialization.
// You use the explicit keyword to prevent the compiler from using that constructor in unintended or automatic type conversions.


// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     int val;

//     explicit MyClass(int x) {  // Try removing 'explicit' to see the difference
//         val = x;
//         cout << "Constructor called\n";
//     }
// };

// void print(MyClass obj) {
//     cout << "Value: " << obj.val << endl;
// }

// int main() {
//     MyClass a(10);     // OK
//     print(a);          // OK

//     print(20);  //    ❌ Error: can't convert int to MyClass implicitly if constructor is explicit
//                       // ✅ If 'explicit' is removed, this compiles (implicit conversion)
    
//     return 0;
// }













// constructor initializer list

// class A {
//     int x;
// public:
//     A(int val) : x(val) { cout << "x = " << x; }
// };


// constructor overloading 

// class A {
// public:
//     A() {}
//     A(int x) {}
//     A(int x, int y) {}
// };




// copy constructor is called 
// when we pass object as parameter by value
// retruning object by value
// initializing new object from the existing one  A b=a;


// constructor can call another constructor in it using  delegating constructors 
// class A {
// public:
//     A() : A(10) {}
//     A(int x) { cout << x; }
// };


// constructor can also throw exception 

// to prevent copying delete copy constructor and assingment operator 


// #include <iostream>
// #include <string>
// using namespace std;

// class Book {
// private:
//     string title;
//     string author;
//     int pages;
//     static int bookcount;
//     const string bookstorename = "ab_books";
//     int* data;

// public:

//     // 1. Default Constructor
//     Book() : title("Unknown"), author("Unknown"), pages(0), data(new int(0)) {
//         bookcount += 1;
//         cout << "Default constructor: Empty book created\n";
//     }

//     // 2. Parameterized Constructor
//     Book(string& t, string& a, int p, int d) : title(t), author(a), pages(p), data(new int(d)) {
//         bookcount += 1;
//         cout << "Parameterized constructor: Book '" << title << "' created\n";
//     }

//     // 3. Copy Constructor
//     Book(const Book& other) : title(other.title), author(other.author), pages(other.pages), data(new int(*other.data)) {
//         bookcount += 1;
//         cout << "Copy constructor: Copied book '" << title << "'\n";
//     }

//     // 4. Move Constructor
//     Book(Book&& other) noexcept : title(std::move(other.title)), author(std::move(other.author)), pages(other.pages), data(other.data) {
//         other.pages = 0;
//         other.data = nullptr;
//         cout << "Move constructor: Moved book '" << title << "'\n";
//     }

//     // 5. Copy Assignment Operator
//     Book& operator=(const Book& other) {
//         if (this == &other) return *this; // self-assignment check
//         delete data;
//         title = other.title;
//         author = other.author;
//         pages = other.pages;
//         data = new int(*other.data);
//         cout << "Copy assignment: Assigned book '" << title << "'\n";
//         return *this;
//     }

//     // 6. Destructor
//     ~Book() {
//         delete data;
//         cout << "Destructor: Book '" << title << "' destroyed\n";
//     }

//     void display() const {
//         cout << title << " by " << author << " (" << pages << " pages)"
//             << ", book number: " << bookcount;
//         if (data != nullptr) {
//             cout << ", data: " << *data;
//         }
//         cout << endl;
//     }
// };

// int Book::bookcount = 0;

// int main() {
//     cout << "===== Book Management System =====\n";

//     Book book1;
//     book1.display();

//     string t = "Harry Potter";
//     string a = "J.K. Rowling";
//     Book book2(t, a, 400, 9);
//     book2.display();

//     Book book3(book2);  // Copy constructor
//     book3.display();

//     Book book4 = std::move(book2);  // Move constructor
//     book4.display();

//     Book book5;
//     book5 = book3;  // Copy assignment
//     book5.display();

//     cout << "===== End of Program =====\n";
//     return 0;
// }




// in initialzer list  initialization Happens before constructor body executes
// time efficent and memory also
// used when there is const or references 
// direct call to constructor in writing it is 2 steps 


// we can explicitly delete any constructor 

//A friend class or function can call a private constructor:


// aggregate can be constructed {} directly default constructor auto generated 
// if a class has any one constructor it is user defined 



// ---------------------------------------INLINE FUNCTION------------------------------------


// An inline function is a function for which the compiler attempts to replace the function call with the actual code of the function at compile time,
// reducing the overhead of a function call.

// results in avoiding overhead and better performance

// inline is just a request compiler may avoid it 
// it is just compiler pushing parameters to the stack 

// inline function can be recursive but it is of no use

// VIRTUAL FUNCTIONS CANNOT BE IN LINE AS IT IS RESOLVED AT RUNTIME 


// IMPLICIT
// class MyClass {
// public:
//     int square(int x) { return x * x; }  // Implicitly inline
// };
 
    // OUTSIDE THE CLASS 
//     class MyClass {
//     int square(int);
// };
// inline int MyClass::square(int x) {
//     return x * x;
// }


// ---------------------------------------------MACRO VS INLINE--------------------------------


// macro is done by preprocessor 
// inline is done by compiler 


// in macro there is no error checking 
// in inline there is error checking 

// in macro there is no type safety 
// in inline there is type safety 


