
#include <stdio.h>

#define MAX 100

void readMatrix(int mat[MAX][3]) {
    int t;
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &mat[0][0], &mat[0][1], &mat[0][2]);
    t = mat[0][2];
    printf("Enter the triplets (row col value):\n");
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }
}

void display(int mat[MAX][3]) {
    printf("Row Col Value\n");
    for (int i = 0; i <= mat[0][2]; i++) {
        printf("%3d %4d %5d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
    printf("\n");
}

void sparseAdd(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    int r1 = A[0][0], c1 = A[0][1], t1 = A[0][2];
    int r2 = B[0][0], c2 = B[0][1], t2 = B[0][2];

    if (r1 != r2 || c1 != c2) {
        printf("Incompatible matrix sizes.\n");
        C[0][2] = 0;
        return;
    }

    C[0][0] = r1;
    C[0][1] = c1;

    int m = 1, n = 1, k = 1;

    while (m <= t1 && n <= t2) {
        if (A[m][0] == B[n][0] && A[m][1] == B[n][1]) {
            C[k][0] = A[m][0];
            C[k][1] = A[m][1];
            C[k][2] = A[m][2] + B[n][2];
            m++; n++; k++;
        } else if (A[m][0] < B[n][0] || (A[m][0] == B[n][0] && A[m][1] < B[n][1])) {
            C[k][0] = A[m][0];
            C[k][1] = A[m][1];
            C[k][2] = A[m][2];
            m++; k++;
        } else {
            C[k][0] = B[n][0];
            C[k][1] = B[n][1];
            C[k][2] = B[n][2];
            n++; k++;
        }
    }

    while (m <= t1) {
        C[k][0] = A[m][0];
        C[k][1] = A[m][1];
        C[k][2] = A[m][2];
        m++; k++;
    }

    while (n <= t2) {
        C[k][0] = B[n][0];
        C[k][1] = B[n][1];
        C[k][2] = B[n][2];
        n++; k++;
    }

    C[0][2] = k - 1;
}

void sparseTranspose(int A[MAX][3], int T[MAX][3]) {
    int k = 1;
    int m = A[0][1]; 
    int n = A[0][2];

    T[0][0] = A[0][1];  
    T[0][1] = A[0][0];
    T[0][2] = n;

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[j][1] == i) {
                T[k][0] = A[j][1];
                T[k][1] = A[j][0];
                T[k][2] = A[j][2];
                k++;hile (j <= m) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
            }
        }
    }
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3], T[MAX][3];

    printf("Enter Matrix A:\n");
    readMatrix(A);

    printf("Enter Matrix B:\n");
    readMatrix(B);

    printf("\nMatrix A (Triplet Form):\n");
    display(A);

    printf("Matrix B (Triplet Form):\n");
    display(B);

    sparseAdd(A, B, C);

    printf("Sum Matrix C (A + B):\n");
    display(C);

    sparseTranspose(C, T);

    printf("Transpose of C:\n");
    display(T);

    return 0;
}

	
