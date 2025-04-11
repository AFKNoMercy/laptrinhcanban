#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    positive,
    negative,
    all,
} Sign;

int sum(int *a, int len, Sign sign)
{
    int total=0;
    switch(sign)
    {
    case positive:
        for (int i=0; i<len; i++)
        {
            if (a[i]>0)
            {
                total+=a[i];
            }
        }
        break;
    case negative:
        for (int i=0; i<len; i++)
        {
            if (a[i]<0)
            {
                total+=a[i];
            }
        }
        break;
    default:
        for (int i=0; i<len; i++)
        {
            total+=a[i];
        }
        break;
    }
    return total;
}

double Avg(int *a, int len, Sign sign)
{
    double Avg=0;
    int n=0;
    switch (sign)
    {
    case positive:
        for (int i=0; i<len; i++)
        {
            if (a[i]>0)
            {
                n++;
            }
        }
        break;
    case negative:
        for (int i=0; i<len; i++)
        {
            if (a[i]<0)
            {
                n++;
            }
        }
        break;
    default:
        n=len;
    }
    Avg=(double)sum(a, len, sign)/(double)n;
    return Avg;
}

void readArray(int* a, int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &a[i]);
    }
}

int main()
{
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    int *a =(int*)malloc(n*sizeof(int));
    printf("Nhap %d phan tu cho mang: ",n);
    readArray(a,n);
    printf("Tong cac so cua mang = %d\n", sum(a,n,all));
    printf("Tong cac so nguyen duong = %d\n", sum(a,n,positive));
    printf("Tong cac so nguyen am = %d\n", sum(a,n,negative));
    printf("Trung binh cong cua mang = %.1f\n", Avg(a,n,all));
    printf("Trung binh cong cua so nguyen duong = %.1f\n", Avg(a,n,positive));
    printf("Trung binh cong cua so nguyen am = %.1f\n", Avg(a,n,negative));
    free(a);
    return 0;
}
