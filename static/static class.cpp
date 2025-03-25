#include<iostream>
using namespace std;


// C++ does not allow fully static classes like in Java/C#. 


// However, we can simulate static classes by:
// Declaring all member functions and variables as static.
// Deleting the constructor to prevent object instantiation.




class Utility 
{
    private:
        Utility() {} // Private constructor to prevent instantiation
    
    public:
        static void showMessage() {
            cout << "This is a static class!" << endl;
        }
};
    
    int main() 
    {
        Utility::showMessage(); 
        return 0;
    }

    // The constructor is private to prevent object creation.
    // All methods must be static to access them without an object.