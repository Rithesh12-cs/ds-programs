#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
typedef struct Stack{
    int StackElements[max];
    int top;
} STACK;

void push(STACK*st,int ele);
int pop(STACK *st);
int top(STACK *st);
int calculator(int op1, char operator, int op2);
int isoperator(char token);

void push(STACK*st,int ele){
    ++st->top;
    st->StackElements[st->top] = ele;
    return;
}
int pop(STACK* st){
    int ele = st->StackElements[st->top];
    st->top--;
    return ele;
}


int top(STACK*st){
    return st->StackElements[st->top];
}
int calculator(int op1, char operator, int op2){
    int res;
    switch(operator){
        case '*':
            res = op1 * op2;
            break;
        case '/':
            res = op1 / op2;
            break;
        case '%':
            res = op1 % op2;
            break;
        case '+':
            res = op1 + op2;
            break;
        case '-':
            res = op1 - op2;
            break;
        default:
            res = 0;
    }
    return res;
}
int isoperator(char token){
    return (token=='*'||token=='/'||token=='%'|| token=='+'|| token=='-');
    
}

int main(){
    STACK *st;
    st = malloc(sizeof(STACK));
    st->top = -1;
    char  postfix[max], token;
    int op1,op2,res,index,dataOut;
    char tokenString[2] = {0};
    printf("\nEnter Postfix Expression:");
    scanf("%s", postfix);
    for (index = 0; postfix[index] != '\0';++index){
        token = postfix[index];
        if(!isoperator(token)){
            tokenString[0] = token;
            dataOut = atoi(tokenString);
            push(st, dataOut);
        }else{
            op2 = pop(st);
            op1 = pop(st);
            res = calculator(op1, token, op2);
            push(st, res);
        }
    }
        res = pop(st);
        printf("\nResult :%d", res);
        printf("\n");
    
    return 0;
}