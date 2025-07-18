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
        cout << "������� ������ ��������� (N1): ";
        cin >> N1;
        cout << "������� ����� ��������� (N2): ";
        cin >> N2;

        if (N1 > N2) {
            cout << "������: N1 ������ ���� ������ ��� ����� N2!" << endl;
        }
        else {
            cout << "�����, ������ ����� ����� ����� ����: ";
            bool found = false;
            for (int i = N1; i <= N2; ++i) {
                if (isSumOfCubes(i)) {
                    cout << i << " ";
                    found = true;
                }
            }
            if (!found) {
                cout << "����� ����� ���";
            }
            cout << endl;
        }

        cout << "������ ����������? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}