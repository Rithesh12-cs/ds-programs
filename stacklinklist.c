#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}NODE;

typedef struct stack{
    NODE *top;
    int count;
}STACK;

void push(STACK *st, int ele);
int pop(STACK *st);
int top(STACK *st);
void display(STACK *st);
int isFull(STACK *st);
int isEmpty(STACK *st);

int isFull(STACK *st){
    if(st->top== -1){
        return -1;
    }else{
        return 0;
    }
}

int isEmpty(STACK *st){
    if(st->top==NULL){
        return -1;
    }else{
        return 0;
    }
}

void push(STACK *st, int ele){
    NODE *nn = malloc(sizeof(NODE));
    nn->data = ele;
    nn->next = NULL;
    if (!st->top){
        st->top = nn;
    }else{
        nn->next = st->top;
        st->top = nn;
    }
    ++st->count;
}

int pop(STACK*st){
    int ele;
    ele = st->top->data;
    if(!st->top->next)
        st->top = NULL;
    else
        st->top = st->top->next;
    --st->count;
    return ele;
}
int top(STACK*st){
    return st->top->data;
}
void display(STACK*st){
    NODE *curr = st->top;
    while (curr){
        printf("%d ", curr->data);
        curr = curr->next;
    }  
}
int main(){
    STACK *st = malloc(sizeof(STACK));
    st->top = NULL;
    st->count = 0;
    int ch, num[10], ele;
    printf("\nStack Operations:");
    while (1){
        printf("\n1.Push Element");
        printf("\n2.Pop Element");
        printf("\n3.Top Element");
        printf("\n4.Display Stack");
        printf("\n5.Exit");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter Element:");
            scanf("%d", &ele);
            push(st, ele);
            break;
        case 2:
            ele=pop(st);
            printf("\nPop Element: %d", ele);
            break;
        case 3:
            ele = top(st);
            printf("\nTop element: %d", ele);
            break;
        case 4:
            printf("\nStack Elements:");
            display(st);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice:");
            break;
        }
    }
    return 0;
}

