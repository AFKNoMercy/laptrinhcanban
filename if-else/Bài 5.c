#include <stdio.h>

int main()
{
    int m, y;
    printf("---In ra so ngay cua thang trong nam---\n");
    printf("Nhap 2 so nguyen Thang x nam y: ");
    scanf("%d %d", &m, &y);

    int MaxDay;

    switch (m)
    {
    case 4:
    case 6:
    case 9:
    case 11:
    {
        MaxDay=30;
        break;
    }
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        MaxDay=31;
        break;
    }
    case 2:
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        {
            MaxDay = 29;
        }
        else
        {
            MaxDay = 28;
        }
        break;
    }
    }
    if (m>0&&m<=12&&y>0)
    {
        printf("Thang %d nam %d co %d ngay\n",m,y,MaxDay);
    }
    else
    {
        printf("Thang %d nam %d khong hop le\n",m,y);
    }

    return 0;
}
