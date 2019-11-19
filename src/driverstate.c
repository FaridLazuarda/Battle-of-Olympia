#include "../include/state.h"
#include <stdio.h>
#include "../include/boolean.h"

int main() {
    STATE S;
    PLAYER P1, P2;
    TabBuilding TB;
    BUILDING B;
    Graph G;

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
    IsTurn(P1(S)) = true;
    IsTurn(P2(S)) = false;
    printf("Tes print daftar bangunan milik player yang lagi jalan\n");
    PrintDaftarBangunanPlayer(S);

    initGraph(&G, 5);
    AddLink(&G, 1, 3);
    AddLink(&G, 1, 2);
    AddLink(&G, 1, 5);
    AddLink(&G, 2, 4);
    // printf("Tes Print Link 1\n");
    // PrintLink(G, 1);

    // printf("Tes Print Link 2\n");
    // PrintLink(G, 2);


    // printf("Tes print daftar bangunan terhubung 1\n");
    // PrintDaftarBangunanTerhubung(S, 1, G, false);

    // printf("Tes print daftar bangunan terhubung 2\n");
    // PrintDaftarBangunanTerhubung(S, 2, G, false);

    ActiveCritHit(P1(S)) = true;
    ActiveShield(P2(S)) = 2;
    ATTACK(&S, G);
    printf("After attack\n");
    PrintDaftarBangunanPlayer(S);
    IsTurn(P1(S)) = false;
    IsTurn(P2(S)) = true;
    printf("Bangunan 2\n");
    PrintDaftarBangunanPlayer(S);
    printf("Skill P1: ");
    PrintSkill(P1(S));
    printf("\n");
    printf("Skill P2: ");
    PrintSkill(P2(S));
    printf("\n");


    return 0;
}