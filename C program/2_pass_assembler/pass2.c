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

// Search opcode in OPTAB
int searchOpcode(char a[]) {
    for(int j = 0; j < oi; j++) {
        if(strcmp(optab[j].opc, a) == 0) {
            return optab[j].hex;
        }
    }
    return -1; // not found
}

// Search label in SYMTAB
int searchLabel(char a[]) {
    for(int j = 0; j < si; j++) {
        if(strcmp(symtab[j].sym, a) == 0) {
            return symtab[j].hex;
        }
    }
    return 0; // not found
}

// Generate object code
void findObj(char obj[], char opcode[], char operand[]) {
    strcpy(obj, "");
    if(strcmp(opcode,"RESB")==0 || strcmp(opcode,"RESW")==0) {
        return; // no object code
    }
    else if(strcmp(opcode,"BYTE")==0) {
        int length = strlen(operand);
        char buf[3];
        if(operand[0] == 'C' || operand[0] == 'c') {
            for(int i = 2; i < length-1; i++) {
                sprintf(buf, "%02X", (unsigned char)operand[i]);
                strcat(obj, buf);
            }
        } else if(operand[0] == 'X' || operand[0] == 'x') {
            for(int i = 2; i < length-1; i++) {
                sprintf(buf, "%c", operand[i]);
                strcat(obj, buf);
            }
        }
    }
    else if(strcmp(opcode,"WORD")==0) {
        int x = atoi(operand);
        sprintf(obj, "%06X", x);
    }
    else {  
        int addr = searchLabel(operand);
        int code = searchOpcode(opcode);
        if(code == -1) code = 0; // in case opcode not found
        sprintf(obj, "%02X%04X", code, addr);
    }
}

// Read symbol table
void readSym(FILE *fptr) {
    si = 0;
    while(fscanf(fptr, "%s %x", symtab[si].sym, &symtab[si].hex) != EOF) {
        si++;
    }
}

// Read opcode table
void readOp(FILE *fptr) {
    oi = 0;
    while(fscanf(fptr, "%s %x", optab[oi].opc, &optab[oi].hex) != EOF) {
        oi++;
    }
}

// Read a line and split into locctr, label, opcode, operand
int readLine(FILE *fptr, char locctr[], char label[], char opcode[], char operand[]) {
    char line[100];
    strcpy(label, "");
    strcpy(opcode, "");
    strcpy(operand, "");
    strcpy(locctr, "");

    if(fgets(line, sizeof(line), fptr) == NULL) {
        return 0; // end of file
    }

    int n = sscanf(line, "%s %s %s %s", locctr, label, opcode, operand);
    if(n == 2) {
        // strcpy(opcode, label);
        // strcpy(label, "");
            strcpy(operand, label);   // second field → operand
    strcpy(opcode, locctr);   // first field → opcode
    strcpy(locctr, "");       // no LOCCTR for this line
    strcpy(label, "");
    } else if(n == 3) {
        strcpy(operand, opcode);
        strcpy(opcode, label);
        strcpy(label, "");
    }
    return 1; // success
}

int main() {
    FILE *fptr1, *fptr2, *fptr3, *fptr4;
    char opcode[20], operand[20], label[20], locctr[10], obj[15];

    fptr1 = fopen("interf.txt", "r");
    fptr2 = fopen("optab.txt", "r");
    fptr3 = fopen("objcode.txt", "w");
    fptr4 = fopen("symtab.txt", "r");

    if(!fptr1 || !fptr2 || !fptr3 || !fptr4) {
        printf("Error opening files!\n");
        return 1;
    }

    readOp(fptr2);
    readSym(fptr4);

    // Read first line
    if(!readLine(fptr1, locctr, label, opcode, operand)) {
        printf("Empty input file!\n");
        return 1;
    }

    if(strcmp(opcode,"START")==0) {
        fprintf(fptr3,"%s\t%-10s %-10s %-10s\n", locctr, label, opcode, operand);
        // Read next line
        if(!readLine(fptr1, locctr, label, opcode, operand)) return 0;
    }

    while(strcmp(opcode,"END") != 0) {
        findObj(obj, opcode, operand);
        fprintf(fptr3,"%s\t%-10s %-10s %-10s %-10s\n", locctr, label, opcode, operand, obj);
        if(!readLine(fptr1, locctr, label, opcode, operand)) break;
    }

    fprintf(fptr3,"%s\t%-10s %-10s %-10s\n", locctr, label, opcode, operand);

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);

    printf("Pass 2 completed, object code written to objcode.txt\n");
    return 0;
}
