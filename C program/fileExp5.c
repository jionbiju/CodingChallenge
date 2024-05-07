/*Develop a C program to read numbers from a file and write odd numbers to one file and even numbers to another file.*/
#include <stdio.h>
#include <stdlib.h>
void main(){
    int num;
    FILE *fp=NULL,*fpodd=NULL,*fpeven=NULL;
    fp=fopen("fileExample.txt","r");
    if(fp==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    fpodd=fopen("fileExample2.txt","w");
    if(fpodd==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    fpeven=fopen("fileExample3.txt","w");
    if(fpeven==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    while(fscanf(fp,"%d",&num)!=EOF){
        if(num%2==0){
            fprintf(fpeven,"%d\t",num);
        }
        else{
            fprintf(fpodd,"%d\t",num);
        }
    }
    fclose(fpeven);
    fclose(fp);
    fclose(fpodd);
}

/*
Output
content in fileExample.txt
7 9 55 3 1 8 4 6 2 1 3 33 
---------------------
content in fileExample2.txt
7	9	55	3	1	1	3	33	
---------------------
content in fileExample3.txt
8	4	6	2	
*/