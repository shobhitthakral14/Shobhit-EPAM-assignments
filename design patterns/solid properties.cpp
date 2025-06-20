
// The SOLID principles are five essential guidelines that enhance software design, making code more maintainable ,cleaner and scalable. 
// The SOLID principle helps in reducing tight coupling.
// Tight coupling means a group of classes are highly dependent on one another which you should avoid in your code.



//----------------------------------- S = Single Responsibility Principle (SRP)--------------------------------------------------------

//The Single Responsibility Principle (SRP) establishes that a class or module should have only one reason to change.
// Which means a class should have only one responsibility or job, and it should do that job well.
// It's important to carefully consider the responsibilities of each class or module in the system. 
// If a class has more than one responsibility, it's usually a sign that it needs to be broken up into smaller, more focused components.
// By ensuring that each class has only one responsibility, changes to one part of the codebase are less likely to affect other parts of the system.    


// THIS IS NOT A GOOD EXAMPLE
class Report {
    public:
        void generateReport() {
            // logic to generate report
        }
    
        void saveToFile() {
            // logic to save report to file
        }
    };


    // THIS IS A GOOD EXAMPLE AS A CLASS IS DOING ONE JOB
    class Report {
        public:
            void generateReport() {
                // logic to generate report
            }
        };
        
        class ReportSaver {
        public:
            void saveToFile(const Report& report) {
                // logic to save report
            }
        };
            


int main()
{
    return 0;
}



// ---------------------------------------------------- O = open /close principle ------------------------------------------------------------------

// The Open/Closed Principle (OCP) establishes that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
// In other words, you should be able to extend the behavior of a system without modifying its existing code.

// To follow the OCP, it's important to design your system with a clear separation of concerns,
// using interfaces or abstract classes to define behavior that can be extended by implementing new concrete classes. 
// This allows you to add new functionality by creating new concrete classes that implement the existing interface or abstract class, without modifying the existing code.

// This makes the codebase more stable and predictable, and reduces the risk of introducing bugs or breaking existing functionality.


#include <iostream>
#include <string>

// Base class for payment processing
class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

// Credit card payment processor
class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};


// ADDING NEW FUNCTIONALITY


// PayPal payment processor
class PayPalPaymentProcessor : public PaymentProcessor {
    public:
        void processPayment(double amount) override {
            std::cout << "Processing PayPal payment of $" << amount << std::endl;
        }
    };
    

    void processPayment(PaymentProcessor* processor, double amount) {
        processor->processPayment(amount);
    }
    
    int main() {
        CreditCardPaymentProcessor creditCardProcessor;
        PayPalPaymentProcessor payPalProcessor;
        
        processPayment(&creditCardProcessor, 100.00); // Processing credit card payment
        processPayment(&payPalProcessor, 150.00);     // Processing PayPal payment
    
        return 0;
    }
    // -----------------------------------------------------L = LISKOV SUBSTITUION PRINCIPLE-----------------------------------------------------------------


    //  L = Liskov Substitution Principle (LSP)

// The Liskov Substitution Principle (LSP) states that subtypes should be substitutable for their base types without breaking the application 
// According to this principle “Derived or child classes must be substitutable for their base or parent classes“.
// This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behaviour.


#include <iostream>
class Shape {
public:
    virtual double getArea()=0; // Pure virtual method
    virtual ~Shape() = default;
};
 
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
 
    double getArea() override {
        return width * height;
    }
 
};
 
class Square : public Shape {
private:
    double side;
public:
    explicit Square(double side) : side(side) {}
 
    double getArea() override {
        return side * side;
    }
 
};

void printArea(Shape& shape) {
    std::cout << "Area = " << shape.getArea() << std::endl;
}

int main()
{
    Square sq(10);
    Rectangle rec(10.5, 5);

    printArea(sq);   // Square treated as a Shape
    printArea(rec);  // Rectangle treated as a Shape

    return 0;
}



/// in open/close it is that the software entities is open for extension and close for modification means we can extend the code through abstract class and should not modify the exisiting code 
// You use virtual functions to extend functionality in derived classes without modifying base classes



// in LSP it is correctness of substitution 
// You also use virtual functions, but the focus is on making sure the behavior of derived classes remains consistent with the base.
// LSP is about making sure new derived classes don’t break expectations of base classes.




// --------------------------------------------------------I = INTERFACE SEGREGATION PRINCIPLE-------------------------------------------------------   

#include <iostream>
#include <vector>
#include <string>

// Interface for vegetarian menu
class IVegetarianMenu {
public:
    virtual std::vector<std::string> getVegetarianItems() = 0;          // abstract base class for veg 
};

// Interface for non-vegetarian menu
class INonVegetarianMenu {
public:
    virtual std::vector<std::string> getNonVegetarianItems() = 0;      // abstract base class for nonveg
}; 

// Interface for drinks menu
class IDrinkMenu {
public:
    virtual std::vector<std::string> getDrinkItems() = 0;             // abstract class for drink
};

// Class for vegetarian menu
class VegetarianMenu : public IVegetarianMenu {
public:
    std::vector<std::string> getVegetarianItems() override {
        return {"Vegetable Curry", "Paneer Tikka", "Salad"};
    }
};

