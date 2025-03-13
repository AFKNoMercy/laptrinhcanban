#include <stdio.h>
int main()
{

    int n,a3;
    int a1=1,a2=1;
    printf("Nhap so nguyen n: ");
    scanf("%d",&n);
    if(n>2)
    {
        for(int i=3; i<=n; i++)
        {
            a3=a1;
            a1+=a2;
            a2=a3;
        }
        printf("Phan tu thu %d cua day Fibonaci = %d\n",n,a1);
    }
    else
    {
        printf("Phan tu thu %d cua day Fibonaci = 1\n",n);
    }
    return 0;
}
