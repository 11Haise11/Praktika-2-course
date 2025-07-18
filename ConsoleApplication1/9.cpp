#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Функция для нумерации строк
string numberLine(int num, const string& line) {
    return to_string(num) + " " + line;
}

// Функция для преобразования цены в текст
string priceToText(int price) {
    int rub = price / 100;
    int kop = price % 100;
    return to_string(rub) + " руб. " +
        (kop < 10 ? "0" + to_string(kop) : to_string(kop)) + " коп.";
}

int main() {
    // Задача 1: Нумерация строк
    string lines[] = { "Первая строка", "Вторая строка", "Третья строка" };
    for (int i = 0; i < 3; i++) {
        cout << numberLine(i + 1, lines[i]) << endl;
    }

    // Задача 2: Обработка цен из файла
    ifstream fin("F1.txt");
    ofstream fout("F2.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    int price;
    while (fin >> price) {
        fout << price << " -> " << priceToText(price) << endl;
    }

    fin.close();
    fout.close();
    cout << "Обработка файлов завершена!" << endl;

    return 0;
}