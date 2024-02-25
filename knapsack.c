#include<stdio.h>
#include<stdlib.h>

struct Item{
    int value;
    int weight;
};

int max(int a,int b){
    return (a>b)?a:b;
}

int knapsack(struct Item items[],int n,int W){
    if(n==0||W==0)
        return 0;

    if(items[n-1].weight>W)
        return knapsack(items,n-1,W);
    
    else    
        return max(items[n - 1].value + knapsack(items, n - 1, W - items[n - 1].weight), knapsack(items, n - 1, W));
}

void main() {
    int W = 50; 
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(items) / sizeof(items[0]); 

    printf("Maximum value that can be obtained is %d\n", knapsack(items, n, W));
}