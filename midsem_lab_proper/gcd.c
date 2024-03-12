#include<stdio.h>
#include<time.h>

int gcd(int a,int b){
    int i,gcd;

    for(i=0;i<=a && i<=b;i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    return gcd;
}

void main(){
    int a,b;
    clock_t start,end;

    printf("Enter the two numbers :");
    scanf("%d %d",&a,&b);

    start=clock();
    int res=gcd(a,b);
    end=clock();

    double timeTaken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Gcd : %d",res);
    printf("Time taken : %f",timeTaken);
}