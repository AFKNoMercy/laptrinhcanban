void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void tronMang(int a[], int n1, int b[], int n2, int c[])
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }

    }
    while(i<n1)
    {
        c[k++]=a[i++];
    }
    while(j<n2)
    {
        c[k++]=b[j++];
    }
}

int main()
{
    int n1,n2;
    printf("Nhap so luong phan tu mang 1: ");
    scanf("%d",&n1);
    int a[n1];
    printf("Nhap %d so nguyen cho mang 1: ",n1);
    nhapMang(a,n1);
    printf("Nhap so luong phan tu mang 2: ");
    scanf("%d",&n2);
    int b[n2];
    printf("Nhap %d so nguyen cho mang 2: ",n2);
    nhapMang(b,n2);
    int c[n1+n2];
    tronMang(a,n1,b,n2,c);
    printf("Mang moi tao boi mang 1 va mang 2: ");
    xuatMang(c,n1+n2);
    return 0;
}
