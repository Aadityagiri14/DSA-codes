#include<iostream>
using namespace std;

void strassen(int A[4][4], int B[4][4], int C[4][4]) {
    int m1, m2, m3, m4, m5, m6, m7;

    m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    m2 = (A[1][0] + A[1][1]) * B[0][0];
    m3 = A[0][0] * (B[0][1] - B[1][1]);
    m4 = A[1][1] * (B[1][0] - B[0][0]);
    m5 = (A[0][0] + A[0][1]) * B[1][1];
    m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

int main() {
    int A[4][4] = {
        {12, 34, 19, 16},
        {22, 10, 15, 20},
        {18, 65, 52, 36},
        {19, 38, 15, 14}
    };

    int B[4][4] = {
        {3, 4, 9, 1},
        {2, 1, 5, 2},
        {4, 8, 2, 7},
        {7, 2, 1, 4}
    };

    int C[4][4];

    cout << "Matrix A:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix B:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }

    strassen(A, B, C);

    cout << "\nResultant Matrix C (A * B) using Strassen's algorithm:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
