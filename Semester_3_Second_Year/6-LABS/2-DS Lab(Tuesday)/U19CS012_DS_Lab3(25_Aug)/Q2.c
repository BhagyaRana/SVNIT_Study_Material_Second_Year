// Write a program (1) to generate sub matrices from the multidimensional matrix.
// (2) Take any two(I took all) sub matrices and perform the addition of two sub matrices.
// For example input Array is A[4][4] and B[2][2]
// (3) Find the occurrence of B in A.
#include <stdio.h>

int mat[101][101], B[101][101], add[101][101];

void print(int rst, int cst, int red, int ced)
{
    printf("Sub-Matrix [%d ... %d] [%d ... %d] :\n", rst, red, cst, ced);
    int addrow = 0;
    int addcol = 0;
    for (int i = rst; i <= red; i++)
    {
        for (int j = cst; j <= ced; j++)
        {
            printf("%d ", mat[i][j]);
            add[addrow][addcol] += mat[i][j];
            addcol++;
        }
        printf("\n");
        addrow++;
        addcol = 0;
    }
    return;
}

int occurances(int rst, int cst, int red, int ced, int B[101][101])
{
    int ans = 0;
    int flag = 1;

    // printf("Sub-Matrix [%d ... %d] [%d ... %d] is being Compared :\n", rst, red, cst, ced);

    int brow = 0;
    int bcol = 0;

    for (int i = rst; i <= red; i++)
    {
        for (int j = cst; j <= ced; j++)
        {
            if (mat[i][j] != B[brow][bcol])
            {
                flag = 0;
                break;
            }
            else
            {
                bcol++;
            }
        }
        brow++;
        bcol = 0;
        if (flag == 0)
        {
            break;
        }
    }

    if (flag)
        ans = 1;

    return ans;
}

int main()
{
    int m, n;
    printf("Enter the Dimensions of Matrix (mXm) (<=100) : \n");
    scanf("%d", &m); // m rows x m columns

    printf("Enter the Values of (mXm) Matrix :\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");

    printf("Task 1 --> Find All Sub-Matrices \n\n");

    printf("Enter the Dimensions of Sub-Matrix (nXn) (<=%d) : \n", m);
    scanf("%d", &n); // n rows x n columns
    if (n > m)
    {
        printf("Enter Valid n value!!\n");
    }
    else
    {
        // printf("%dX%d Parent Matrixes is :\n", m, m);

        // print(0,0,m-1,m-1);

        printf("%dX%d Sub Matrixes are :\n", n, n);
        int rstart = 0, rend = n - 1;
        int cstart = 0, cend = n - 1;

        for (; rend <= m - 1; rend++)
        {
            rstart = rend - n + 1;
            cend = n - 1;
            for (; cend <= m - 1; cend++)
            {
                cstart = cend - n + 1;
                print(rstart, cstart, rend, cend);
            }
        }
    }

    printf("Task 2 --> Sum of all Subsets \n\n");

    printf("Add Matrix(%d X %d)\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Task 3 --> To Find the Occurance of B in A\n\n");

    printf("Enter Values of Sub-Matrix B (%dX%d) (%d <= %d):\n", n, n, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");

    int occur = 0; // count the Number of Occurances

    int rstart = 0, rend = n - 1;
    int cstart = 0, cend = n - 1;

    for (; rend <= m - 1; rend++)
    {
        rstart = rend - n + 1;
        cend = n - 1;
        for (; cend <= m - 1; cend++)
        {
            cstart = cend - n + 1;
            occur += occurances(rstart, cstart, rend, cend, B);
        }
    }

    printf("The Occurance of B in A is : %d", occur);

    return 0;
}
