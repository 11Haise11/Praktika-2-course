#include <iostream>
#include <cmath>
#include <iomanip>
#include "4.h"
using namespace std;

int task4() {
    int N;
    double A, B;
    double before_prev = 0.0;

    cout << "������� ���������� �������: ";
    cin >> N;
    cout << "������� ��� ������� ������ (��): ";
    cin >> A;
    cout << "������� ��� ���������� ������ (��): ";
    cin >> B;

    if (N <= 0) {
        cerr << "������: ���������� ������� ������ ���� ������������� ������!";
        return 1;
    }
    if (A <= 0 || B <= 0) {
        cerr << "������: ��� ������� ������ ���� ������������� ������!";
        return 1;
    }

    if (N == 1) {
        cout << "��� ������������� ������: " << fixed << setprecision(0) << A * 1000 << " �����";
        return 0;
    }
    if (N == 2) {
        cout << "��� ������� ������: " << fixed << setprecision(0) << B * 1000 << " �����";
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
    cout << "��� ������� ������: " << result << " �����";

    return 0;
}

