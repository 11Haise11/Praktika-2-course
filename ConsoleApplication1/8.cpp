#include <iostream>
#include <vector>
#include <climits>
#include "8.h"
using namespace std;

double computeRowDistance(const vector<vector<int>>& mat, int row1, int row2) {
    double dist = 0.0;
    int cols = mat[0].size();
    for (int j = 0; j < cols; j++) {
        dist += mat[row1][j] * mat[row2][j];
    }
    return dist;
}

void findClosestRows(const vector<vector<int>>& mat, int& r1, int& r2) {
    int rows = mat.size();
    double minDist = INT_MAX;
    r1 = 0;
    r2 = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            double currDist = computeRowDistance(mat, i, j);
            if (currDist < minDist) {
                minDist = currDist;
                r1 = i;
                r2 = j;
            }
        }
    }
}

int task8() {
    int rows, cols;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int row1, row2;
    findClosestRows(matrix, row1, row2);
    cout << "Строки с минимальным расстоянием: " << row1 + 1 << " и " << row2 + 1 << endl;

    return 0;
}

int task8p() {
    return task8();
}