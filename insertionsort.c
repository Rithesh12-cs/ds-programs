#include <stdio.h>
void readArray(int arr[],int n){
    for (int i = 0; i < n;i++){
        printf("\nEnter the elements %d:" ,i + 1);
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[],int n){
    printf("\nEnter elements:");
    for (int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertSort(int arr[],int n){
    int CI = 0, WI = 0, temp,loc=0;
    for (CI = 0; CI < n;CI++){
        loc = 0;
        temp = arr[CI];
        for (WI = CI - 1; WI >= 0 && !loc;--WI){
            if (temp < arr[WI]){
                arr[WI + 1] = arr[WI];
            }else{
                loc = 1;
            }
        }
        arr[WI + 1] = temp;
    }
    return;
}

int main(){
    int arr[100], n;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    readArray(arr, n);
    printf("\nBefore Sorting:");
    displayArray(arr, n);

    insertSort(arr, n);

    printf("\nAter Sorting:");
    displayArray(arr, n);
    return 0;
}