#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "10.h"
using namespace std;

const int PRICE_PER_SEAT = 300; 

void loadHall(vector<vector<bool>>& hall, int n, int m) {
    ifstream file("hall.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                file >> hall[i][j];
            }
        }
        file.close();
    }
}

void saveHall(const vector<vector<bool>>& hall) {
    ofstream file("hall.txt");
    for (const auto& row : hall) {
        for (bool seat : row) {
            file << seat << " ";
        }
        file << endl;
    }
    file.close();
}

void showHall(const vector<vector<bool>>& hall) {
    cout << "\n  ";
    for (int j = 0; j < hall[0].size(); ++j) {
        cout << setw(3) << j + 1;
    }
    cout << "\n";

    for (int i = 0; i < hall.size(); ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < hall[i].size(); ++j) {
            cout << setw(3) << (hall[i][j] ? "[X]" : "[ ]");
        }
        cout << "\n";
    }
}

bool bookSeat(vector<vector<bool>>& hall, int row, int seat) {
    if (row < 1 || row > hall.size() || seat < 1 || seat > hall[0].size()) {
        cout << "Неверный номер места!\n";
        return false;
    }
    if (hall[row - 1][seat - 1]) {
        cout << "Место уже занято!\n";
        return false;
    }
    hall[row - 1][seat - 1] = true;
    return true;
}

int task10() {
    int n, m;
    cout << "Введите количество рядов: ";
    cin >> n;
    cout << "Введите количество мест в ряду: ";
    cin >> m;

    vector<vector<bool>> hall(n, vector<bool>(m, false));
    loadHall(hall, n, m);

    while (true) {
        showHall(hall);
        cout << "\n1. Забронировать место\n2. Выход\nВыберите действие: ";
        int choice;
        cin >> choice;

        if (choice == 2) break;

        int row, seat;
        cout << "Введите номер ряда: ";
        cin >> row;
        cout << "Введите номер места: ";
        cin >> seat;

        if (bookSeat(hall, row, seat)) {
            cout << "Место " << row << "-" << seat << " забронировано!\n";
            cout << "Стоимость: " << PRICE_PER_SEAT << " руб.\n";
            saveHall(hall);
        }
    }

    return 0;
}