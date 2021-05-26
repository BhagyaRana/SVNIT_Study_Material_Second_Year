#include <bits/stdc++.h>

using namespace std;

// Matrix Operations
// To Intialise the Matrix
int **init_matrix(int n);

// To Take Input to Matrix
void input(int **M, int n);

// To Print the Matrix
void print_matrix(int **M, int n);

// To Add Two Matrices of Size( n X n )
int **add(int **M1, int **M2, int n);

// To Subtract Two Matrices of Size( n X n )
int **subtract(int **M1, int **M2, int n);

// Strassen Multiplication Function
int **Strassen_Multiply(int **A, int **B, int n);

// Checks if n is Power of 2 or Not
bool check(int x)
{
    return x && (!(x & (x - 1)));
}

int main()
{
    cout << "Enter Size of the Matrix (Power of 2): ";

    int n;
    cin >> n;

    if (check(n))
    {
        int **A = init_matrix(n);
        input(A, n);

        int **B = init_matrix(n);
        input(B, n);

        cout << "Matrix A:" << endl;
        print_matrix(A, n);

        cout << "Matrix B:" << endl;
        print_matrix(B, n);

        int **C = init_matrix(n);
        C = Strassen_Multiply(A, B, n);

        cout << "MATRIX C [AXB]:" << endl;
        print_matrix(C, n);
    }
    else
    {
        cout << "Matrix Can't Be Multiplied!" << endl;
        cout << "Strassian Multiplication => Only Works on Square Matrices whose Dimension is a Power of 2!\n";
    }

    return 0;
}

// --------------------------------MATRIX_OPERATIONS------------------------------------

// To Intialise the Matrix
int **init_matrix(int n)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

// To Take Input to Matrix
void input(int **M, int n)
{
    cout << "Enter Matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    cout << endl;
}

// To Print the Matrix
void print_matrix(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// To Add Two Matrices of Size( n X n )
int **add(int **M1, int **M2, int n)
{
    int **temp = init_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

// To Subtract Two Matrices of Size( n X n )
int **subtract(int **M1, int **M2, int n)
{
    int **temp = init_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}

// -----------------------------------------------------------------------------------

// Strassen Multiplication Function
int **Strassen_Multiply(int **A, int **B, int n)
{
    // Base Case
    if (n == 1)
    {
        int **C = init_matrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int **C = init_matrix(n);
    int k = n / 2;

    int **A11 = init_matrix(k);
    int **A12 = init_matrix(k);
    int **A21 = init_matrix(k);
    int **A22 = init_matrix(k);
    int **B11 = init_matrix(k);
    int **B12 = init_matrix(k);
    int **B21 = init_matrix(k);
    int **B22 = init_matrix(k);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }
    }

    int **P1 = Strassen_Multiply(A11, subtract(B12, B22, k), k);
    int **P2 = Strassen_Multiply(add(A11, A12, k), B22, k);
    int **P3 = Strassen_Multiply(add(A21, A22, k), B11, k);
    int **P4 = Strassen_Multiply(A22, subtract(B21, B11, k), k);
    int **P5 = Strassen_Multiply(add(A11, A22, k), add(B11, B22, k), k);
    int **P6 = Strassen_Multiply(subtract(A12, A22, k), add(B21, B22, k), k);
    int **P7 = Strassen_Multiply(subtract(A11, A21, k), add(B11, B12, k), k);

    int **C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    int **C12 = add(P1, P2, k);
    int **C21 = add(P3, P4, k);
    int **C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }
    }

    return C;
}