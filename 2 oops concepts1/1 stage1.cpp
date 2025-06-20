//-------------------------------------------------------------COUT-----------------------------------------------------------------------------


// std::cout is the standard output stream in C++.

// It is used to print output to the console.

// Defined in the <iostream> header file.

// It is an instance of the ostream class (from the Standard Library)


// std::cout<<"hello"<<std::endl;


// here
//  std-> standard namespace   
//  cout -> standard character output stream 
// << -> : The insertion operator. Used to insert data into the output stream.
// endl->  Ends the line and flushes the buffer.




// std::cout is an object of type ostream, which is part of the C++ standard library's I/O stream classes.

// Inherits from ostream, which provides overloaded << operators for various types (int, char*, double, etc.).

// You can overload << for user-defined types as well.


// to make cout thread safe use mutex and lock_guard

// std::flush  Flushes the output buffer without adding a newline.



// -------------------------------------------------------------------CIN--------------------------------------------------------------------------------


// std::cin is the standard input stream in C++.

// It reads input from the keyboard.

// Defined in the <iostream> header.

// It's an instance of std::istream class.

// Uses the >> extraction operator to read data from the input buffer.

// It skips whitespace by default (spaces, tabs, newlines).

// to read a full line using spaces std::getline(cin,variable)            // difference is cin stops at whitespaces but getline take all the line 


// if cin fail cin.fail() become true and cin stopped working until cleared 

// cin.clear();
// cin.ignore(1000,'\n');

// If you're mixing cin >> and getline(), always use cin.ignore() right after cin >> to avoid skipping input.


// int age;
// string name;

// cin>>age;

// cin.ignore(numeric_limits<streamsize>::max,'\n');

// getline(cin,name);



//------------------------------------------------STRING-----------------------------------------------------------------------------

// std::string is a class from the C++ Standard Library (<string> header).

// It represents a dynamic array of characters.

// Provides rich functionality for string manipulation.

// Defined in the std namespace.


// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s = "Hello";
//     cout << s << endl;
// }



// INITALIZATION 


// string s1;                     // Empty string
// string s2 = "Hello";           // Direct initialization
// string s3("World");            // Constructor style
// string s4(s2);                 // Copy constructor
// string s5(5, 'x');             // "xxxxx"



// MEMORY MANAGEMENT 

// Through dynamic memory; modern implementations use SSO (Short String Optimization) to avoid heap allocation for small strings.
// Memory grows as needed using reserve() and shrinks with shrink_to_fit().

// Unlike std::string, there’s no hidden null terminator — everything you push is counted.

// null terminator is present to make it compatible with c style strings 
// It is not needed for C++ operations (like .size() or indexing), but it's stored to ensure safe interop.


// STD::STRING IS NOT THREAD SAFE UNLESS PROTECTED INTERNALLY 



// TO REVERSE A STRING 
// std::reverse(s.begin(), s.end());


// TIME COMPLEXITY 

// s.append("1")    O(1)
// s.insert(5,'1')  O(n) worst case 
// s.erase(5,1)     O(n)




// s.at(1)      if it is out of bound it will throw exception 
// s.front()    first character 
// s.back()     last character

// int a = stoi("123456")    string to integer 
// int b = stof("12345")     string to float

// string s =to_string(1234)  convert it to string 



// // ITERATE 

//  for(int i=0;i<s.size();i++)
//  {
//     cout<<s[i]<<endl;
//  }


// for(char c:s)
// {
//     cout<<c<<endl;
// }




// modifying string literals ay leads to undefined beahviour as they are const char*



// s.substr(0, 4);             // Get substring
// s.find("lo");               // Returns position
// s.rfind("o");               // Search from end
// s.find_first_of("aeiou");   // First vowel
 



// s.capacity()  greater than or equal to size 

// if we incerease the size of the string and the size is not available then bad_alloc exception will occur 
// this indicate heap allocation failure 






// -----------------------------------------------------------------------------UNICODE---------------------------------------------------------------------------


// Unicode is a universal character encoding standard that assigns a unique number (code point)
// to every character across all writing systems (letters, digits, symbols, emojis, etc.) used in the world.

// 🧠 Why Unicode?
// Before Unicode, different systems used different encodings (like ASCII, ISO-8859-1, etc.), which could lead to incompatibility.
// Unicode solves this by assigning a single code point for every character, no matter the platform, language, or program

// Unicode has multiple encodings, such as:

// UTF-8: Variable-length encoding (1 to 4 bytes), backward compatible with ASCII.
// UTF-16: Variable-length encoding (2 or 4 bytes).
// UTF-32: Fixed-length encoding (4 bytes per character).

// | Type       | Description                                            |
// | ---------- | ------------------------------------------------------ |
// | `char`     | 1 byte, typically ASCII                                |
// | `wchar_t`  | Wide character, size varies by platform (2 or 4 bytes) |
// | `char16_t` | For UTF-16 characters                                  |
// | `char32_t` | For UTF-32 characters                                  |



// #include <iostream>
// using namespace std;

// int main() {
//     const char* emoji = u8"\U0001F600"; // 😀 as UTF-8 string literal
//     cout << emoji << endl;             // works in UTF-8 terminals
// }




