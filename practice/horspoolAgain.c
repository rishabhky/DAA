#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void preshiftTable(char pattern[],int shiftTable[]){
    int m=strlen(pattern);
    for(int i=0;i<256;i++)
        shiftTable[i]=m;
    
    for(int i=0;i<m-1;i++)
        shiftTable[pattern[i]]=m-i-1;
}

void horspool(char text[],char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);

    int shiftTable[256];

    preshiftTable(pattern,shiftTable);

    int i=m-1;
    int k;

    while(i<n){
        int k=0;

        if(k<m-1 && text[i-k]==pattern[m-1-k]){
            k++;
        }


        if(k==m){
            return i-m+1;
        }
        else{
            i+=shiftTable[text[i]];
        }
    }

    return -1;
}

int main(){
    char text[]="This is a sample text for testing Horspool's algorithm";
    char pattern[]="Horspool";

    int result = horspoolMatching(text,pattern);

    if(result!=-1){
        printf("Pattern found at index %d\n",result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}