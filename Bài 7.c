#include <stdio.h>
#include <math.h>

int main()
{

    int T, t, n, kq, i;
    printf("---Kiem tra so nguyen to---\n");
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);
    if(n < 2)
    {
        kq = 0;
    }
    else
    {
        kq = 1;
        for(i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                kq = 0;
                break;
            }
        }
    }

    if(kq == 0)
    {
        printf("%5d : khong phai so nguyen to\n", n);
    }
    else
    {
        printf("%5d : la so nguyen to\n", n);
    }
    return 0;
}
