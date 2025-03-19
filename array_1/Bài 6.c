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

void doi_so_am(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i]<0)
        {
            a[i]=0;
        }
    }
}

int main()
{
    int n,key;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap %d so nguyen vao mang: ",n);
    nhapMang(a, n);
    printf("Mang ban dau: ");
    xuatMang(a,n);
    printf("\n");
    doi_so_am(a,n);
    printf("Mang sau khi thay the so am = 0: ");
    xuatMang(a,n);
    return 0;
}
