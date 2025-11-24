#include <stdio.h>

int main () {
    int ar[6][6]; // 5x5 matrix + 1 row and 1 column for sums
    int i, j;
    int n = 5; // actual data size (before sum row/column)

    // Input matrix values
    printf("Enter 5x5 matrix values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }

    // 1. Sum of horizontal lines (rows) ? store in column 5
    for (i = 0; i < n; i++) {
        int rowSum = 0;
        for (j = 0; j < n; j++) {
            rowSum += ar[i][j];
        }
        ar[i][n] = rowSum; // store in column 6 (index 5)
    }

    // 2. Sum of vertical lines (columns) ? store in row 5
    for (j = 0; j < n; j++) {
        int colSum = 0;
        for (i = 0; i < n; i++) {
            colSum += ar[i][j];
        }
        ar[n][j] = colSum; // store in row 6 (index 5)
    }

    // 3. Sum of diagonals ? store in bottom-right corner (ar[5][5])
    int mainDiag = 0, secDiag = 0;
    for (i = 0; i < n; i++) {
        mainDiag += ar[i][i];
        secDiag += ar[i][n - 1 - i];
    }
    ar[n][n] = mainDiag + secDiag;

    // Print final matrix (with sums)
    printf("\nFinal 6x6 matrix (with sums):\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%5d", ar[i][j]);
        }
        printf("\n");
    }

    return 0;
}
