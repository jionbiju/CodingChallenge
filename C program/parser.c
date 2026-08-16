#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[100];
int pos = 0;

/* Function declarations */
void E();
void Eprime();
void T();
void Tprime();
void F();

/* E -> T E' */
void E()
{
    T();
    Eprime();
}

/* E' -> + T E' | epsilon */
void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

/* T -> F T' */
void T()
{
    F();
    Tprime();
}

/* T' -> * F T' | epsilon */
void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

/* F -> (E) | id */
void F()
{
    if (isalpha(input[pos]))
    {
        pos++;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (input[pos] == ')')
        {
            pos++;
        }
        else
        {
            printf("Error: Missing ')'\n");
            exit(1);
        }
    }
    else
    {
        printf("Error: Invalid expression\n");
        exit(1);
    }
}

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    E();

    if (input[pos] == '\0')
        printf("Expression is successfully parsed.\n");
    else
        printf("Error: Invalid expression.\n");

    return 0;
}
/*
OUTPUT
Enter the expression: a+b*c
Expression is successfully parsed.
Enter the expression: a++b
Error: Invalid expression
PS G:\Jion Coding\C program> */