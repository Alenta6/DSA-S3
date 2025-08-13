#include<stdio.h>
#define MAX 100

struct tp {
    int r, c, val;
};

int input(struct tp mat[MAX], int rows, int cols) {
    int nzCount = 0;
    printf("Enter number of non-zero elements: ");
    scanf("%d", &nzCount);

    for (int i = 0; i < nzCount; i++) {
        printf("Enter r, c, and value of element %d: ", i + 1);
        scanf("%d %d %d", &mat[i].r, &mat[i].c, &mat[i].val);
    }

    return nzCount;
}

int addSM(struct tp m1[MAX], int n1, struct tp m2[MAX], int n2, struct tp res[MAX]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (m1[i].r == m2[j].r) {
            if (m1[i].c == m2[j].c) {
                res[k].r = m1[i].r;
                res[k].c = m1[i].c;
                res[k].val = m1[i].val + m2[j].val;
                i++;
                j++;
                k++;
            } else if (m1[i].c < m2[j].c) {
                res[k] = m1[i];
                i++;
                k++;
            } else {
                res[k] = m2[j];
                j++;
                k++;
            }
        } else if (m1[i].r < m2[j].r) {
            res[k] = m1[i];
            i++;
            k++;
        } else {
            res[k] = m2[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        res[k] = m1[i];
        i++;
        k++;
    }
    while (j < n2) {
        res[k] = m2[j];
        j++;
        k++;
    }

    return k;
}

int transposeSM(struct tp mat[MAX], int n, struct tp res[MAX]) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        res[k].r = mat[i].c;
        res[k].c = mat[i].r;
        res[k].val = mat[i].val;
        k++;
    }

    return k;
}

void printSM(struct tp mat[MAX], int n) {
    printf("r\tc\tval\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", mat[i].r, mat[i].c, mat[i].val);
    }
}

int main() {
    int r, c;
    struct tpxc8 mat1[MAX], mat2[MAX], result[MAX], transposed[MAX];
    int n1, n2, n3, n4;

    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter first sparse matrix:\n");
    n1 = inputSM(mat1, r, c);

    printf("Enter second sparse matrix:\n");
    n2 = inputSM(mat2, r, c);

    n3 = addSM(mat1, n1, mat2, n2, result);
    
    printf("Resultant matrix (tuple form):\n");
    printSM(result, n3);

    n4 = transposeSM(result, n3, transposed);

    printf("Transpose of result matrix (tuple form):\n");
    printSM(transposed, n4);

    return 0;
}

	
