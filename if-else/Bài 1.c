#include <stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    printf("---Giai phuong trinh bac hai---\n");
    printf("ax^2 + bx + c = 0\n");
    printf("Nhap 3 so thuc a b c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    double delta=(b*b)-(a*c+a*c+a*c+a*c);
    if (a!=0)
    {
        if (delta>0)
        {
            printf("Phuong trinh co 2 nghiem phan biet\n");
            printf("x1 = %.5f\n",(-b-(sqrt(delta)))/(a+a));
            printf("x2 = %.5f\n",(-b+(sqrt(delta)))/(a+a));
        }
        else if (delta==0)
        {
            printf("Phuong trinh co nghiem kep\n");
            printf("x1 = x2 = %.5f\n",-b/(a+a));
        }
        else if (delta<0)
        {
            printf("Phuong trinh vo nghiem\n");
        }
    }
    else
    {
        if (b==0&&c==0)
        {
            printf("x la nghiem duy nhat\n");
        }
        else if (b==0&&c!=0)
        {
            printf("Phuong trinh vo nghiem\n");
        }
        else if (b!=0)
        {
            printf("Phuong trinh co 1 nghiem don\n");
            printf("x = %.5f\n",-c/b);
        }
    }
    return 0;
}
