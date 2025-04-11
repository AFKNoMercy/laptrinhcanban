#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    unsigned int n;
    double sum=0;
    printf("Nhap so nguyen: n = ");
    scanf("%u",&n);
    int i;
    for(i=1; i<=n; i++)
    {
        sum+=1.0/i;
    }
    printf("Tong 1/n la: %.10f\n",sum);
    return 0;
}
 
