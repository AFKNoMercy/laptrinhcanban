#include <stdio.h>
#include <stdlib.h>


void nhapMang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%5d ", a[i]);
    }
}
void doiCho(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sapXepChon(int a[], int n)
{
    int i, j, index_min;
    for (i = 0; i < n; i++)
    {
        index_min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[index_min])
            {
                index_min = j;
            }
        }
        if (i != index_min)
        {
            doiCho(a, i, index_min);
        }
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap %d so nguyen vao mang: ",n);
    nhapMang(a, n);
    printf("Mang ban dau: ");
    xuatMang(a,n);
    printf("\n");
    sapXepChon(a, n);
    printf("Mang da sap xep: ");
    xuatMang(a, n);
    return 0;
}
