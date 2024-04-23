#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 100

void initializeGraph(int graph[max][max],int num){
    int i,j;

    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            graph[i][j]=0;
        }
    }
}

void transitiveClosure(int graph[max][max],int num){
    int i,j,k;

    for(k=0;k<num;k++){
        for(i=0;i<num;i++){
            for(j=0;j<num;j++){
                graph[i][j]=graph[i][j]||(graph[i][k]&&graph[k][j]);
            }
        }
    }
}

void main(){
    int graph[max][max];
    int num,i,j;

    printf("Enter the number of nodes in the graph :");
    scanf("%d ",&num);

    initializeGraph(graph,num);

    printf("Enter the adjacency matrix of the graph :");
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    clock_t start=clock();
    transitiveClosure(graph,num);
    clock_t end=clock();

    double timeTaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Time taken to compute transitive closure: %f seconds\n",timeTaken);

    printf("Transitive closure of the graph :\n");

    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

}