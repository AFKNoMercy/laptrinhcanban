#include <stdio.h>

typedef struct {
    double hs[10];
    int bac;
} DaThuc;

void nhapDT(DaThuc *dt) {
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &dt->bac);

    printf("Nhap he so tu bac %d den 0:\n", dt->bac);
    for (int i = dt->bac; i >= 0; i--) {
        printf("He so x^%d: ", i);
        scanf("%lf", &dt->hs[i]);
    }
}

void inDT(DaThuc dt) {
    for (int i = dt.bac; i >= 0; i--) {
        if (i == dt.bac) {
            printf("%.2lf*x^%d", dt.hs[i], i);
        } else {
            printf(" + %.2lf*x^%d", dt.hs[i], i);
        }
    }
    printf("\n");
}

double tinhGiaTri(DaThuc dt, double x) {
    double gt = 0;
    for (int i = dt.bac; i >= 0; i--) {
        gt = gt * x + dt.hs[i];
    }
    return gt;
}

DaThuc congDT(DaThuc dt1, DaThuc dt2) {
    DaThuc dtTong;
    dtTong.bac = (dt1.bac > dt2.bac) ? dt1.bac : dt2.bac;

    for (int i = 0; i <= dtTong.bac; i++) {
        dtTong.hs[i] = 0;
        if (i <= dt1.bac) dtTong.hs[i] += dt1.hs[i];
        if (i <= dt2.bac) dtTong.hs[i] += dt2.hs[i];
    }

    return dtTong;
}

int main() {
    DaThuc P, Q, T;
    double x;

    printf("Nhap da thuc P:\n");
    nhapDT(&P);

    printf("Nhap da thuc Q:\n");
    nhapDT(&Q);

    T = congDT(P, Q);

    printf("Nhap gia tri x: ");
    scanf("%lf", &x);

    printf("Da thuc P: ");
    inDT(P);
    printf("Da thuc Q: ");
    inDT(Q);
    printf("Da thuc T: ");
    inDT(T);

    printf("P(%.2lf) = %.2lf\n", x, tinhGiaTri(P, x));
    printf("Q(%.2lf) = %.2lf\n", x, tinhGiaTri(Q, x));
    printf("T(%.2lf) = %.2lf\n", x, tinhGiaTri(T, x));

    return 0;
}
