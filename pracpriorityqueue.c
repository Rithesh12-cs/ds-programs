#include <stdio.h>
#include <stdlib.h>
#define max 100
int heap[max];
int size = 0;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value){
    if(size >= max-1){
        printf("\nQueue is Full");
        return;
    }
    size++;
    heap[size] = value;
    int i = size; 
    while(i >1 && heap[i] > heap[i/2]){
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
    printf("\nInseserted :%d", value);
}
int getMax(){
    if(size==0){
        printf("\nPriority Queue is Empty");
        return -1;
    }
    return heap[1];
}
int deleteMax(){
    if(size==0){
        printf("\nPriority Queue is Empty");
        return -1;
    }
    int maxu = heap[1];
    heap[1] = heap[size];
    size--;
    int i = 1;
    while(2*i<=size){
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;
        if(left<=size && heap[left]  > heap[largest])
            largest = left;
        if(right<=size && heap[right]  > heap[largest])
            largest = right;
        if(largest!=i){
            swap(&heap[i],&heap[largest]);
            i = largest;
        }else{
            break;
        }
    }
    return maxu;
}

void display(){
   if(size==0){
        printf("\nPriority Queue is Empty");
        return ;
    }
    printf("\nPriority Queue :");
    for (int i = 1; i <= size;i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nPriority Queue Operation");
        printf("\n1. Insert");
        printf("\n2. Get Max");
        printf("\n3. Delete Max");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = getMax();
                if (value != -1)
                    printf("Maximum value: %d\n", value);
                break;
            case 3:
                value = deleteMax();
                if (value != -1)
                    printf("Deleted max value: %d\n", value);
                break;
            case 4:
                display(); 
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
