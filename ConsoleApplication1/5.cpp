#include <iostream>
#include <iomanip>
#include "5.h"
using namespace std;

double my_pow(double num, int p) {
    double res = 1.0;
    int n = (p > 0) ? p : -p;

    for (int i = 0; i < n; i++) {
        res *= num;
    }

    return (p >= 0) ? res : 1.0 / res;
}

int task5() {
    cout << "  x   | x^2  | x^-1 | x^0" << endl;
    cout << "------|------|------|------" << endl;

    for (double x = -2.0; x <= 2.0; x += 0.5) {
        if (x == 0.0) continue;

        cout << fixed << setprecision(1);
        cout << setw(5) << x << " |";

        cout << setprecision(3);
        cout << setw(6) << my_pow(x, 2) << " |";
        cout << setw(6) << my_pow(x, -1) << " |";
        cout << setw(4) << my_pow(x, 0) << endl;
    }

    return 0;
}