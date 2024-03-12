#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define INF 99999

int matrix[4][4] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};


void main(){
    int minSum=INF,sum=0;
    int i,j,k,l;
    clock_t start,end;

    start=clock();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                        sum = matrix[i][0] + matrix[j][1] + matrix[k][2] + matrix[l][3];
                    

                        if(sum<minSum){
                            minSum=sum;
                        }
                    }
                }
            }
        }
    }
    end=clock();

    double timeTaken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Min sum : %d",minSum);

    printf("\nTime taken : %f",timeTaken);
}
