#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low-1;
    int j=high+1;

    while(1){

        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j){
            return j;
        }

        swap(&arr[i],&arr[j]);
    }
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi);
        quickSort(arr,pi+1,high);
    }
}

void printArray(int arr[],int n){
    int i;

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");
}

void main(){
    int arr[]={12,11,9,5,7,3,2,1};

    int size=sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting :");
    printArray(arr,size);

    quickSort(arr,0,size-1);

    printf("After sorting :");
    printArray(arr,size);

}