// Class for non-vegetarian menu
class NonVegetarianMenu : public INonVegetarianMenu {
public:
    std::vector<std::string> getNonVegetarianItems() override {
        return {"Chicken Curry", "Fish Fry", "Mutton Biryani"};
    }
};

// Class for drinks menu
class DrinkMenu : public IDrinkMenu {
public:
    std::vector<std::string> getDrinkItems() override {
        return {"Water", "Soda", "Juice"};
    }
};
// Function to display menu items for a vegetarian customer
void displayVegetarianMenu(IVegetarianMenu* menu) {
    std::cout << "Vegetarian Menu:\n";
    for (const auto& item : menu->getVegetarianItems()) {
        std::cout << "- " << item << std::endl;
    }
}

// Function to display menu items for a non-vegetarian customer
void displayNonVegetarianMenu(INonVegetarianMenu& menu) {
    std::cout << "Non-Vegetarian Menu:\n";
    for (const auto& item : menu.getNonVegetarianItems()) {
        std::cout << "- " << item << std::endl;
    }
}

int main() {
    VegetarianMenu vegMenu;
    NonVegetarianMenu nonVegMenu;
    DrinkMenu drinkMenu;

    displayVegetarianMenu(&vegMenu);
    displayNonVegetarianMenu(nonVegMenu);
    return 0;
}


//Passing by value copies the entire object — which can be costly for big objects and impossible for abstract classes.
//Passing by value requires making a copy (calling a copy constructor), which is impossible for abstract classes.
// so here in this code we cannot do that 



// difference between passing by reference and passing by pointer is that pointer can be null and reference cannot be 
// means reference always expect to exit 

// and if passing by reference no need to pass address means using & in the main code where the funcion is calling 
// in the pointer we need to pass &

// reference is called using . and pointer is called using ->









// ----------------------------------D = DEPENDENCY INVERSION PRINCIPLE--------------------------------------------------------

//  D = Dependency Inversion Principle (DIP)
//  The Dependency Inversion Principle (DIP) is a principle in object-oriented design that states that “High-level modules should not depend on low-level modules.
//  Both should depend on abstractions“.
//  It also suggests that abstractions must not depend on details, but details must depend on abstractions.


#include <iostream>
#include <string>

// Interface for version control system
class IVersionControl {
public:
    virtual void commit(const std::string& message) = 0;
    virtual void push() = 0;
    virtual void pull() = 0;
};

// Git version control implementation
class GitVersionControl : public IVersionControl {
public:
    void commit(const std::string& message) override {
        std::cout << "Committing changes to Git with message: " << message << std::endl;
    }

    void push() override {
        std::cout << "Pushing changes to remote Git repository." << std::endl;
    }

    void pull() override {
        std::cout << "Pulling changes from remote Git repository." << std::endl;
    }
};

// Team class that relies on version control
class DevelopmentTeam {
private:
    IVersionControl* versionControl;

public:
    DevelopmentTeam(IVersionControl* vc) : versionControl(vc) {}

    void makeCommit(const std::string& message) {
        versionControl->commit(message);
    }

    void performPush() {
        versionControl->push();
    }

    void performPull() {
        versionControl->pull();
    }
};

int main() {
    GitVersionControl git;
    DevelopmentTeam team(&git);

    team.makeCommit("Initial commit");
    team.performPush();
    team.performPull();

    return 0;
}





// ---------------------------------------------------------DRY = DO NOT REPEAT YOURSELF-----------------------------------------------------------


// The DRY principle stands for Don't Repeat Yourself. 
// It's a fundamental software engineering principle that promotes reducing repetition in code to improve maintainability, readability, and reduce bugs.

// using functions by putting the code in function and call it whenever it is needed 
// using inheritance 
// using template 
// using macros 




//-------------------------------------------------KISS = KEEP IT SIMPLE STUPID----------------------------------------------------------------------------

//It’s a core software design principle that emphasizes simplicity — the idea that most systems work best if they are kept simple rather than made complicated.

//Simple Logic Instead of Nested or Complex Code
//Simple Function Usage
// Avoid Overuse of Templates, Inheritance, or Macros


//----------------------------------------------YAGNI = YOU AREN'T GONNA NEED IT--------------------------------------------------------------------------

//“Don’t add functionality until it’s necessary.”

//// Let's assume we *only* need to print an invoice.

// class Printer {
// public:
//     virtual void print() = 0;  // YAGNI violation if we don't plan to extend it
// };

// class InvoicePrinter : public Printer {
// public:
//     void print() override {
//         std::cout << "Printing Invoice..." << std::endl;
//     }
// };

// USING YAGNI

// #include <iostream>

// class InvoicePrinter {
// public:
//     void print() {
//         std::cout << "Printing Invoice..." << std::endl;
//     }
// };




//---------------------------------------LOD=LAW OF DEMETER--------------------------------------------------------

//A class should only talk to its immediate friends, and not to strangers.

class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine;

public:
    void startCar() {
        engine.start();  // ✅ This is OK: Car talks to its own Engine
    }
};


class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

class Car {
public:
    Engine* getEngine() { return &engine; }

private:
    Engine engine;
};

class Driver {
public:
    void startCar(Car& car) {
        car.getEngine()->start();  // ❌ LOD violation – Driver accesses internals of Car
    }
};
