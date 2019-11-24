#include "../include/building.h"
#include <stdio.h>

int main() {
    BUILDING B1;
    BUILDING B2;
    BUILDING B3;
    InitGame(&B1, 1, 'C', MakePOINT(1,1));
    // InitGame(&B2, 2, 'V', MakePOINT(2,2));
    // PrintInfoBuilding(B2);
    PrintInfoBuilding(B1);
    CopyBuilding(B1, &B3);
    printf("Hasil copy: \n");
    PrintInfoBuilding(B3);
    // InitTurn(&B1);
    // PrintInfoBuilding(B1);
    // LevelUp(&B1, false);
    // PrintInfoBuilding(B1);
    return 0;
}