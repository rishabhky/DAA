#include<stdio.h>
#include<time.h>

int fibo(int n){
    if(n<=1){
        return n;
    }
    else{
    return fibo(n-1)+fibo(n-2);
    }
}

void main()
{
    clock_t start,end;
    int n,i;

    printf("Enter the number :");
    scanf("%d",&n);

    start=clock();
    printf("The Fibonacci series is :");
    for (i = 0; i <= n; i++) {
        printf("%d ", fibo(i));
    }
    end=clock();

    double timeTaken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nTime taken : %f",timeTaken);
    
}