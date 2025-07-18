#include <iostream>
#include <cmath>
#include "4.h"
using namespace std;

int task4() {
    int N;
    double A, B;

    cout << "������� ���������� �������: ";
    cin >> N;
    cout << "������� ��� ������� ������ (��): ";
    cin >> A;
    cout << "������� ��� ���������� ������ (��): ";
    cin >> B;

    if (N == 1) {
        cout << "������: ������ ���� ���� �� 1 �����";
        return 0;
    }
    if (N == 2) {
        cout << "��� ������� ������: " << B * 1000 << " �����";
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
    cout << "��� ������� ������: " << result << " �����";

    return 0;
}