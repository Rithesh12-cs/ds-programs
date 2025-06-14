#include <stdio.h>
void readArray(int arr[], int n);
void displayArray(int arr[], int n);
void SortArray(int arr[], int n);
int binarySearch(int arr[], int n);
void readArray(int arr[], int n){
    for (int i = 0; i < n;i++){
        printf("\nEnter Elements:");
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("\nElement are: %d", arr[i]);
    }
    printf("\n");
}
void SortArray(int arr[], int n){
    int i, j, temp;
    for (int i = 0; i < n;i++){
        for (int j = n - 1; j < i - 1;j++){
            if(arr[j-1] > arr[j]){
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int n){
    int sElem, left = 0, right = n - 1, mid;
    printf("\nEnter element to be Searched:");
    scanf("%d", &sElem);
    while (left <=right){
    mid = (left + right) / 2;
    if(arr[mid]==sElem){
        return mid;
    }
    if (arr[mid] <sElem){
        left = mid + 1;
    }else{
        right = mid - 1;
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
    int res = binarySearch(arr, n);
   if(res == -1){
    printf("\nElement is not found");
   } else {
    printf("\nElement is found at index %d", res);
    }
    return 0;

}