#include <bits/stdc++.h>

using namespace std;

// Change this According to Your Requirement [Constraints on N]
#define MAX_N 100

// Dimensions of A[n1*m1] & B[n2*m2]
int n1, n2, m1, m2;

// 2 Dimensions Matrix [A,B & C]
vector<vector<int>> A(MAX_N, vector<int>(MAX_N, 0));
vector<vector<int>> B(MAX_N, vector<int>(MAX_N, 0));
vector<vector<int>> C(MAX_N, vector<int>(MAX_N, 0));

// Brute Force Method to Multiply Two Matrices 0(N^3)
void matrix_multiply()
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < m1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return;
}

int main()
{
    // Dimensions of Matrix A
    cout << "Enter Dimensions of Matrix 1 [row col]: " << endl;
    cin >> n1 >> m1;
    cout << "Enter the Values in Matrix 1:" << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            // cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Enter Dimensions of Matrix 2 [row col]: " << endl;
    // Dimensions of Matrix B
    cin >> n2 >> m2;
    cout << "Enter the Values in Matrix 2:" << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            // cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    if (m1 != n2)
    {
        cout << "Matrix Can't Be Multiplied!" << endl;
        cout << "For Matrix Multiplication,\n No. Of Columns [Matrix-1] Must be Equal No. Of Rows [Matrix-2]!" << endl;
    }
    else
    {
        // n1 * m2 = Dimensions of C
        matrix_multiply();

        cout << "MATRIX A:" << endl;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m1; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "MATRIX B:" << endl;
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        cout << "MATRIX C [AXB]:" << endl;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}