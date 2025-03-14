#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int index;
} Num;

void readArray(Num *a, int len) {
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i].number);
        a[i].index = i;
    }
}

int findMax(Num *a, int len, int *maxIndex) {
    int max = a[0].number;
    *maxIndex = 0;
    for (int i = 1; i < len; i++) {
        if (a[i].number > max) {
            max = a[i].number;
            *maxIndex = i;
        }
    }
    return max;
}

int findMin(Num *a, int len, int *minIndex) {
    int min = a[0].number;
    *minIndex = 0;
    for (int i = 1; i < len; i++) {
        if (a[i].number < min) {
            min = a[i].number;
            *minIndex = i;
        }
    }
    return min;
}

int main() {
    Num *a;
    int n;
    int maxIndex, minIndex;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    a = (Num*)malloc(n * sizeof(Num));
    printf("Nhap %d phan tu cho mang: ", n);
    readArray(a, n);
    int max = findMax(a, n, &maxIndex);
    int min = findMin(a, n, &minIndex);
    printf("Gia tri lon nhat: %d, chi so: %d\n", max, maxIndex);
    printf("Gia tri nho nhat: %d, chi so: %d\n", min, minIndex);
    free(a);
    return 0;
}
