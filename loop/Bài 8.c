#include <stdio.h>

int main()
{
    int i=1;
    printf("Cac so duong chan tu 1 -> 20:   ");
    while(i<=20)
    {
        if(i%2==0)
        {
            printf("%d  ",i);
        }
        i++;
    }

    return 0;
}
