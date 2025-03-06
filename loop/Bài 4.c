#include <stdio.h>

int main()
{
    int i=0;
    int sum = 0;
    while(i<=100)
    {
        if(i%2==1)
        {
            sum+=i;
        }
        i++;
    }
    printf("Tong cac so le tu 1 -> 100: %d\n",sum);
    return 0;
}
