#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double D, d, cost;
    std::cin >> D >> d >> cost;

    const double PI = 3.14159265358979323846;
    double length = PI * D;
    int pearls = static_cast<int>(std::ceil(length / d));

    std::cout.precision(6);
    std::cout << pearls * cost << std::endl;

    return 0;
}