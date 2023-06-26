/*
Question 7

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3

Output: [[1,2,3],[8,9,4],[7,6,5]]
*/



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) {
        // Fill the top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Fill the right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Fill the bottom row
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // Fill the left column
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;

    vector<vector<int>> matrix = generateMatrix(n);

    printMatrix(matrix);

    return 0;
}