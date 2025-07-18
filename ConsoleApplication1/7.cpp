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
    cout << "���� ���� ������� �����������:" << endl;
    for (int i = 0; i < count; i++) {
        double avgWeight = (students[i].gender == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight > avgWeight) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " ��" << endl;
        }
    }

    cout << "\n���� ���� ������� �����������:" << endl;
    for (int i = 0; i < count; i++) {
        double avgWeight = (students[i].gender == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight < avgWeight) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " ��" << endl;
        }
    }
}

int task7() {
    const int MAX_STUDENTS = 30;
    Student class[MAX_STUDENTS];
    int studentCount;
    double avgWeightBoy, avgWeightGirl;

    cout << "������� ���������� ��������: ";
    cin >> studentCount;

    for (int i = 0; i < studentCount; i++) {
        cout << "\n������ #" << i + 1 << endl;
        cout << "�������: ";
        cin >> class[i].surname;
        cout << "��� (M/F): ";
        cin >> class[i].gender;
        cout << "���� (��): ";
        cin >> class[i].height;
        cout << "��� (��): ";
        cin >> class[i].weight;
    }

    cout << "\n������� ������� ��� ��� ��������� (��): ";
    cin >> avgWeightBoy;
    cout << "������� ������� ��� ��� ������� (��): ";
    cin >> avgWeightGirl;

    findStudents(class, studentCount, avgWeightBoy, avgWeightGirl);

    return 0;
}