//this is written mainly in c... just file name in cpp
//This program evaluates a reverse polish notation by using stack array
//A reminder that this code ony works for digits i.e. 0-9

#include<iostream>
#define MX 1000
using namespace std;

int top = -1;
int stk[MX];

bool isEmpty(){
    return top == -1 ? 1 : 0;
}
void push(int value){
    stk[++top] = value;
}
int pop(){
    if(!isEmpty()){
        return stk[(top)--];
    }
    throw("Stack Underflow!");
}
void input(char RPN[]){
    scanf("%s", RPN);
}
int evaluation(char RPN[]){
    int temp;
    for(int i = 0; i < MX; i++){
       if(isdigit(RPN[i])) push(RPN[i]-'0');
       else if(RPN[i] == '+' || RPN[i] == '-' || RPN[i] == '*' || RPN[i] == '/'){
        temp = pop();
        if(RPN[i] == '+')temp+=pop();
        else if(RPN[i] == '-')temp=pop()-temp;
        else if(RPN[i] == '*')temp*=pop();
        else if(RPN[i] == '/')temp=pop()/temp;

        push(temp);
       }
       else break;
    }
    return temp;
}

int main(){
    cout << "Make sure to include a ')' at the end of expression\n";
    char RPN[MX];
    input(RPN);
    printf("%d", evaluation(RPN));
}