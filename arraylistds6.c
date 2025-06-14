#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int size;
    int num[100];
}LIST;
void insertAtBegin(LIST *l, int ele);
void insertAtEnd(LIST *l, int ele);
void insertAtPos(LIST *l, int ele, int pos);
int deleteFromBegin(LIST *l);
int deleteFromEnd(LIST *l);
int deleteFromPos(LIST *l, int pos);
int search(LIST *l);
void displayList(LIST *l);
void insertAtBegin(LIST *l, int ele){
    for (int i = l->size; i > 0;i--){
        l->num[i] = l->num[i - 1];
    }
        l->num[0] = ele;
        l->size++;
    
}
void insertAtEnd(LIST *l, int ele){
    l->num[l->size++] = ele;
}
void insertAtPos(LIST *l, int ele, int pos){
    for (int i = l->size; i >= pos;i--){
        l->num[i] = l->num[i - 1];
    }
        l->num[pos] = ele;
        l->size++;
    
}
int deleteFromBegin(LIST *l){
    int ele = l->num[0];
    for (int i = 0; i < l->size;i++){
        l->num[i] = l->num[i + 1];
    }
    l->size--;
    return ele;
}
int deleteFromEnd(LIST *l){
     int ele=l->num[l->size] ;
     l->size--;
     return ele;
}
int deleteFromPos(LIST *l, int pos){
    int ele = l->num[pos];
    for (int i = pos; i < l->size;i++){
        l->num[i] = l->num[i + 1];
    }
    l->size--;
    return ele;
}
int search(LIST *l){
    int i, pos = 0;
    for (int i = 0; i < l->size;i++){
        if(pos==l->num[i]){
            pos = i;
            break;
        }
    }
    return -1;
}
void displayList(LIST*l){
    printf("\nList Elements are:");
    for(int i = 0; i < l->size;i++){
        printf("%d ", l->num[i]);
    }
    printf("\n");
}

int main(){
    int ele, ch,pos,res;
    LIST *l;
    l = (LIST *)malloc(sizeof(LIST));
    l->size = 0;
    while(1){
        printf("\nList Operations are:");
        printf("\n1.Insert At Begin");
        printf("\n2.Insert At End");
        printf("\n3.Insert At Position");
        printf("\n4.Delete From Begin");
        printf("\n5.Delete From End");
        printf("\n6.Delete From Position");
        printf("\n7.Search Element");
        printf("\n8.Display List");
        printf("\n9.Exit");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter Element:");
            scanf("%d", &ele);
            insertAtBegin(l, ele);
            break;
        case 2:
            printf("\nEnter Element:");
            scanf("%d", &ele);
            insertAtEnd(l, ele);
            break;
        case 3:
            printf("\nEnter Element and Position:");
            scanf("%d%d", &ele,&pos);
            insertAtPos(l, ele,pos);
            break;
        case 4:
            ele = deleteFromBegin(l);
            printf("\nDeleted Element %d", ele);
            break;
        case 5:
            ele = deleteFromEnd(l);
            printf("\nDeleted Element:%d", ele);   
            break;
        case 6:
            printf("\nEnter Postion:");
            scanf("%d", &pos);
            ele = deleteFromPos(l, pos);
            break;
        case 7:
            printf("\nEnter Element to be searched:");
            scanf("%d", &ele);
            res = search(l);
            if(res==-1){
                printf("\nElement not found");
            }else{
                printf("\nElement found at %d", res);
            }
            break;
        case 8:
            displayList(l);
            break;
        case 9:
            printf("Exit:");
            break;
        default:
            printf("\nInvalid Choice:");
            break;
        }
    }
}
