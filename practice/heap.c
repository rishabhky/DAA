#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 10000

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void buildHeap(int arr[], int n){
    for(int i=1;i<n;i++){
        int child=i;
        while(child>0){
            int parent=(child-1)/2;
            if(arr[child]>arr[parent]){
                swap(&arr[child],&arr[parent]);
                child=parent;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    int n,arr[max];
    clock_t start,end;
    double timetaken;

    printf("No of elements :");
    scanf("%d ",&n);

    srand(time(NULL));

    for(int i=0;i<n;i++){
        arr[i]=rand()%1000;
    }

    start=clock();
    buildHeap(arr,n);
    end=clock();

    timetaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Heap built in %f seconds\n",timetaken);

    return 0;
}