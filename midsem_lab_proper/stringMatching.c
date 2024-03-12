#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void StringMatching(char* string, char *sub){
    int n=strlen(string);
    int m=strlen(sub);

    int i,j;

    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(string[i+j]!=sub[j]){
                break;
            }
        }
        if(j==m){
            printf("The substring is present at index : %d",i);
        }
    }
}

void main(){
    char text[100],sub[100];
    clock_t start,end;

    printf("Enter the string :");
    scanf("%[^\n]",text);

    printf("Enter the substring to be searched :");
    scanf("%s",&sub);

    start=clock();
    StringMatching(text,sub);
    end=clock();

    double timeConsumed=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nTime Consumed : %f",timeConsumed);

}