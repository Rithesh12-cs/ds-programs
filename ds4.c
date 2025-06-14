#include <stdio.h>
void readArray(int arr[],int n);
void displayArray(int arr[], int n);
void readArray(int arr[],int n){
    for (int i = 0; i < n;i++){
        printf("\nEnter the elements %d:",i+1);
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
void selectSort(int arr[], int n){
    int i, j, SI = 0, temp;
    for (i = 0; i < n; i++){
        SI = i;
        for (j = i + 1; j < n; j++){
            if(arr[SI] > arr[j]){
                SI = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[SI];
        arr[SI] = temp;
    }
}
int main(){
    int arr[100], n;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    readArray(arr, n);
    printf("\nBefore Sorting:");
    displayArray(arr, n);

    selectSort(arr, n);

    printf("\nAter Sorting:");
    displayArray(arr, n);
    return 0;
}