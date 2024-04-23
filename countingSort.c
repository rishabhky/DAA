#include <stdio.h>

void counting_sort(int A[], int n)
{
    int i, j;
    int S[15], C[100];
    for (i = 0; i < n; i++)
        C[i] = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] < A[j])
                C[j]++;
            else
                C[i]++;
        }
    }
    for (i = 0; i < n; i++)
        S[C[i]] = A[i];
    printf("The Sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", S[i]);
}

int main()
{
    int n, k = 0, A[15], i;
    printf("Enter the number of integers : ");
    scanf("%d", &n);
    printf("\nEnter the integers to be sorted :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    counting_sort(A, n);
    printf("\n");
    return 0;
}
