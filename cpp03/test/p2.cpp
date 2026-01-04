#include <cmath>
#include <iostream>
int main() {
    float a = 1.3f;
    float b = 1.7f;
    float c = -1.3f;
    float d = -1.7f;

    std::cout << roundf(a) << "\n"; // 1
    std::cout << roundf(b) << "\n"; // 2
    std::cout << roundf(c) << "\n"; // -1
    std::cout << roundf(d) << "\n"; // -2
}
