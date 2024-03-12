#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct AdjList* createList() {
    struct AdjList* list = (struct AdjList*) malloc(sizeof(struct AdjList));
    list->head = NULL;
    return list;
}

void addEdge(struct AdjList* list, int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = list->head;
    list->head = newNode;
}

int findEdge(struct AdjList* list, int dest) {
    struct AdjListNode* current = list->head;
    while (current != NULL) {
        if (current->dest == dest)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    int nodes, edges, i, src, dest;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct AdjList* list[nodes];

    for (i = 0; i < nodes; i++)
        list[i] = createList();

    printf("Enter the edges (u -> v): \n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(list[src], dest);
    }

    printf("Enter the node for which you want to find the edge: ");
    scanf("%d", &src);

    printf("Enter the node with which you want to check if there is an edge: ");
    scanf("%d", &dest);

    if (findEdge(list[src], dest))
        printf("There is an edge between node %d and node %d.\n", src, dest);
    else
        printf("There is no edge between node %d and node %d.\n", src, dest);

    return 0;
}