#include <stdio.h>

int main()
{
    int diem;
    printf("---Kiem tra va xep loai diem---\n");
    printf("Nhap diem la so nguyen tu 1 den 10: ");
    scanf("%d",&diem);

    switch(diem)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        printf("Yeu\n");
        break;
    case 5:
    case 6:
        printf("TB\n");
        break;
    case 7:
        printf("Kha\n");
        break;
    case 8:
    case 9:
        printf("Gioi\n");
        break;
    case 10:
        printf("Xuat sac\n");
        break;
    default:
        printf("Nhap sai so\n");
        break;
    }
    return 0;
}
