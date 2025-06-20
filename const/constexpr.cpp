
//constexpr ensures compile-time evaluation, while const only prevents runtime modification.


#include<iostream>
using namespace std;

constexpr int square(int x) {
    return x * x;
}
int main()
    {
        const int value = 10;  // Constant but evaluated at runtime
        constexpr int result = square(5);  // Evaluated at compile-time
        cout<<result<<endl;
        return 0;
    }