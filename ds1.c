#include <stdio.h>
void readArray(int arr[],int n);
void displayArray(int arr[], int n);
int linearSearch(int arr[], int n);

void readArray(int arr[],int n){
    for (int i = 0; i < n;i++){
        printf("Enter Elements:");
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int linearSearch(int arr[],int n){
    int sElem;
    printf("\nEnter Element to be searched:");
    scanf("%d", &sElem);
    for (int i = 0; i < n;i++){
        if(sElem==arr[i]){
            return i;
        }
    }
        return -1;
    
}
int main(){
    int n,sElem,arr[100],i;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    readArray(arr, n);
    displayArray(arr, n);
    int res = linearSearch(arr, n);
   if(res == -1){
    printf("\nElement is not found");
   } else {
    printf("\nElement is found at index %d", res);
    }
    return 0;
}