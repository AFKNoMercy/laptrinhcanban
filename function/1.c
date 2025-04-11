#include <stdio.h>

double powRec(double b, int e) {
    if (e == 0) {
        return 1.0; // Lũy thừa 0
    }
    if (e < 0) {
        return 1.0 / powRec(b, -e);
    }
    return b * powRec(b, e - 1);
}

int main() {
    double x;
    int y;
    printf("Nhap x: ");
    scanf("%lf", &x);
    printf("Nhap y: ");
    scanf("%d", &y);

    printf("Ket qua %.2lf^%d = %.2lf\n", x, y, powRec(x, y));
    return 0;
}