// ----------------------------------------------------------------MULTIBYTE------------------------------------------------------------------------------------------


//Multibyte characters refer to characters that require more than one byte for representation, common in non-ASCII character sets like UTF-8, UTF-16, Shift-JIS, etc.
// These are essential for representing international characters (e.g., Chinese, Japanese, emoji, etc.).

// Standard ASCII uses 1 byte (8 bits) for a character — can only represent 128 or 256 characters.
// Languages like Chinese or Japanese need thousands of unique symbols, so we need more than 1 byte per character.








//---------------------------------------------------------------------MEMORY MANAGEMENT----------------------------------------------------------------------------


// Memory management in C++ is a fundamental concept that deals with the allocation, usage, and deallocation of memory during a program's runtime.
// Unlike some higher-level languages, C++ gives programmers manual control over memory, which provides both power and responsibility. 


// 1.) STACK MEMORY 

// automatically managed 
// used for local variables , function calls 
// deallocated when the function scope ends
// fast access but limited size 


void func() {
    int a = 10;  // Stored in stack
}



// 2.) HEAP MEMORY 

// manually managed 
// used for dynamically allocated memory 
// must be explicitly allocated and deallocated using new and delete 
// slow access but large in size 

// int* ptr = new int(10);  // Allocated on heap
// delete ptr;              // Must delete to avoid memory leak



// int *p=new int(5);
// // this is used for single object allocation 
// delete p;


// new[] and delete[]  for dynamic array allocation 

// int *arr=new int[10];
// delete[] arr;


//  Common Problems in Memory Management

// 1.) Memory Leak
// Forgetting to delete dynamically allocated memory

int* p = new int(10);
// No delete => memory leak


// 2.) Dangling pointer 

// Using memory after it's been deleted.

// int* p = new int(10);
// delete p;
// *p now is a dangling pointer


// 3.) Double Deletion
// Deleting the same pointer more than once.

// int* p = new int(10);
// delete p;
// delete p;  // Undefined behavior



//C++ uses RAII to manage resources. When an object goes out of scope, its destructor is called automatically to release resources.

// #include <iostream>
// using namespace std;

// int main() {
//     // --- Dynamic allocation of a single integer ---
//     int* singleInt = new int;      // Allocates memory for one int
//     *singleInt = 10;               // Assign value
//     cout << "Single integer value: " << *singleInt << endl;
//     delete singleInt;              // Free memory

//     // --- Dynamic allocation of an array of integers ---
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     int* arr = new int[n];         // Allocate array of size n

//     // Input elements
//     cout << "Enter " << n << " integers:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }

//     // Print elements
//     cout << "You entered: ";
//     for (int i = 0; i < n; ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     delete[] arr;                  // Free the entire array

//     return 0;
// }




//-------------------------------------------------------REFERENCES-----------------------------------------------------------------------------


// A reference is an alias for another variable. Once a reference is initialized to a variable, it becomes just another name for that variable.

// int a = 10;
// int &ref = a; // ref is a reference to a
// ref = 20;     // now a is also 20



// 🔹 Key Characteristics:
// Must be initialized at the time of declaration.

// Acts as an alias—changes made through the reference affect the original variable.

// Cannot be null.

// Cannot be reseated (i.e., made to refer to another variable).

// Used for pass-by-reference, improving performance and enabling modification.



//int &ref; // ❌ ERROR: Must be initialized




// 📌 Why Use References?

// Modify arguments in functions.
// Avoid copies (efficiency).
// Operator overloading.
// Move semantics (via r-value references).



// HERE THE VALUE IS MODIFING USING REFERENCE AND THE OPERATIONS PERFORMED WILL AFFECT THE ORIGINAL VARIABLE AS IT IS NOT MAKING COPY

// void modify(int &x) {
//     x = 100;
// }

// int main() {
//     int a = 10;
//     modify(a); // a becomes 100
// }




//Pointer	                                Reference
// Can be null	                            Cannot be null
// Can be reseated	                        Cannot be reseated
// Requires dereferencing	                Used as-is
// More flexible	                        Safer syntax



// REFERENCE TO POINTER
// int *p;
// int * &ref=p;



// WE CANNOT HAVE ARRAY OF REFERENCES IN CPP . EITHER USE POINTER OR WRAPPER CLASS 


// REFERENCES CAN ALSO BE THE MEMBER OF CLASS AND NEEDS TO BE INITALISED USING CONSTRUCTOR INITIALIZER LIST 


class A {
    int &ref;
public:
    A(int &x): ref(x) {} // must initialize in initializer list
};





// T&& is an r-value reference.

// std::move() casts l-values to r-values, enabling move semantics.

// Used to optimize performance by avoiding deep copies.



// IMPLEMENTATION OF REFERNCES INTERNALLY 
// Under the hood, often as pointers (though not exposed). This is compiler-dependent.


// IF WE RETURN REFERNCE TO A LOCAL VARIABLE IT WILL GIVE UNDEFINED BEHAVIOUR 

int& getVal() {
    int x = 10;
    return x; // ⚠️ BAD: x goes out of scope
}


