#include<stdio.h>

#define INF 999999
#define N 4

void copy_array(int n, int *src, int *dest) {
    for(int i=0; i<n; i++)
        dest[i] = src[i];
}

int first_city = 0;
int min_path[N];
int min_length = INF;

int length(int n, int graph[N][N], int *path) {
    int res = 0;
    for(int i=0; i<n-1; i++)
        res += graph[path[i]][path[i+1]];
    res += graph[path[n-1]][first_city];
    return res;
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int n, int graph[N][N], int *a, int i) {
    if(i == n) {
        int current_length = length(n, graph, a);
        if(current_length < min_length) {
            min_length = current_length;
            copy_array(n, a, min_path);
        }
    }
    else {
        for(int j=i; j<n; j++) {
            swap((a+i), (a+j));
            permute(n, graph, a, i+1);
            swap((a+i), (a+j)); // backtrack
        }
    }
}

int main() {
    int graph[N][N] = { { 0, 10, 15, 20 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 20, 25, 30, 0 } };
    int path[N];
    for(int i=0; i<N; i++)
        path[i] = i;

    permute(N, graph, path, 1);

    printf("Minimum cost : %d\n", min_length);
    printf("Path : ");
    for(int i=0; i<N; i++)
        printf("%d ", min_path[i]);
    printf("%d ", first_city);
    return 0;
}