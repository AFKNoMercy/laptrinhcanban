#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so nguyen: n = ");
    scanf("%d", &n);
    int giai_thua = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        giai_thua *= i;
    }
    printf("%d! = %d\n",n,giai_thua);
    return 0;
}
