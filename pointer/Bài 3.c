#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void readArray(int arr[], int len) {
    printf("Nhap %d phan tu cho mang: ", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}

void selectionSort(int arr[], int len) {
    int i, j, index_min;
    for (i = 0; i < len; i++) {
        index_min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[index_min] > arr[j]) {
                index_min = j;
            }
        }
        if (i != index_min) {
            swap(arr, i, index_min);
        }
    }
}

int main() {
    int len;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &len);

    int *arr = (int *)malloc(len * sizeof(int));

    readArray(arr, len);
    selectionSort(arr, len);

    printf("Max = %d\nMin = %d\n", arr[len - 1], arr[0]);

    free(arr);
    return 0;
}
