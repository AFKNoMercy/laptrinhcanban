#include <stdio.h>

int fibonaci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    return fibonaci(n-1) + fibonaci(n-2);
}

int main()
{
    int n;
    printf("Nhap so nguyen: n = ");
    scanf("%d",&n);
    printf("Phan tu thu %d cua day fibonaci la %d\n",n,fibonaci(n));

    return 0;
}
