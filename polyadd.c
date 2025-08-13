#include<stdio.h>
struct Term{
    int coeff;
    int exp;
};
int main()
struct Term P1[10],P2[10],P3[20];
int n1,n2,i,j,k,x;
    printf("enter the number of terms in the first polynomial: ");
    scanf("%d",&n1);
    printf("enter the coefficient and exponent for each term of P1: \n");
    for(i=0;i<n1;i++)
    { 
        printf("Term %d:",i+1);
        scanf("%d,%d",&P[i].coeff,&P[i].exp);
    } 

    printf("enter the number of terms in the second polynominal: ");
    scanf("%d",&n2);
    printf("enter the coefficient and exponent for each term of P2: \n");
    for (j=0;j<n2;j++)
    {
        printf("Term %d"j+1);
        scanf("%d,%d,",&P[j].coeff,&P[j].exp);
    }
    i=j=k=0;
    while(i<n1 && j<n2){
        if (P1[i].exp==P2[j].exp){
            P3[k].coeff=P1[i].coeff+P2[j].coeff;
            P3[k].exp=P1[i].exp;
            i++;j++;k++;
    }else if(P1[i].exp>P2[j].exp){
        P3[k]=P1[i];
        i++;j++;
    }else{
        P3[k]=P2[j];
        j++;k++;
    }}
    while(i<n1){
        P3[k]=P2[i];
        i++;k++;
    }
    while(j<n2){
        P3[k]=P2[j]
        j++;k++;
    }
    printf("Resultant polynomial P3:");
    for(int x=0;x<k;x++){
        printf("%dx^%d",P3[x].coeff,P3[x].exp);
        if(x!=k-1){
            printf("+";)
        }
    }printf("/n");






	
