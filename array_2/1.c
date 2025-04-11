#include <stdio.h>
#define SIZE 3

void xuatMaTran(int a[][SIZE], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void nhapMaTran(int a[][SIZE], int r, int c)
{
    int i, j;
    printf("Nhap cac phan tu cho ma tran (%d x %d):\n", r, c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

int main()
{

    int mangKhaiBao[SIZE][SIZE] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Ma tran khai bao san:\n");
    xuatMaTran(mangKhaiBao, SIZE, SIZE);

    int mangNhap[SIZE][SIZE];
    nhapMaTran(mangNhap, SIZE, SIZE);

    printf("\nMa tran nhap vao:\n");
    xuatMaTran(mangNhap, SIZE, SIZE);

    return 0;
}
