#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    string name;
    int received;
    int sold;
};

void inputProducts(vector<Product>& products) {
    int n;
    cout << "������� ���������� �������: ";
    cin >> n;
    products.resize(n);

    for (int i = 0; i < n; ++i) {
        cout << "\n����� #" << i + 1 << endl;
        cout << "������������: ";
        cin.ignore();
        getline(cin, products[i].name);
        cout << "��������� �� �����: ";
        cin >> products[i].received;
        cout << "����������� �� �����: ";
        cin >> products[i].sold;
    }
}

void printTurnoverReport(const vector<Product>& products) {
    cout << "\n��������� ���������\n";
    cout << "--------------------------------------------------------\n";
    cout << "| ������������ ������ | ��������� | ����������� | ������� |\n";
    cout << "--------------------------------------------------------\n";

    for (const auto& p : products) {
        int difference = p.received - p.sold;
        cout << "| " << setw(19) << left << p.name
            << " | " << setw(9) << right << p.received
            << " | " << setw(11) << p.sold
            << " | " << setw(7) << difference << " |\n";
    }
    cout << "--------------------------------------------------------\n";
}

void printStockReport(const vector<Product>& products) {
    cout << "\n����� �� �������� �� ������\n";
    cout << "------------------------------------\n";
    cout << "| ������������ ������ | ������� |\n";
    cout << "------------------------------------\n";

    for (const auto& p : products) {
        int balance = p.received - p.sold;
        cout << "| " << setw(19) << left << p.name
            << " | " << setw(7) << right << balance << " |\n";
    }
    cout << "------------------------------------\n";
}

void calculateTotals(const vector<Product>& products) {
    int totalReceived = 0;
    int totalSold = 0;

    for (const auto& p : products) {
        totalReceived += p.received;
        totalSold += p.sold;
    }

    cout << "\n�����:\n";
    cout << "����� ������ ������: " << totalReceived << endl;
    cout << "����� ������ ������: " << totalSold << endl;
    cout << "����� �������: " << totalReceived - totalSold << endl;
}

int main() {
    vector<Product> products;

    inputProducts(products);
    printTurnoverReport(products);
    calculateTotals(products);
    printStockReport(products);

    return 0;
}