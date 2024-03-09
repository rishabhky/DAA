#include<stdio.h>
#include<time.h>

int gcd(int a,int b){
    int i, gcd;

    for(i=1;i<=a&&i<=b;i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }

    return gcd;
}

void main(){
    clock_t start,end;
    int a,b;

    printf("Enter the two nos :");
    scanf("%d %d",&a,&b);

    start=clock();
    int result=gcd(a,b);
    end=clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("GCD of %d and %d is %d\n", a, b, result);
    printf("Time taken: %f seconds\n", time_spent);
}