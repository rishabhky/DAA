#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int stack[MAX_NODES];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void dfs(int node, int num_nodes, int graph[][MAX_NODES], int visited[]) {
    visited[node] = 1;
    for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, num_nodes, graph, visited);
        }
    }
    push(node);
}

void topologicalSort(int num_nodes, int graph[][MAX_NODES]) {
    int visited[MAX_NODES] = {0};
    for (int node = 0; node < num_nodes; node++) {
        if (!visited[node]) {
            dfs(node, num_nodes, graph, visited);
        }
    }
    printf("Topological sorting order: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(num_nodes, graph);

    return 0;
}