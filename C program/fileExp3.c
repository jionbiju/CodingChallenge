/*Implement a C program that copies the contents of one text file to another.
*/
#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE *fp1=NULL,*fp2=NULL;
    char c;
    fp1=fopen("fileExample.txt","r");
    if(fp1==NULL){
        printf("Error while  opening the file.\n");
        exit(1);
    }
    fp2=fopen("fileExample2.txt","w");
    if(fp2==NULL){
        printf("Error while  opening the file.\n");
        exit(1);
    }
    while((c=fgetc(fp1))!=EOF){
        fputc(c,fp2);
        
    }
    fclose(fp1);
    fclose(fp2);
     printf("Content successfully copied");
}
/*
Output
content in fileExample.txt
hello 

World
---------------------------
content in fileExample2.txt which is copied from fileExample.txt
hello 

World
*/