// Encapsulation is the process of wrapping data (variables) and the functions that operate on that data into a single unit (class).
// It restricts direct access to some of the object's components, which is why it's also referred to as data hiding.


// | Concept               | Description                                                          |
// | --------------------- | -------------------------------------------------------------------- |
// | **Class**             | Defines the encapsulated unit.                                       |
// | **Access Specifiers** | Control the accessibility of data: `private`, `protected`, `public`. |
// | **Getter/Setter**     | Public functions used to access/modify private members.              |


#include<iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    void setBalance(double b) {
        if (b >= 0)
            balance = b;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc;
    acc.setBalance(1000);
    cout << "Balance: " << acc.getBalance() << endl;
}


// here the balance is hidden and cannot be accessed directly it can be accessed using public getter and setter 


// ADVANTAGES 

// security 
// modularity
// maintainability
// data integrity 



//Encapsulation is not just about making data members private.
// It’s about controlling access and bundling logic with data, so that changes to data don't affect external users directly.


// we can break encapsulation using 

// friend function and class 
// pointer arithmetic and casting



