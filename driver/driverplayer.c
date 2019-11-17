#include <stdio.h>
#include "../include/player.h"

int main() {
    PLAYER P1,P2;
    InitPlayer(&P1, 1);
    InitPlayer(&P2, 2);
    PrintBangunanPlayer(P1);
    printf("\n");
    PrintBangunanPlayer(P2);
    printf("\n");
    AddBuilding(&P1,1);
    PrintBangunanPlayer(P1);
    printf("\n");
    AddBuilding(&P2,2);
    PrintBangunanPlayer(P2);
    printf("\n");
    AddSkill(&P1,'S');
    AddSkill(&P1,'U');
    PrintSkill(P1);
    printf("\n");
    AddSkill(&P2,'U');
    PrintSkill(P2);
    printf("\n");
    return 0;
}