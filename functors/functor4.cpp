#include <iostream>

template <typename T>
class Comparator {
public:
    bool operator()(T a, T b) const {
        return a < b; // Default: ascending order
    }
};

int main() {
    Comparator<int> comp;
    std::cout << comp(3, 7) << std::endl; // Output: 1 (true)
    return 0;
}
