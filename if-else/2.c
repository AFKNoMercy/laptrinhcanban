#include <stdio.h>

int main() {
    double a, b, e;
    double c, d, f;
    printf("---Giai he phuong trinh bac nhat hai an---\n");
    printf("    ax + by = c\n    dx + ey = f\n");
    printf("Nhap 3 so thuc a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Nhap 3 so thuc d e f: ");
    scanf("%lf %lf %lf", &d, &e, &f);

    double D = a * e - b * d;
    double Dx = e * c - b * f;
    double Dy = a * f - d * c;

    if (D == 0) {
        if (Dx == 0 && Dy == 0) {
            printf("He phuong trinh co vo so nghiem\n");
        } else {
            printf("He phuong trinh vo nghiem\n");
        }
    } else {
        double x=Dx/D;
        double y=Dy/D;
        printf("He phuong trinh co nghiem duy nhat\n");
        printf("x = %.5f\n",x);
        printf("y = %.5f\n",y);
    }

    return 0;
}
