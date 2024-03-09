#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j+1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    printf("Sorted Array : ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int i, n;
    clock_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; 

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    //printArray(arr, n);

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f", timeTaken);

    return 0;
}
