#include <iostream>
#include <cmath>
#include "3.h"
using namespace std;

bool isSumOfCubes(int num) {
    if (num < 1) return false;
    int original = num;
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, 3);
        num /= 10;
    }
    return sum == original;
}

int task3() {
    char choice;
    do {
        int N1, N2;
        cout << "¬ведите начало диапазона (N1): ";
        cin >> N1;
        cout << "¬ведите конец диапазона (N2): ";
        cin >> N2;

        if (N1 > N2) {
            cout << "ќшибка: N1 должно быть меньше или равно N2!" << endl;
        }
        else {
            cout << "„исла, равные сумме кубов своих цифр: ";
            bool found = false;
            for (int i = N1; i <= N2; ++i) {
                if (isSumOfCubes(i)) {
                    cout << i << " ";
                    found = true;
                }
            }
            if (!found) {
                cout << "таких чисел нет";
            }
            cout << endl;
        }

        cout << "’отите продолжить? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}