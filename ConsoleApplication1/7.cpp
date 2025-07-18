#include <iostream>
#include <string>
#include "7.h"
using namespace std;

struct Student {
    string surname;
    char gender;
    double height;
    double weight;
};

void findStudents(Student students[], int count, double avgWeightBoy, double avgWeightGirl) {
    cout << "Дети выше средней упитанности:" << endl;
    for (int i = 0; i < count; i++) {
        double avgWeight = (students[i].gender == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight > avgWeight) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " кг" << endl;
        }
    }

    cout << "\nДети ниже средней упитанности:" << endl;
    for (int i = 0; i < count; i++) {
        double avgWeight = (students[i].gender == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight < avgWeight) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " кг" << endl;
        }
    }
}

int task7() {
    const int MAX_STUDENTS = 30;
    Student class[MAX_STUDENTS];
    int studentCount;
    double avgWeightBoy, avgWeightGirl;

    cout << "Введите количество учеников: ";
    cin >> studentCount;

    for (int i = 0; i < studentCount; i++) {
        cout << "\nУченик #" << i + 1 << endl;
        cout << "Фамилия: ";
        cin >> class[i].surname;
        cout << "Пол (M/F): ";
        cin >> class[i].gender;
        cout << "Рост (см): ";
        cin >> class[i].height;
        cout << "Вес (кг): ";
        cin >> class[i].weight;
    }

    cout << "\nВведите средний вес для мальчиков (кг): ";
    cin >> avgWeightBoy;
    cout << "Введите средний вес для девочек (кг): ";
    cin >> avgWeightGirl;

    findStudents(class, studentCount, avgWeightBoy, avgWeightGirl);

    return 0;
}