#include <stdio.h>
void sortDescending(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) { 
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, k;
    printf("Enter number of events: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter activity points for each event:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter maximum number of events you can participate in: ");
    scanf("%d", &k);

    sortDescending(A, n);

    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += A[i];

    printf("Maximum number of points you can earn: %d\n", sum);
    return 0;
}
	
