#include <iostream>
#include <cmath>
#include "4.h"
using namespace std;

int task4() {
    int N;
    double A, B;

    cout << "Введите количество арбузов: ";
    cin >> N;
    cout << "Введите вес первого арбуза (кг): ";
    cin >> A;
    cout << "Введите вес последнего арбуза (кг): ";
    cin >> B;

    if (N == 1) {
        cout << "Ошибка: должен быть хотя бы 1 арбуз";
        return 0;
    }
    if (N == 2) {
        cout << "Вес второго арбуза: " << B * 1000 << " грамм";
        return 0;
    }

    double prev = A;
    double current = 0;

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

    int result = round(current * 1000);
    cout << "Вес второго арбуза: " << result << " грамм";

    return 0;
}