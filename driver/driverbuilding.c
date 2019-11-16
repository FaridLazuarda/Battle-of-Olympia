#include "../include/building.h"
#include <stdio.h>

int main() {
    BUILDING B1;
    BUILDING B2;
    InitGame(&B1, 1, 'C');
    InitGame(&B2, 2, 'V');
    PrintInfoBuilding(B2);
    printf("\n");
    PrintInfoBuilding(B1);
    printf("\n");
    InitTurn(&B1);
    PrintInfoBuilding(B1);
    printf("\n");
    LevelUp(&B1);
    PrintInfoBuilding(B1);
    return 0;
}