#include <stdio.h>
#define ROWS 55
#define COLS 55

void nhapMaTran(int a[][COLS], int r, int c)
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

void xuatMaTran(int a[][COLS], int r, int c)
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

void TongHaiMaTran(int a[][COLS], int b[][COLS], int ketQua[][COLS], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            ketQua[i][j] = a[i][j] + b[i][j];
        }
    }
}

void TichHaiMaTran(int a[][COLS], int b[][COLS], int ketQua[][COLS], int r1, int c1, int c2)
{
    int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            ketQua[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                ketQua[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a[ROWS][COLS], b[ROWS][COLS], tong[ROWS][COLS], tich[ROWS][COLS];
    int r1, c1, r2, c2;

    int choice;
    printf("1. Nhan 2 ma tran\n2. Cong 2 ma tran\nNhap lua chon: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("Nhap kich thuoc ma tran a (dong cot): ");
        scanf("%d%d", &r1, &c1);

        printf("Nhap kich thuoc ma tran b (dong cot): ");
        scanf("%d%d", &r2, &c2);

        if (c1 != r2)
        {
            printf("\nTich hai ma tran chi tinh duoc khi so cot cua ma tran a bang so dong cua ma tran b!\n");
        }
        else
        {
            printf("\nNhap ma tran a:\n");
            nhapMaTran(a, r1, c1);

            printf("\nNhap ma tran b:\n");
            nhapMaTran(b, r2, c2);

            TichHaiMaTran(a, b, tich, r1, c1, c2);
            printf("\nTich hai ma tran:\n");
            xuatMaTran(tich, r1, c2);
        }
        break;
    case 2:
        printf("Nhap kich thuoc ma tran a (dong cot): ");
        scanf("%d%d", &r1, &c1);

        printf("Nhap kich thuoc ma tran b (dong cot): ");
        scanf("%d%d", &r2, &c2);

        if (r1 != r2 || c1 != c2)
        {
            printf("Tong hai ma tran chi tinh duoc khi kich thuoc hai ma tran bang nhau!\n");
        }
        else
        {
            printf("\nNhap ma tran a:\n");
            nhapMaTran(a, r1, c1);

            printf("\nNhap ma tran b:\n");
            nhapMaTran(b, r2, c2);

            TongHaiMaTran(a, b, tong, r1, c1);
            printf("\nTong hai ma tran:\n");
            xuatMaTran(tong, r1, c1);
        }
        break;
    default:
        printf("Khong ton tai lua chon\n");
        return 0;
        break;
    }

    return 0;
}
