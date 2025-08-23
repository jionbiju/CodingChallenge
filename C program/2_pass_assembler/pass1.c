#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char label[20], opcode[20], operand[20], sym[20], code[20], mnemonic[20];
    char line[100], objcode[20];
    int locctr, start, length, addr;
    FILE *fp1, *fp2, *fp3, *fp4;

    fp1 = fopen("interf.txt", "r");   // intermediate file
    fp2 = fopen("symtab.txt", "r");   // symbol table
    fp3 = fopen("optab.txt", "r");    // operation code table
    fp4 = fopen("objcode.txt", "w");  // output object code

    if (!fp1 || !fp2 || !fp3 || !fp4) {
        printf("Error opening files.\n");
        return 1;
    }

    // read first line
    fgets(line, sizeof(line), fp1);
    if (line[0] == ' ' || line[0] == '\t')
        sscanf(line, "%s %s", opcode, operand);
    else
        sscanf(line, "%s %s %s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16);
        locctr = start;
        fprintf(fp4, "H^%s^%06X^", label, start);
        fgets(line, sizeof(line), fp1);
        if (line[0] == ' ' || line[0] == '\t')
            sscanf(line, "%s %s", opcode, operand);
        else
            sscanf(line, "%s %s %s", label, opcode, operand);
    } else {
        locctr = 0;
    }

    while (strcmp(opcode, "END") != 0) {
        // search optab
        int found = 0;
        rewind(fp3);
        while (fscanf(fp3, "%s %s", code, mnemonic) != EOF) {
            if (strcmp(opcode, code) == 0) {
                found = 1;
                // find address of operand in symtab
                rewind(fp2);
                while (fscanf(fp2, "%s %X", sym, &addr) != EOF) {
                    if (strcmp(sym, operand) == 0) {
                        sprintf(objcode, "%s%04X", mnemonic, addr);
                        fprintf(fp4, "%s^", objcode);
                        break;
                    }
                }
                locctr += 3;
                break;
            }
        }

        if (!found) {
            if (strcmp(opcode, "WORD") == 0) {
                sprintf(objcode, "%06X", atoi(operand));
                fprintf(fp4, "%s^", objcode);
                locctr += 3;
            } else if (strcmp(opcode, "BYTE") == 0) {
                int len = strlen(operand);
                if (operand[0] == 'C') {
                    for (int i = 2; i < len - 1; i++) {
                        sprintf(objcode, "%02X", operand[i]);
                        fprintf(fp4, "%s", objcode);
                    }
                } else if (operand[0] == 'X') {
                    for (int i = 2; i < len - 1; i++)
                        fprintf(fp4, "%c", operand[i]);
                }
                fprintf(fp4, "^");
                locctr += (operand[0] == 'C') ? len - 3 : (len - 3) / 2;
            } else if (strcmp(opcode, "RESW") == 0) {
                locctr += 3 * atoi(operand);
            } else if (strcmp(opcode, "RESB") == 0) {
                locctr += atoi(operand);
            }
        }

        // read next line
        if (!fgets(line, sizeof(line), fp1)) break;
        if (line[0] == ' ' || line[0] == '\t')
            sscanf(line, "%s %s", opcode, operand);
        else
            sscanf(line, "%s %s %s", label, opcode, operand);
    }

    fprintf(fp4, "\nE^%06X\n", start);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    printf("Pass 2 completed. Object code generated in objcode.txt\n");
    return 0;
}
