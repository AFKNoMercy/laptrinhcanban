#include <stdio.h>
#define ROWS 55
#define COLS 55

void nhapMaTran(int a[][COLS], int r, int c) {
    int i, j;
    printf("Nhap cac phan tu cho ma tran (%d x %d):\n", r, c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatMaTran(int a[][COLS], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void TongHaiMaTran(int a[][COLS], int b[][COLS], int ketQua[][COLS], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            ketQua[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int a[ROWS][COLS], b[ROWS][COLS], tong[ROWS][COLS], tich[ROWS][COLS];
    int r1, c1, r2, c2;

    printf("Nhap kich thuoc ma tran a (dong cot): ");
    scanf("%d%d", &r1, &c1);

    printf("Nhap kich thuoc ma tran b (dong cot): ");
    scanf("%d%d", &r2, &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Tong hai ma tran chi tinh duoc khi kich thuoc hai ma tran bang nhau!\n");
    } else {
        printf("\nNhap ma tran a:\n");
        nhapMaTran(a, r1, c1);

        printf("\nNhap ma tran b:\n");
        nhapMaTran(b, r2, c2);

        TongHaiMaTran(a, b, tong, r1, c1);
        printf("\nTong hai ma tran:\n");
        xuatMaTran(tong, r1, c1);
    } 

    return 0;
}
