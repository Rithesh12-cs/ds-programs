#include <stdio.h>
void readArray(int arr[], int n);
void displayArray(int arr[], int n);
void bubbleSort(int arr[], int n);

void readArray(int arr[], int n){
    printf("\nEnter Elements:");
    for (int i = 0; i < n;i++){
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[], int n){
    printf("\nElements are:");
    for (int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n- i - 1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[100], n;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    readArray(arr, n);
    printf("\nBefore Sorting:");
    displayArray(arr, n);

    bubbleSort(arr, n);

    printf("\nAter Sorting:");
    displayArray(arr, n);
    return 0;
}