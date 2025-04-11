#include <stdio.h>
#include <stdlib.h>

void readArray(int arr[], int len)
{
    printf("Nhap %d phan tu cho mang: ",len);
    for(int i=0; i<len; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[], int len)
{
    printf("Cac phan tu cua mang: ");
    for(int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int len;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d",&len);

    int arr = (int *)malloc(len*sizeof(int));
    readArray(arr,len);
    printArray(arr,len);

    free(arr);
    return 0;
}
