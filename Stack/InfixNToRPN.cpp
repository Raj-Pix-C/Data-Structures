//this is written mainly in c... just file name in cpp
//This program converts an infix expression to reverse polish notation by using stack array
//A reminder that this code ony works for digits i.e. 0-9

#include<iostream>
#include<stdio.h>
#define MX 1000
using namespace std;

int top = -1, idx = 0;
bool isEmpty(){
    return top == -1 ? 1 : 0;
}
void push(char stk[], char value){
    stk[++(top)] = value;
}
int pop(char stk[]){
    return stk[(top)--];
}
int peek(char stk[]){
    return stk[top];
}
int precedence(char ch){
    if(ch == '^')return 3;
    else if(ch == '*' || ch == '/')return 2;
    else if(ch == '+' || ch == '-')return 1;
    else return 0;
}
void in_Rp(char infix[]){
    int i = 0;
    while (infix[i] != '\0')i++;
    infix[i] = ')';    
}
void conversion(char stk[], char infix[], char postfix[]){
    push(stk, '(');
    
    for(int i = 0; infix[i] != '\0'; i++){
        char ch = infix[i];
        if(isdigit(ch)){
            postfix[idx++] = infix[i];
        }
        else if(ch == '('){
            push(stk, ch);
        }
        else if(ch == '^'||ch == '*'|| ch == '/'|| ch == '+'|| ch == '-'){
            while(!isEmpty() && precedence(ch) <= precedence(peek(stk))){
                postfix[idx++] = pop(stk);
            }
            push(stk, ch);
        }
        else if(ch == ')'){
            while(peek(stk) != '('){
                postfix[idx++] = pop(stk);
            }
            pop(stk);
        }
    }
}
void input(char infix[]){
    puts("Enter the infix expression");
    fscanf(stdin, "%s", infix);
}
void output(char result[]){
    fprintf(stdout, "%s", result);
}


int main(){
    char stk[MX], infix[MX], postfix[MX];
    input(infix);
    in_Rp(infix);
    conversion(stk, infix, postfix);
    output(postfix);
}