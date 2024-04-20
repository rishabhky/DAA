#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

void intializeGraph(int graph[MAX][MAX],int numNodes){
    int i,j;
    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            graph[i][j]=0;
        }
    }

}

void transitiveClosure(int graph[MAX][MAX],int numNodes){
    int i,j,k;

    for(k=0;k<numNodes;k++){
        for(i=0;i<numNodes;i++){
            for(j=0;j<numNodes;j++){
                graph[i][j]=graph[i][j]||(graph[i][k] && graph[k][j]);
            }
        }
    }
}

void main(){
    int graph[MAX][MAX];
    int numNodes,i,j;

    printf("Enter the number of nodes in the graph :");
    scanf("%d",&numNodes);

    intializeGraph(graph,numNodes);

    printf("Enter the adjacency matrix of the graph :\n");
    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    clock_t start=clock();
    transitiveClosure(graph,numNodes);
    clock_t end=clock();

    double timeTaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Time taken to compute transitive closure: %f seconds\n",timeTaken);

    printf("Transitive closure of the graph :\n");

    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

}