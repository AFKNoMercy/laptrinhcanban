#include <stdio.h>
#include <malloc.h>

int main()
{
    int *a = (char *)malloc(10*sizeof(int));
    for(int i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
