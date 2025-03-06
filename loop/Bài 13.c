#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps, n, x, sin;
    int i = 1, j;
    long long k;

    printf("Nhap so thuc: x = ");
    scanf("%lf", &x);
    printf("Nhap so thuc : eps = ");
    scanf("%lf", &eps);

    double radian=x*M_PI/180;
    n=radian;
    sin=n;
    do
    {
        k=1;
        for(j=1; j<=2*i+1; j++)
        {
            k*=j;
        }
        n=pow((-1), i)*pow(radian,2*i+1)/k;
        sin+=n;
        i++;
    } while (fabs(n)>eps);
    printf("sin(%f) = %f", radian, sin);
    return 0;
}
