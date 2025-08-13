#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char label[20],opcode[20],operand[20],code[20],mnemonic[20];
    char line[100];
    int locctr,length,start;
    FILE *fp1,*fp2,*fp3,*fp4;
    
    fp1=fopen("input.txt","r");
    fp2=fopen("optab.txt","r");
    fp3=fopen("symtab.txt","w");
    fp4=fopen("interf.txt","w");
    

    fgets(line, sizeof(line), fp1);
    
    if(line[0] == ' ' || line[0] == '\t') {
        
        strcpy(label, "");
        sscanf(line, "%s%s", opcode, operand);
    } else {
        
        sscanf(line, "%s%s%s", label, opcode, operand);
    }
    
    if(strcmp(opcode,"START") == 0){
        start = (int)strtol(operand, NULL, 16);
        locctr=start;
        fprintf(fp4,"\t\t%-10s%-10s%-10s\n",label,opcode,operand);
        
        
        fgets(line, sizeof(line), fp1);
        if(line[0] == ' ' || line[0] == '\t') {
            strcpy(label, "");
            sscanf(line, "%s%s", opcode, operand);
        } else {
            sscanf(line, "%s%s%s", label, opcode, operand);
        }
    }
    else{
        locctr=0;
    }
    
    while(strcmp(opcode,"END") != 0){
        fprintf(fp4,"%04X\t",locctr);
        

        if(strlen(label) > 0){
            fprintf(fp3,"%-10s%04X\n",label,locctr);
        }
        
        rewind(fp2);
        
        while(fscanf(fp2,"%s%s",code,mnemonic) != EOF){
            if(strcmp(opcode,code) == 0){
                locctr+=3;
                break;
            }
        }
        
        if(strcmp(opcode,"WORD") == 0){
            locctr+=3;
        }
        else if(strcmp(opcode,"RESW") == 0){
            locctr+=3*(atoi(operand));
        }
        else if(strcmp(opcode,"RESB") == 0){
            locctr+=atoi(operand);
        }
        else if(strcmp(opcode,"BYTE") == 0){
            if (operand[0] == 'C') {
                locctr += strlen(operand) - 3;
            } else if (operand[0] == 'X') {
                locctr += (strlen(operand) - 3) / 2;
            }
        }
        
        fprintf(fp4,"%-10s%-10s%-10s\n",label,opcode,operand);
        

        fgets(line, sizeof(line), fp1);
        
        if(line[0] == ' ' || line[0] == '\t') {
            strcpy(label, "");
            sscanf(line, "%s%s", opcode, operand);
        } else {
            sscanf(line, "%s%s%s", label, opcode, operand);
        }
    }
    
    fprintf(fp4,"%04X\t%-10s%-10s%-10s\n",locctr,label,opcode,operand);
    length=locctr-start;
    printf("Program Length = %04X",length);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}
/*
OUTPUT
Program Length = 001A
input.txt
        START   2000
        LDA     FIVE
        STA     ALPHA
        LDCH    CHARZ
        STCH    C1
ALPHA   RESW    2
FIVE    WORD    5
CHARZ   BYTE    C'Zdfg'
C1      RESB    1
        END

optab.txr
LDA     03
STCH    57
STA     0F
LDCH    53

interf.txt
		          START     2000      
2000	          LDA       FIVE      
2003	          STA       ALPHA     
2006	          LDCH      CHARZ     
2009	          STCH      C1        
200C	ALPHA     RESW      2         
2012	FIVE      WORD      5         
2015	CHARZ     BYTE      C'Zdfg'   
2019	C1        RESB      1         
201A	          END       1         

*/
