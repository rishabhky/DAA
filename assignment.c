#include<stdio.h>

int arr[4][4]={
    {9,2,7,8},
    {6,4,3,7},
    {5,8,1,8},
    {7,6,9,4}
};

int main() {
    int sum = 0;
    int ppl[] = {0, 0, 0, 0};

    for (int m = 0; m < 4; m++) {
        int min = arr[0][m];
        int selectedRow = 0;

        for (int n = 1; n < 4; n++) {
            if (arr[n][m] < min && ppl[n] != 1) {
                min = arr[n][m];
                selectedRow = n;
            }
        }

        printf("Min: %d\n", min);
        sum += min;
        ppl[selectedRow] = 1;
    }

    printf("Sum = %d\n", sum);

    return 0;
}
