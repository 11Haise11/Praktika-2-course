#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

double calculateDistance(const vector<vector<int>>& matrix, int k, int l) {
    double distance = 0.0;
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        distance += matrix[k][j] * matrix[l][j];
    }
    return distance;
}

pair<int, int> findMinDistanceRows(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    double minDistance = INT_MAX;
    pair<int, int> result = { 0, 1 };

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double currentDistance = calculateDistance(matrix, i, j);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                result = { i, j };
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    cout << "Введите количество строк (n) и столбцов (m): ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    auto [row1, row2] = findMinDistanceRows(matrix);
    cout << "Минимальное расстояние между строками " << row1 << " и " << row2 << endl;

    return 0;
}