#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include "7.h"
using namespace std;

struct Student {
    string surname;
    char gender;
    double height;
    double weight;
};

void processStudents(Student students[], int count, double avgWeightBoy, double avgWeightGirl) {
    cout << "Дети выше средней упитанности:\n";
    for (int i = 0; i < count; ++i) {
        double avg = (toupper(students[i].gender) == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight > avg) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " кг\n";
        }
    }

    cout << "\nДети ниже средней упитанности:\n";
    for (int i = 0; i < count; ++i) {
        double avg = (toupper(students[i].gender) == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight < avg) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " кг\n";
        }
    }
}

int task7() {
    const int MAX_SIZE = 30;
    Student group[MAX_SIZE];
    int count;
    double boyAvg, girlAvg;

    cout << "Количество учеников (1-" << MAX_SIZE << "): ";
    while (!(cin >> count) || count < 1 || count > MAX_SIZE) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите число от 1 до " << MAX_SIZE << ": ";
    }

    for (int i = 0; i < count; ++i) {
        cout << "\nУченик #" << i + 1 << ":\n";

        cout << "Фамилия: ";
        cin.ignore();
        getline(cin, group[i].surname);

        cout << "Пол (M/F): ";
        while (!(cin >> group[i].gender) ||
            (toupper(group[i].gender) != 'M' && toupper(group[i].gender) != 'F')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите M или F: ";
        }

        cout << "Рост (см): ";
        while (!(cin >> group[i].height) || group[i].height <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }

        cout << "Вес (кг): ";
        while (!(cin >> group[i].weight) || group[i].weight <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }
    }

    cout << "\nСредний вес мальчиков (кг): ";
    while (!(cin >> boyAvg) || boyAvg <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное число: ";
    }

    cout << "Средний вес девочек (кг): ";
    while (!(cin >> girlAvg) || girlAvg <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное число: ";
    }

    processStudents(group, count, boyAvg, girlAvg);
    return 0;
}

int task7p() {
    return task7();
}