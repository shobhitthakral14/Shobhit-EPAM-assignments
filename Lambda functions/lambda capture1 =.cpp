#include<iostream>
using namespace std;


//The [=] capture clause copies the value of x into the lambda.
// x inside the lambda is a copy, so changes inside the lambda do not reflect in the original variable.

// [=]: capture all external variables by value.
int main() {
    int x = 10;
    auto printX = [=]() { std::cout << "Value of x: " << x << std::endl; };
    printX();
    return 0;
}
