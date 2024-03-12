#include<stdio.h>

#define N 4
#define INF 99999

void copyArray(int n,int *src, int *dst){
    for (int i = 0; i <n ; i++)
    {
        dst[i]=src[i];
    }
}

int firstCity=0;
int min_path[N];
int min_length=INF;

int length(int n,int graph[N][N],int *path){
    int res=0;
    int i;

    for(i=0;i<n-1;i++){
        res+=graph[path[i]][path[i+1]];
    }

    res+=graph[path[n-1]][firstCity];
    
    return res;
}

void swap(int *a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void permute(int n,int graph[N][N],int *path,int i){
    if(i==n){
        int current_length = length(n,graph,path);
        if(current_length<min_length){
            min_length=current_length;
            copyArray(n,path,min_path);
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

int main(){
    int graph[N][N]= { { 0, 10, 15, 20 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 20, 25, 30, 0 } };

    int path[N];
    int i;

    for(i=0;i<N;i++){
        path[i]=i;
    }

    permute(N,graph,path,1);

    printf("Minimum cost : %d\n", min_length);
    printf("Path : ");
    for(int i=0; i<N; i++)
        printf("%d ", min_path[i]);
    printf("%d ", firstCity);
}