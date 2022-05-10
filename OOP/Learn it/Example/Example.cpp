#include <iostream>
#include <iomanip>
int main() {
    int a, b = 0; //ax + b = 0
    float result;
    std::cin >> a >> b;
    if (a == 0 && b == 0) {
        std::cout << "INF" << std::endl;
    }
    else if (a == 0 && b != 0) {
        std::cout << "NO" << std::endl;
    }
    else {
        result = -b * 1.0 / a;
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    }
    return 0;
}