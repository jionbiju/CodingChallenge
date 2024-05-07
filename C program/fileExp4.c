//Write a C program to replace vowels in a text file with character 'x'
#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp=NULL,*fp1=NULL;
    char ch;
    fp=fopen("fileExample.txt","r");
    if(fp==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    fp1=fopen("fileExample2.txt","w");
    if(fp1==NULL){
        printf("Error in opening the file.\n");
        exit(1);
    }
    while((ch=fgetc(fp))!=EOF){
        if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
           ch=='A'|| ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            fputc('x',fp1);
        }
        else{
            fputc(ch,fp1);
        }
       
    }
    fclose(fp);
    fclose(fp1);
    printf("Vowels replaced successfully.\n");
    return 0;
}
/*
Output
content in fileExample.txt
hello world
---------------------------
content in fileExample2.txt 
hxllx wxrld
*/