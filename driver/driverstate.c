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
    InitGame(&B, 0, 'C', MakePOINT(1,1));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'V', MakePOINT(2,2));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'V', MakePOINT(3,3));
    AddAsLastEl(&Buildings(S), B);
    InitGame(&B, 0, 'F', MakePOINT(4,4));
    AddAsLastEl(&Buildings(S), B);
    // TulisIsiTab(Buildings(S));
    // printf("Bangunan Player 1\n");

    /* Castle -> Player 1, Tower -> Player 2 */
    AddBuilding(&P1(S), getIdx(Buildings(S), MakePOINT(1,1)));
    AddBuilding(&P1(S), getIdx(Buildings(S), MakePOINT(3,3)));
    AddBuilding(&P2(S), getIdx(Buildings(S), MakePOINT(2,2)));
    IsTurn(P1(S)) = true;
    IsTurn(P2(S)) = false;
    printf("Tes print daftar bangunan milik player yang lagi jalan\n");
    PrintDaftarBangunanPlayer(S);

    initGraph(&G, 4);
    AddLink(&G, 1, 3);
    AddLink(&G, 1, 2);
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


    return 0;
}