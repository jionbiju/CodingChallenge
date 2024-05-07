/*Write a C program to read a text file character 
by character and display its content on the screen.
*/

#include <stdio.h>
#include <stdlib.h>
void main(){
    char ch;
    FILE *fp=NULL;
    fp=fopen("fileExample.txt","r");
    if(fp==NULL){
        printf("Eror\n");
        exit(1);
    }
    while(!feof(fp)){
        ch=fgetc(fp);
        printf("%c",ch);
    }
    fclose(fp);
}

//Output
//hello World 