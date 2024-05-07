//Count number of line in a file
#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE *fp=NULL;
    char c;
    int count=1;
    fp=fopen("fileExample.txt","r");
    if(fp==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    while((c=fgetc(fp))!=EOF){
        if(c=='\n')
        count++;
    }
    printf("Number of line is %d",count);
    fclose(fp);
}
/*
File content
hello 

World
-------------------
Output
Number of line is 3
*/