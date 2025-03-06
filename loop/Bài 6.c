#include <stdio.h>
int main()
{
    int a,b,r;
    printf("---Tim UCLN va BCNN cua a b---\n");
    printf("Nhap 2 so nguyen a b: ");
    scanf("%d %d",&a,&b);
    int A = a, B = b;
        while (B != 0) {
            r = B;
            B = A % B;
            A = r;
        }
        int gcd = A;
        int lcm = (a / gcd) * b;
        printf("%UCLN = %d\nBCNN = %d\n",gcd,lcm);
    return 0;
}
