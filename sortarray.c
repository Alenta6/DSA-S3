#include <stdio.h>

int binarySearch(int a[], int n, int key, int *comparisons) {
    int l = 0, r = n - 1;
    *comparisons = 0;  

    while (l <= r) {
        int m = (l + r) / 2;
        (*comparisons)++;  
        if (a[m] == key) return m;
        else if (a[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n, key, comps;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = binarySearch(a, n, key, &comps);

    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    printf("Number of comparisons (Time Complexity steps): %d\n", comps);

    
    int space = sizeof(a) + sizeof(n) + sizeof(key) + sizeof(comps);
    printf("Estimated Space Used (bytes): %d\n", space);
}