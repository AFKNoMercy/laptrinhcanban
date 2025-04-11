#include <stdio.h>
#include <stdlib.h>

void convert_to_base(int n, int base)
{
    if (base < 2 || base > 36)
    {
        printf("Khong ho tro co so %d\n", base);
        return;
    }

    char result[33];
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;

    while (n > 0)
    {
        result[index++] = digits[n % base];
        n /= base;
    }

    printf("n(%d) = ", base);
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main()
{
    int n, base;
    printf("Nhap so nguyen he 10: ");
    scanf("%d", &n);
    printf("Nhap he co so can doi: ");
    scanf("%d", &base);
    convert_to_base(n, base);
    return 0;
}
