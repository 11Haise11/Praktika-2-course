#include <iostream>
#include <cmath>
#include <iomanip>
#include "4.h"
using namespace std;

int task4() {
    int N;
    double A, B;
    double before_prev = 0.0;

    cout << "Введите количество арбузов: ";
    cin >> N;
    cout << "Введите вес первого арбуза (кг): ";
    cin >> A;
    cout << "Введите вес последнего арбуза (кг): ";
    cin >> B;

    if (N <= 0) {
        cerr << "Ошибка: количество арбузов должно быть положительным числом!";
        return 1;
    }
    if (A <= 0 || B <= 0) {
        cerr << "Ошибка: вес арбузов должен быть положительным числом!";
        return 1;
    }

    if (N == 1) {
        cout << "Вес единственного арбуза: " << fixed << setprecision(0) << A * 1000 << " грамм";
        return 0;
    }
    if (N == 2) {
        cout << "Вес второго арбуза: " << fixed << setprecision(0) << B * 1000 << " грамм";
        return 0;
    }

    double prev = A;
    double current = 0.0;

    for (int i = 2; i <= N; ++i) {
        if (i == N) {
            current = B;
        }
        else {
            current = 2 * (prev + 0.1);
            if (i > 2) current -= before_prev;
        }
        before_prev = prev;
        prev = current;
    }

    int result = static_cast<int>(round(current * 1000));
    cout << "Вес второго арбуза: " << result << " грамм";

    return 0;
}

