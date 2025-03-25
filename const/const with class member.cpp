
// const members must be initialized in the constructor initializer list.
// They cannot be modified after initialization.

// const with Data Members (Member Variables)

// #include <iostream>
// using namespace std;

// class Car {
// private:
//     const int maxSpeed; // Constant member variable

// public:
//     // Constructor initializer list required for const members
//     Car(int speed) : maxSpeed(speed) {}

//     void display() const {
//         cout << "Max Speed: " << maxSpeed << endl;
//     }
// };

// int main() {
//     Car myCar(200);
//     myCar.display();

//     // myCar.maxSpeed = 250; // ❌ Error: cannot modify a const member
//     return 0;
// }




// const with Member Functions 

// #include <iostream>
// using namespace std;
// class Car {
//     private:
//         int speed;
    
//     public:
//         Car(int s) : speed(s) {}
    
//         // const member function
//         void showSpeed() const {
//             cout << "Speed: " << speed << " km/h" << endl;
//         }
    
//         // This would cause an error because it modifies the object
//         // void increaseSpeed() const {
//         //     speed += 10; // ❌ Error: cannot modify member variable in a const function
//         // }
//     };
    
//     int main() {
//         Car myCar(100);
//         myCar.showSpeed();
//         return 0;
//     }
    // const after a method (void showSpeed() const) ensures that the function cannot modify class data members.
    // It allows objects of the class to call this function even if they are declared as const.




    //const with Objects
    //A const object ensures that none of its members can be modified (except mutable members, discussed later).
    // #include<iostream>
    // using namespace std;
    // class Car {
    //     public:
    //         void show() const {
    //             cout << "This is a car." << endl;
    //         }
    //     };
        
    //     int main() {
    //         const Car myCar;
    //         myCar.show(); // ✅ Allowed because show() is a const function
        
    //         // myCar.someMethod(); // ❌ Error if method is non-const
        
    //         return 0;
    //     }
        
    // A const object can only call const member functions.
    // Any non-const function cannot be called on a const object.  



    // mutable Keyword (Exception to const)

    // #include<iostream>
    // using namespace std;
    // class Logger {
    //     private:
    //         mutable int logCount; // Can be modified even in a const function
        
    //     public:
    //         Logger() : logCount(0) {}
        
    //         void logMessage() const {
    //             logCount++; // ✅ Allowed due to 'mutable'
    //             cout << "Logging message #" << logCount << endl;
    //         }
    //     };
        
    //     int main() {
    //         const Logger logger;
    //         logger.logMessage();
    //         logger.logMessage();
    //         return 0;
    //     }
        


    // const retutn type

    // pass b y value
    
    

    // class Car {
    //     public:
    //         const int getMaxSpeed() {
    //             return 200;
    //         }
    //     };
        
    //     int main() {
    //         Car myCar;
    //         int speed = myCar.getMaxSpeed();
    //         // speed = 250; // Allowed, because `speed` is a copy
    //         return 0;
    //     }
        
    // Returning a const Reference

    // class Car {
    //     private:
    //         int speed;
        
    //     public:
    //         Car(int s) : speed(s) {}
        
    //         const int& getSpeed() const {
    //             return speed;
    //         }
    //     };
        
    //     int main() {
    //         Car myCar(150);
    //         const int& s = myCar.getSpeed();
        
    //         // s = 200; // ❌ Error: cannot modify const reference
    //         return 0;
    //     }
        