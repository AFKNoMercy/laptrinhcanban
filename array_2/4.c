#include <stdio.h>
#define ROWS 55
#define COLS 55
void xuatMaTran(int a[][COLS], int r, int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
void MaTranXoanOc(int a[][COLS], int r, int c)
{
    int i, j;
    int lap = 0;
    int gt = 1;

    while (gt <= r * c)
    {
        for (j = lap; j < c - lap; j++)
        {
            if (gt <= r * c)
            {
                a[lap][j] = gt++;
            }
        }
        for (i = lap + 1; i < r - lap; i++)
        {
            if (gt <= r * c)
            {
                a[i][c - 1 - lap] = gt++;
            }
        }
        for (j = c - 2 - lap; j >= lap; j--)
        {
            if (gt <= r * c)
            {
                a[r - 1 - lap][j] = gt++;
            }
        }
        for (i = r - 2 - lap; i > lap; i--)
        {
            if (gt <= r * c)
            {
                a[i][lap] = gt++;
            }
        }
        lap++;
    }
}

int main()
{
    int a[ROWS][COLS];
    int n;
    printf("Nhap kich thuoc cho ma tran vuong: n = ");
    scanf("%d",&n);
    MaTranXoanOc(a,n,n);
    xuatMaTran(a,n,n);
    return 0;
}
