#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct CircularQueue{
    int Queue[size];
    int front, rear;
} QUEUE;

void enqueue(QUEUE *q,int ele);
int dequeue(QUEUE *q);
int top(QUEUE *q);
void display(QUEUE *q);
int isEmpty(QUEUE *q);
int isFull(QUEUE *q);

int isEmpty(QUEUE *q){
    return (q->front == -1);
}

int isFull(QUEUE *q){
    return (q->front == ((q->rear + 1) % size));
}

void enqueue(QUEUE *q,int ele){
    if(isFull(q)){
        printf("\nQueue is Flow");
        return;
    }
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        q->front = q->rear = 0;
    }else{
        q->rear = (q->rear + 1) % size;
    }
    q->Queue[q->rear]=ele;
}

int dequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return -1;
    }
        int ele = q->Queue[q->front];
        if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % size;
    }
    return ele;
}
int top(QUEUE *q){
    return q->Queue[q->front];
}
void display(QUEUE *q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return;
    }
    int i = q->front;
     while (1) {
    printf("%d ", q->Queue[i]);
    if (i == q->rear) 
      break;
    i = (i + 1) % size;
}

}
int main() {
    QUEUE *q = malloc(sizeof(QUEUE));
    q->front = q->rear = -1;

    int ch, ele;

    while (1) {
        printf("\n1.Enqueue Element");
        printf("\n2.Dequeue Element");
        printf("\n3.Top Element");
        printf("\n4.Display Elements");
        printf("\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &ele);
                enqueue(q, ele);
                break;
            case 2:
                ele = dequeue(q);
                if (ele != -1)
                    printf("Dequeued Element: %d\n", ele);
                break;
            case 3:
                ele = top(q);
                if (ele != -1)
                    printf("Top Element: %d\n", ele);
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q);
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }

    return 0;
}