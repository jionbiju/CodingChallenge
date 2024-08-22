//Infix to postfix conversion using stack 
#include <stdio.h>
#include <ctype.h>
#define SIZE 25

char stack[SIZE];
char infix[SIZE];
int top=-1;
void push(char c){
    if(top==SIZE -1){
        printf("Stack is full");
    }
    else{
    top++;
    stack[top]=c;
    }
}
char pop(){
    if(top==-1){
    return -1;
    }
    else{
        return stack[top--];
    }
}
int priority(char c){
    if(c == '(')
    return 1;
    if(c=='+' || c=='-')
    return 2;
    if(c=='*'|| c=='/')
    return 3;
    if(c=='^')
    return 4;
}

void main(){
    char ch;
    printf("Enter a Infix Expression\n");
    scanf("%s",infix);
    int i=0;
    printf("Postfix Expression:");
    while (infix[i] != '\0'){
        if(isalnum(infix[i])){
            printf("%c",infix[i]);
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while((ch=pop())!= '('){
                printf("%c",ch);
            }
        }
        else{
            while(priority(stack[top])>=priority(infix[i])){
                printf("%c",pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while (top!=-1){
        printf("%c",pop());
    }
}
/*
OUTPUT
Enter a Infix Expression
A+B*C/D-F+A^E
Postfix Expression:ABC*D/+F-AE^+
*/