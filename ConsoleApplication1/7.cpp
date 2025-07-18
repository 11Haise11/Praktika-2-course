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
    cout << "���� ���� ������� �����������:\n";
    for (int i = 0; i < count; ++i) {
        double avg = (toupper(students[i].gender) == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight > avg) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " ��\n";
        }
    }

    cout << "\n���� ���� ������� �����������:\n";
    for (int i = 0; i < count; ++i) {
        double avg = (toupper(students[i].gender) == 'M') ? avgWeightBoy : avgWeightGirl;
        if (students[i].weight < avg) {
            cout << students[i].surname << " (" << students[i].gender << "): "
                << students[i].weight << " ��\n";
        }
    }
}

int task7() {
    const int MAX_SIZE = 30;
    Student group[MAX_SIZE];
    int count;
    double boyAvg, girlAvg;

    cout << "���������� �������� (1-" << MAX_SIZE << "): ";
    while (!(cin >> count) || count < 1 || count > MAX_SIZE) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������! ������� ����� �� 1 �� " << MAX_SIZE << ": ";
    }

    for (int i = 0; i < count; ++i) {
        cout << "\n������ #" << i + 1 << ":\n";

        cout << "�������: ";
        cin.ignore();
        getline(cin, group[i].surname);

        cout << "��� (M/F): ";
        while (!(cin >> group[i].gender) ||
            (toupper(group[i].gender) != 'M' && toupper(group[i].gender) != 'F')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������! ������� M ��� F: ";
        }

        cout << "���� (��): ";
        while (!(cin >> group[i].height) || group[i].height <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������! ������� ������������� �����: ";
        }

        cout << "��� (��): ";
        while (!(cin >> group[i].weight) || group[i].weight <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������! ������� ������������� �����: ";
        }
    }

    cout << "\n������� ��� ��������� (��): ";
    while (!(cin >> boyAvg) || boyAvg <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������! ������� ������������� �����: ";
    }

    cout << "������� ��� ������� (��): ";
    while (!(cin >> girlAvg) || girlAvg <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������! ������� ������������� �����: ";
    }

    processStudents(group, count, boyAvg, girlAvg);
    return 0;
}

int task7p() {
    return task7();
}