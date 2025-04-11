#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    printf("---Kiem tra loai tam giac va tinh chu vi, dien tich---\n");
    printf("Nhap 3 so thuc la canh tam giac a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double nua_chu_vi = (a + b + c)/2.0;
    double dien_tich = sqrt((nua_chu_vi)*(nua_chu_vi - a)*(nua_chu_vi - b)*(nua_chu_vi - c));
    if ((a + b > c) || (a + c > b) || (b + c > a))
    {
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
        {
            printf("(%.1f, %.1f, %.1f) la tam giac vuong\n",a,b,c);
        }
        else if ((a == b) && (b == c))
        {
            printf("(%.1f, %.1f, %.1f) la tam giac deu\n",a,b,c);
        }
        else if ((a == b) || (c == b) || (a == c))
        {
            printf("(%.1f, %.1f, %.1f) la tam giac can\n",a,b,c);
        }
        else
        {
            printf("(%.1f, %.1f, %.1f) la tam giac thuong\n",a,b,c);
        }
    }
    else
    {
        return 0;
    }
    printf("Chu vi = %.1f\n",a+b+c);
    printf("Dien tich = %.1f\n",dien_tich);
    return 0;
}
