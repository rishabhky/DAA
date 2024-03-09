#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define INF 999999

int matrix[4][4]={
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

void main(){
    int sum=0;
    int min_sum=INF;
    clock_t start,end;

    int i,j,k,l;

    start=clock();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){

                    if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                        sum=matrix[0][i]+matrix[1][j]+matrix[2][k]+matrix[3][l];

                        if(min_sum>sum){
                            min_sum = sum;
                        }
                    }
                }
            }
        }
    }
    end=clock();

    double timeConsumed= ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime consumed : %f",timeConsumed);

    printf("\nMin Sum : %d",min_sum);
}