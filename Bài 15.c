#include <stdio.h>
 
int main() {
    int n;
    printf("Nhap so nguyen: n = ");
    scanf("%d", &n);
    double sum = 0;
    double giai_thua = 1.0;
    int i;
 
    for (i = 1; i <= n; i++) {
        giai_thua *= i;
        sum += 1.0 / giai_thua;
    }
    printf("Tong 1/n! la: %.10f\n", sum);
    return 0;
} 
