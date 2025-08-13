#include <stdio.h>

struct Polynomial {
int coeff;
int expo;
};

int main() {
int n1, n2, i, j, k;

printf("Enter the number of terms in first polynomial: ");
scanf("%d", &n1);

struct Polynomial p1[n1];
for (i = 0; i < n1; i++) {
printf("Enter the coefficient of term %d: ", i + 1);
scanf("%d", &p1[i].coeff);
printf("Enter the exponent of term %d: ", i + 1);
scanf("%d", &p1[i].expo);
}

printf("\nEnter the number of terms in second polynomial: ");
scanf("%d", &n2);

struct Polynomial p2[n2];
for (i = 0; i < n2; i++) {
printf("Enter the coefficient of term %d: ", i + 1);
scanf("%d", &p2[i].coeff);
printf("Enter the exponent of term %d: ", i + 1);
scanf("%d", &p2[i].expo);
}

struct Polynomial res[n1 + n2];
i = 0; j = 0; k = 0;

while (i < n1 && j < n2) {
if (p1[i].expo == p2[j].expo) {
int sumCoeff = p1[i].coeff + p2[j].coeff;
if (sumCoeff != 0) {
res[k].coeff = sumCoeff;
res[k].expo = p1[i].expo;
k++;
}
i++;
j++;
} else if (p1[i].expo > p2[j].expo) {
res[k++] = p1[i++];
} else {
res[k++] = p2[j++];
}
}

while (i < n1) {
res[k++] = p1[i++];
}

while (j < n2) {
res[k++] = p2[j++];
}

printf("\nFirst polynomial: ");
for (i = 0; i < n1; i++) {
if (p1[i].coeff == 0) continue;
if (i > 0 && p1[i].coeff > 0) printf("+");
printf("%dx^%d", p1[i].coeff, p1[i].expo);
}

printf("\nSecond polynomial: ");
for (i = 0; i < n2; i++) {
if (p2[i].coeff == 0) continue;
if (i > 0 && p2[i].coeff > 0) printf("+");
printf("%dx^%d", p2[i].coeff, p2[i].expo);
}

printf("\nResultant polynomial after addition: ");
if (k == 0) {
printf("0");
} else {
for (i = 0; i < k; i++) {
if (res[i].coeff > 0 && i > 0) printf("+");
printf("%dx^%d", res[i].coeff, res[i].expo);
}
}

printf("\n");
return 0;
}



	
