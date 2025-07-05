#include <stdio.h>

void quicksort(int n[], int first, int last);
void display(int n[], int size);

int main() {
    int i, size, n[10];

    printf("Enter the size of array:\n");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &n[i]);
    }

    printf("Before sorting:\n");
    display(n, size);

    quicksort(n, 0, size - 1);

    printf("After sorting:\n");
    display(n, size);

    return 0;
}

void quicksort(int n[], int first, int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (n[i] <= n[pivot] && i < last)
                i++;
            while (n[j] > n[pivot])
                j--;

            if (i < j) {
                temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }

        temp = n[pivot];
        n[pivot] = n[j];
        n[j] = temp;

        quicksort(n, first, j - 1);
        quicksort(n, j + 1, last);
    }
}

void display(int n[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}
