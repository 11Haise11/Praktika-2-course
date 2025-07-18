#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "10.h"
using namespace std;

const int SEAT_PRICE = 300;

void loadHallState(vector<vector<bool>>& hall) {
    ifstream file("hall.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < hall.size(); ++i) {
            for (size_t j = 0; j < hall[i].size(); ++j) {
                int temp;
                file >> temp;
                hall[i][j] = temp;
            }
        }
        file.close();
    }
}

void saveHallState(const vector<vector<bool>>& hall) {
    ofstream file("hall.txt");
    for (const auto& row : hall) {
        for (bool seat : row) {
            file << seat << ' ';
        }
        file << '\n';
    }
    file.close();
}

void displayHall(const vector<vector<bool>>& hall) {
    cout << "\n  ";
    for (size_t j = 0; j < hall[0].size(); ++j) {
        cout << setw(4) << j + 1;
    }
    cout << "\n";

    for (size_t i = 0; i < hall.size(); ++i) {
        cout << i + 1 << " ";
        for (size_t j = 0; j < hall[i].size(); ++j) {
            cout << setw(4) << (hall[i][j] ? "[X]" : "[ ]");
        }
        cout << "\n";
    }
}

bool bookSeat(vector<vector<bool>>& hall, int row, int seat) {
    if (row < 1 || row > static_cast<int>(hall.size()) ||
        seat < 1 || seat > static_cast<int>(hall[0].size())) {
        cout << "Ошибка: неверный номер места!\n";
        return false;
    }
    if (hall[row - 1][seat - 1]) {
        cout << "Ошибка: место уже занято!\n";
        return false;
    }
    hall[row - 1][seat - 1] = true;
    return true;
}

int task10() {
    int rows, cols;
    cout << "Система бронирования мест\n";
    cout << "Введите количество рядов: ";
    cin >> rows;
    cout << "Введите количество мест в ряду: ";
    cin >> cols;

    vector<vector<bool>> hall(rows, vector<bool>(cols, false));
    loadHallState(hall);

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Показать схему зала\n";
        cout << "2. Забронировать место\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        if (choice == 3) break;

        switch (choice) {
        case 1:
            displayHall(hall);
            break;
        case 2: {
            int row, seat;
            cout << "Введите номер ряда: ";
            cin >> row;
            cout << "Введите номер места: ";
            cin >> seat;

            if (bookSeat(hall, row, seat)) {
                cout << "Место " << row << "-" << seat << " забронировано!\n";
                cout << "Стоимость: " << SEAT_PRICE << " руб.\n";
                saveHallState(hall);
            }
            break;
        }
        default:
            cout << "Неверный выбор!\n";
        }
    }

    return 0;
}

int task10p() {
    return task10();
}