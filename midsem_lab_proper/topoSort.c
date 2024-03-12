#include<stdio.h>
#include<stdlib.h>

#define max 100

int stack[max];
int top=-1;

void push(int value){
    stack[++top]=value;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return top==-1;
}

void dfs(int node,int num_nodes,int graph[][max],int visited[]){
    visited[node]=1;
    
    for(int neighbour=0;neighbour<num_nodes;neighbour++){
        if(graph[node][neighbour]==1 && !visited[node]){
            dfs(neighbour,num_nodes,graph,visited);
        }
    }
    push(node);
}

void topoSort(int num_nodes,int graph[][max]){
    int visited[max]={0};

    for(int node=0;node<num_nodes;node++){
        if(!visited[node]){
            dfs(node,num_nodes,graph,visited);
        }
    }

    printf("Topological Sort :");
    while(!isEmpty()){
        printf("%d ",pop());
    }
    printf("\n");
}

void main(){
    int num_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    int graph[max][max];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topoSort(num_nodes, graph);
}