#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public exception {
    int a;
public:
    MyException(int num) : a(num) {}

    const char* what() const noexcept override {
        return "Custom Exception";
    }

    int getErrorCode() const {
        return a;
    }
};

int main() {
    try {
        int num = 10;
        int den = 0;
        int res;

        if (den == 0) {
            throw MyException(10001);
        }

        res = num / den;
        cout << "Answer: " << res << endl;
    }
    catch (MyException& e) {
        cout << "Exception Code: " << e.what() << endl;
        cout << "Exception Code: " << e.getErrorCode() << endl;
    }

    return 0;
}
