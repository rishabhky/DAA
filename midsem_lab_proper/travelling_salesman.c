#include<stdio.h>
#include<stdlib.h>

#define INF 999999
#define N 4

void copy_array(int n,int *src,int *dst){
    int i;
    for(i=0;i<n;i++){
        dst[i]=src[i];
    }
}

int firstCity=0;
int min_path[N];
int min_length=INF;

int length(int n, int graph[N][N],int *path){
    int res=0;
    int i;

    for(i=0;i<n;i++){
        res+=graph[path[i]][path[i+1]];
    }

    res+=graph[path[n-1]][firstCity];

    return res;
}

void swap(int *a,int *b){
    int* temp;
    temp=a;
    a=b;
    b=temp;
}

void permute(int n, int graph[N][N],int* path,int i){
    if(i==n){
        int current_length=length(n,graph,path);
        if(current_length<min_length){
            min_length=current_length;
            copy_array(n,path,min_path);
        }
    }
    else{
        int j;
        for(j=i;j<n;j++){
            swap((path+i),(path+j));
            permute(n,graph,path,i+1);
            swap((path+i),(path+j));
        }
    }
}


void main(){
    int graph[N][N]={ {0,10,15,20},
                      {10,0,35,25},
                      {15,35,0,30},
                      {20,25,30,0} };

    int path[N];
    int i;

    for(i=0;i<N;i++)
        path[i]=i;

    permute(N,graph,path,1);

    printf("Minimum cost: %d",min_length);
    printf("Path :");

    for(int j=0;j<N;j++)
        printf("%d ",min_path[j]);

    printf("%d ",firstCity);

}