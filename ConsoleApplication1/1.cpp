#include <iostream>
#include <cmath>
#include "1.h"
using namespace std;
int task1() {
    const double cost_per_meter = 29.0;
    double D;
    double PI = 3.14159265358979323846;
    cout << "Введите диаметр отверстия D (в метрах): ";
    cin >> D;
    double circumference = PI * D;
    double total_cost = circumference * cost_per_meter;
    cout << "Стоимость окантовки отверстия: " << total_cost << " руб." << endl;
    return 0;
}
