#include <stdio.h>

int main()
{
    int t,x;
    int sum = 0;
    for(t=1;t<=10;t++)
    {
        printf("Nhap mot so nguyen: ");
        scanf("%d",&x);
        sum+=x;
    }
    printf("Tong tat ca so nguyen da nhap: %d\n",sum);
    return 0;
}
