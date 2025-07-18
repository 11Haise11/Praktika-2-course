#include <iostream>
#include <cstdlib>
#include <ctime>
#include "6.h"
using namespace std;

bool has_negative(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) return true;
    }
    return false;
}

int count_before_negative(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) return i;
    }
    return size;
}

int sum_before_negative(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) break;
        sum += arr[i];
    }
    return sum;
}

void input_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "������� " << i << ": ";
        cin >> arr[i];
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void remove_before_negative(int arr[], int& size) {
    int pos = count_before_negative(arr, size);
    for (int i = 0; i < size - pos; i++) {
        arr[i] = arr[i + pos];
    }
    size -= pos;
}

void generate_array(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }
}

void get_after_negative(int src[], int src_size, int* dest, int& dest_size) {
    int pos = count_before_negative(src, src_size) + 1;
    dest_size = src_size - pos;
    for (int i = 0; i < dest_size; i++) {
        dest[i] = src[pos + i];
    }
}

int task6() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    cout << "������� ������ �������: ";
    cin >> size;

    input_array(arr, size);
    cout << "������: ";
    print_array(arr, size);

    if (has_negative(arr, size)) {
        cout << "������������� ����" << endl;
        cout << "�� ������� ��������������: " << count_before_negative(arr, size) << endl;
        cout << "����� �� ������� ��������������: " << sum_before_negative(arr, size) << endl;
    }
    else {
        cout << "������������� ���" << endl;
    }

    remove_before_negative(arr, size);
    cout << "����� ��������: ";
    print_array(arr, size);

    generate_array(arr, size);
    cout << "��������������� ������: ";
    print_array(arr, size);

    int new_arr[MAX_SIZE];
    int new_size;
    get_after_negative(arr, size, new_arr, new_size);
    cout << "�������� ����� ������� ��������������: ";
    print_array(new_arr, new_size);

    return 0;
}