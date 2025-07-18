#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double a1, b1, a2, b2;

        cout << "Введите первый интервал [a1, b1]: ";
        cin >> a1 >> b1;
        cout << "Введите второй интервал [a2, b2]: ";
        cin >> a2 >> b2;

        if (a1 > b1 || a2 > b2) {
            cout << "Ошибка: левая граница интервала должна быть меньше правой!" << endl;
        }
        else {
            if (a1 >= a2 && b1 <= b2) {
                cout << "Первый интервал полностью принадлежит второму" << endl;
            }
            else if (a2 >= a1 && b2 <= b1) {
                cout << "Второй интервал полностью принадлежит первому" << endl;
            }
            else if (b1 >= a2 && b2 >= a1) {
                cout << "Интервалы пересекаются" << endl;
            }
            else {
                cout << "Интервалы не пересекаются" << endl;
            }
        }

        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}