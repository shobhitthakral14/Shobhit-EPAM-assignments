// Adapter Pattern is a structural design pattern used to make two incompatible interfaces work together.
// It acts as a bridge between two incompatible interfaces, allowing them to collaborate without modifying their source code.
// This pattern is particularly useful when integrating legacy code or third-party libraries into your application.




#include <iostream>
using namespace std;

// Target Interface
class Printer {
public:
    virtual void printDocument() = 0;
    virtual ~Printer() = default;
};

// Adaptee (incompatible interface)
class LegacyPrinter {
public:
    void oldPrint() {
        cout << "Printing using legacy printer...\n";
    }
};

// Adapter using composition
class PrinterAdapter : public Printer {
    LegacyPrinter* legacyPrinter;
public:
    PrinterAdapter(LegacyPrinter* lp) : legacyPrinter(lp) {}
    
    void printDocument() override {
        legacyPrinter->oldPrint();  // Adapting call
    }
};

int main() {
    LegacyPrinter* lp = new LegacyPrinter();
    Printer* printer = new PrinterAdapter(lp);
    
    printer->printDocument();  // Works via adapter

    delete lp;
    delete printer;
    return 0;
}
