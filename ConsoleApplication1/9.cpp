#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "9.h"
using namespace std;

string numberLine(int num, const string& line) {
    return to_string(num) + " " + line;
}

string priceToText(int price) {
    int rub = price / 100;
    int kop = price % 100;
    return to_string(rub) + " ���. " +
        (kop < 10 ? "0" + to_string(kop) : to_string(kop)) + " ���.";
}

int task9() {
    string lines[] = { "������ ������", "������ ������", "������ ������" };
    for (int i = 0; i < 3; i++) {
        cout << numberLine(i + 1, lines[i]) << endl;
    }

 
    ifstream fin("F1.txt");
    ofstream fout("F2.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "������ �������� ������!" << endl;
        return 1;
    }

    int price;
    while (fin >> price) {
        fout << price << " -> " << priceToText(price) << endl;
    }

    fin.close();
    fout.close();
    cout << "��������� ������ ���������!" << endl;

    return 0;
}