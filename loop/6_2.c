#include <stdio.h>

int main()
{
    int n;
    int i;
    int sum = 0;
    printf("Nhap so nguyen: n = ");
    scanf("%d",&n);
    printf("Cac uoc so cua %d la: ",n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            printf("%d ",i);
        }
    }
    printf("\n");
    if(sum==n*2)
    {
        printf("%d: la so hoan hao\n",n);
    }
    else
    {
        printf("%d: khong la so hoan hao\n",n);
    }
    return 0;
}
