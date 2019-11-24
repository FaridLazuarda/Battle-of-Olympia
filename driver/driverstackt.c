#include "../include/stackt.h"
#include <stdio.h>

int main() {    
    Stack Stack1;
    STATE S, StatePop;
    BUILDING B;

    // ALGORITMA
    CreateEmpty(&Stack1);
    CreateEmptyState(&S);
    InitGame(&B, 0, 'T', MakePOINT(1,1));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'F', MakePOINT(2,2));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'T', MakePOINT(3,3));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'F', MakePOINT(4,4));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'T', MakePOINT(5,5));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'C', MakePOINT(6,6));
    AddAsLastEl(&Buildings(S), B);
    // TulisIsiTab(Buildings(S));
    // printf("Bangunan Player 1\n");
    

    /* Castle -> Player 1, Tower -> Player 2 */
    AddBuilding(&P1(S), getIdx(Buildings(S), MakePOINT(1,1)));
    AddBuilding(&P1(S), getIdx(Buildings(S), MakePOINT(3,3)));
    AddBuilding(&P2(S), getIdx(Buildings(S), MakePOINT(2,2)));
    AddBuilding(&P2(S), getIdx(Buildings(S), MakePOINT(4,4)));
    AddBuilding(&P2(S), getIdx(Buildings(S), MakePOINT(5,5)));


    IsTurn(P1(S)) = false;
    IsTurn(P2(S)) = true;
    Push(&Stack1, S);
    printf("Bangunan player yang sedang jalan state 1\n");
    PrintDaftarBangunanPlayer(InfoTop(Stack1), false);

    IsTurn(P1(S)) = true;
    IsTurn(P2(S)) = false;
    Push(&Stack1, S);
    printf("Bangunan player yang sedang jalan state 2\n");
    PrintDaftarBangunanPlayer(InfoTop(Stack1), false);

    

    DelP(&OwnBuilding(P2(S)), 2);
    InsVLast(&OwnBuilding(P1(S)), 2);
    Push(&Stack1, S);
    Pop(&Stack1, &StatePop);
    printf("Bangunan player yang sedang jalan state 3 dari yang di pop\n");
    PrintDaftarBangunanPlayer(StatePop, false);

    if (IsEmpty(Stack1)) {
        printf("Stack kosong\n");
    } else {
        printf("Stack kosong\n");
    }
    
    return 0;
}