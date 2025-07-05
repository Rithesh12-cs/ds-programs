#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int num[10];
    int rear;
    int front;
} QUEUE;

void enqueue(QUEUE *q, int ele);
int dequeue(QUEUE *q);
int top(QUEUE *q);
void display(QUEUE *q);
int isEmpty(QUEUE *q);
int isFull(QUEUE *q);

void enqueue(QUEUE *q, int ele){
     if(q->front==q->rear==-1){
        q->num[++q->front]=ele;
        ++q->rear;
     }else{
         q->num[++q->rear] = ele;
     }
}
int dequeue(QUEUE *q){
    int ele = q->num[q->front];
    for (int i = 0; i < q->rear;i++){
        q->num[i] = q->num[i + 1];
    }
    return ele;
}
int top(QUEUE *q){
    return q->num[q->rear];
}
void display(QUEUE *q){
    for (int i = q->front; i < q->rear;i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}
int isEmpty(QUEUE *q){
    if(q->rear== q->front==-1){
        return -1;
    }else{
        return 0;
    }
}
int isFull(QUEUE *q){
    if(q->rear==9){
        return -1;
    }else{
        return 0;
    }
}
int main(){
    QUEUE *q = malloc(sizeof(QUEUE));
    q->front = -1;
    q->rear = -1;
    int ch, ele;
    printf("\nQueue Operations:");
    while (1){
        printf("\n1.Enqueue Element");
        printf("\n2.Dequeue Element");
        printf("\n3.Pop Element");
        printf("\n4.Display Queue");
        printf("\n5.Exit");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter element:");
            scanf("%d", &ele);
            enqueue(q, ele);
            break;
        case 2:
            ele = dequeue(q);
            printf("\nDequeued Element :%d", ele);
            break;
        case 3:
            ele = top(q);
            printf("\nTop Element:%d", ele);
            break;
        case 4:
            printf("\nQueue:");
            display(q);
            break;
        case 5:
            exit(0);
             break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}