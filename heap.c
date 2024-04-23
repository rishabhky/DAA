#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create a heap from a list of integers using top-down heap construction
void buildHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int child = i;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (arr[child] > arr[parent]) {
                swap(&arr[child], &arr[parent]);
                child = parent;
            } else {
                break;
            }
        }
    }
}

int main() {
    int n, arr[MAX_SIZE];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random integers for the list
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }

    // Measure time taken to build the heap
    start = clock();
    buildHeap(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Heap built in %f seconds.\n", cpu_time_used);

    return 0;
}
