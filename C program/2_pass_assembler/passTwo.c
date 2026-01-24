#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int si = 0, oi = 0;

struct optable {
    char opc[10];
    int hex;
} optab[20];

struct symtable {
    char sym[10];
    int hex;
} symtab[20];


int searchOpcode(char a[]) {
    for (int j = 0; j < oi; j++) {
        if (strcmp(optab[j].opc, a) == 0) {
            return optab[j].hex;
        }
    }
    return -1;
}


int searchLabel(char a[]) {
    for (int j = 0; j < si; j++) {
        if (strcmp(symtab[j].sym, a) == 0) {
            return symtab[j].hex;
        }
    }
    return -1; 
}


void findObj(char obj[], char opcode[], char operand[]) {
    strcpy(obj, "");
    if (strcmp(opcode, "RESB") == 0 || strcmp(opcode, "RESW") == 0 ||
        strcmp(opcode, "START") == 0 || strcmp(opcode, "END") == 0) {
        return; 
    }
    else if (strcmp(opcode, "BYTE") == 0) {
        int length = strlen(operand);
        if (operand[0] == 'C') { 
            for (int i = 2; i < length - 1; i++) {
                sprintf(obj + strlen(obj), "%02X", (unsigned char)operand[i]);
            }
        } else if (operand[0] == 'X') {
           
            for(int i=2; i<length; i++){
                sprintf(obj,"%c",operand[i]);
            }
        }
    }
    else if (strcmp(opcode, "WORD") == 0) {
        int x = atoi(operand);
        sprintf(obj, "%06X", x & 0xFFFFFF);
    }
    else {  
        int addr = searchLabel(operand);
        int code = searchOpcode(opcode);
        if (code == -1) {
            sprintf(obj, "??");
        } else if (addr == -1) {
            sprintf(obj, "%02X????", code);
        } else {
            sprintf(obj, "%02X%04X", code, addr);
        }
    }
}


void readSym(FILE *fptr) {
    si = 0;
    while (fscanf(fptr, "%s %x", symtab[si].sym, &symtab[si].hex) != EOF) {
        si++;
    }
}


void readOp(FILE *fptr) {
    oi = 0;
    while (fscanf(fptr, "%s %x", optab[oi].opc, &optab[oi].hex) != EOF) {
        oi++;
    }
}


int readLine(FILE *fptr, char locctr[], char label[], char opcode[], char operand[]) {
    char line[100];
    strcpy(label, "");
    strcpy(opcode, "");
    strcpy(operand, "");
    strcpy(locctr, "");

    if (fgets(line, sizeof(line), fptr) == NULL) {
        return 0; 
    }

    int n = sscanf(line, "%s %s %s %s", locctr, label, opcode, operand);
    if (n == 2) {
        strcpy(operand, label);  
        strcpy(opcode, locctr);  
        strcpy(locctr, "");       
        strcpy(label, "");
    } else if (n == 3) {
        strcpy(operand, opcode);
        strcpy(opcode, label);
        strcpy(label, "");
    }
    return 1; 
}



int main() {
    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5;
    char opcode[20], operand[20], label[20], locctr[10], obj[20];

    fptr1 = fopen("interf.txt", "r");   
    fptr2 = fopen("optab.txt", "r");    
    fptr3 = fopen("objcode.txt", "w");  
    fptr4 = fopen("symtab.txt", "r");   
    fptr5 = fopen("objprog.txt", "w");  

    if (!fptr1 || !fptr2 || !fptr3 || !fptr4 || !fptr5) {
        printf("Error opening files!\n");
        return 1;
    }

    readOp(fptr2);
    readSym(fptr4);

    int startAddr = 0, progLen = 0, endAddr = 0;
    char programName[10] = "";
    char firstExec[10] = "";

    
    char textRec[100] = "";
    int textStart = -1, textLen = 0;

   
    if (!readLine(fptr1, locctr, label, opcode, operand)) {
        printf("Empty input file!\n");
        return 1;
    }

    if (strcmp(opcode, "START") == 0) {
        startAddr = (int)strtol(operand, NULL, 16);
        strcpy(programName, label);
        strcpy(firstExec, operand);

        fprintf(fptr3, "%s\t%-10s %-10s %-10s\n", locctr, label, opcode, operand);

        if (!readLine(fptr1, locctr, label, opcode, operand)) return 0;
    }

   
    char textRecords[100][200];
    int textCount = 0;

   
    while (strcmp(opcode, "END") != 0) {
        findObj(obj, opcode, operand);
        fprintf(fptr3, "%s\t%-10s %-10s %-10s %-10s\n", locctr, label, opcode, operand, obj);

        if (strlen(obj) > 0) {
            if (textStart == -1) textStart = (int)strtol(locctr, NULL, 16);

            if ((textLen + strlen(obj) / 2) > 30) {
                sprintf(textRecords[textCount++], "T^%06X^%02X^%s", textStart, textLen, textRec);
                strcpy(textRec, "");
                textStart = (int)strtol(locctr, NULL, 16);
                textLen = 0;
            }

            if (strlen(textRec) > 0) strcat(textRec, "^");
            strcat(textRec, obj);
            textLen += strlen(obj) / 2;
        } 

        endAddr = (int)strtol(locctr, NULL, 16);
        if (!readLine(fptr1, locctr, label, opcode, operand)) break;
    }

    
    fprintf(fptr3, "%s\t%-10s %-10s %-10s\n", locctr, label, opcode, operand);

    
    if (textLen > 0) {
        sprintf(textRecords[textCount++], "T^%06X^%02X^%s", textStart, textLen, textRec);
    }

   
    progLen = endAddr - startAddr;

  
    fprintf(fptr5, "H^%-6s^%06X^%06X\n", programName, startAddr, progLen);
    for (int i = 0; i < textCount; i++) {
        fprintf(fptr5, "%s\n", textRecords[i]);
    }
    fprintf(fptr5, "E^%06X\n", (int)strtol(firstExec, NULL, 16));

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    fclose(fptr5);

    printf("Pass 2 completed.\nListing file: objcode.txt\nObject program: objprog.txt\n");
    return 0;
}
