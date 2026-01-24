#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int i,j,start;
    char line[100],startAddr[20],name[20];
    FILE *fp;
    fp=fopen("loader.txt","r");
    fscanf(fp,"%s",line);
    for(i=2,j=0; line[i]!='^'; i++,j++){
        name[j]=line[i];
    }
    name[j]='\0';
    printf("Name of the program is:%s\n",name);
        fscanf(fp,"%s",line);
        while(line[0]=='T'){
            for(i=2,j=0; line[i]!='^'; i++,j++){
                startAddr[j]=line[i];
            }
            startAddr[j]='\0';
            start = strtol(startAddr, NULL, 16);
            i=12;
            while(line[i]!='$'){
                if(line[i]!='^'){
                    printf("%06X\t%c%c\n",start,line[i],line[i+1]);
                    i=i+2;
                    start++;
                }
                else{
                    i++;
                }
            }
            fscanf(fp,"%s",line);
        }
        if(line[0]=='E'){
            fclose(fp);
            
        }

}