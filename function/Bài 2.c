#include <stdio.h>

int giaithua(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n*giaithua(n-1);
}

int main()
{
    int n;
    printf("Nhap so nguyen: n = ");
    scanf("%d",&n);
    printf("%d! = %d",n,giaithua(n));

    return 0;
}
