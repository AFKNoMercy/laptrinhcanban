void nhapMang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int dem_so_lan(int a[], int n, int key)
{
    int dem=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int n,key;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap %d so nguyen vao mang: ",n);
    nhapMang(a, n);
    printf("Nhap so can tim: ");
    scanf("%d",&key);
    int dem = dem_so_lan(a,n,key);
    printf("So \"%d\" xuat hien %d lan\n",key,dem);

    return 0;
}
