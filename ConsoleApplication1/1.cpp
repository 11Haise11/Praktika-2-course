#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const double cost_per_meter = 29.0;
    double D;
    cout << "������� ������� ��������� D (� ������): ";
    cin >> D;
    double circumference = M_PI * D;
    double total_cost = circumference * cost_per_meter;
    cout << "��������� ��������� ���������: " << total_cost << " ���." << endl;
    return 0;
}
