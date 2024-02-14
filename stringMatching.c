#include<stdio.h>
#include<time.h>
#include<string.h>

void stringMatching(char *text, char*sub){
    int textlen=strlen(text);
    int sublen=strlen(sub);

    int i,j;

    for (i = 0; i <= textlen-sublen; i++)
    {
        for (j = 0; j < sublen; j++)
        {
            if(text[i+j]!=sub[j]){
                break;
            }
        }
        if(j==sublen){
            printf("Substring found at index :%d",i);
        }
    }
    
}

void main(){

    char text[100];
    char sub[100];

    printf("Enter the first text :");
    scanf(" %[^\n]", text);

    printf("Enter the substring :");
    scanf("%s",&sub);

    clock_t  start,end;

    start=clock();
    stringMatching(text,sub);
    end=clock();

    double timeConsumed= ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken : %f",timeConsumed);

}