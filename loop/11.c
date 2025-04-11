#include <stdio.h>

int main()
{
    int i, n;
    scanf("%d",&n);
    for (i = 32; i >= 0; i--)
    {
        printf("%d", (n >> i)%2);
    }
    printf("\n");
    printf("0%o\n",n);
    printf("0x%0x\n",n);
    return 0;
}
