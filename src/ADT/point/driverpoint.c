#include "point.h"
#include <stdio.h>

int main() {
    POINT P, mirrorP;

    BacaPOINT(&P);
    TulisPOINT(P);
    P = NextX(P);
    printf("Absis ditambah 1\n");
    TulisPOINT(P);
    P = NextY(P);
    printf("Ordinat ditambah 1\n");
    TulisPOINT(P);
    P = PlusDelta(P, 3, 4);
    printf("Absis ditambah 3, Ordinat ditambah 4\n");
    TulisPOINT(P);
    printf("\n");
    mirrorP = MirrorOf(P, true);
    printf("Mirror P dari sumbu X: ");
    TulisPOINT(mirrorP);
    printf("Jarak P dan pusat : %f\n", Jarak0(P));
    printf("Panjang P dan mirrorP : %f\n", Panjang(P, mirrorP));
    Geser(&P, -3, -4);
    printf("Absis dikurang 3, Ordinat dikurang 4\n");
    TulisPOINT(P);
    GeserKeSbX(&P);
    printf("Digeser ke sb-x pusat\n");
    TulisPOINT(P);
    GeserKeSbY(&P);
    printf("Digeser ke sb-Y pusat\n");
    TulisPOINT(P);
    Mirror(&mirrorP, false);
    printf("mirrorP dicerminkan terhadap sumbu y :");
    TulisPOINT(mirrorP);
    printf("\n");
    Putar(&mirrorP, 90);
    printf("mirrorP diputar 90 derajat");
    TulisPOINT(mirrorP);
    printf("\n");
    
    
    
    
    
    return 0;
}
