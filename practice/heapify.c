#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 10000

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }

    if(r<n &&arr[r]>arr[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(&arr[i],&arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){

        swap(&arr[0],&arr[i]);

        heapify(arr,i,0);
    }
}

int main(){
    int n,arr[max];
    clock_t start,end;
    double timeTaken;

    printf("Enter the number of elements");
    scanf("%d",&n);

    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000;
    }

    start=clock();
    heapSort(arr,n);
    end=clock();

    timeTaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Sorted array in %f seconds.\n", timeTaken);

     printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}