#include "utils.h"
#include <stdio.h>

boolean IsKataSama (const char * b) {
    boolean ret = true;
    int i = 0;
    while (ret && b[i] != '\0') 
    {
        if (CKata.TabKata[i+1] != b[i]) ret = false;
        else i++;
    }
    if (i != CKata.Length) ret = false;
    return ret;
}

int angka(){
    int sum = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        sum = sum * 10 + (CKata.TabKata[j] - '0');
    }
    return sum;
}

// int angkaLOAD(){
//     int sum = 0;
//     for (int j = 1; j <= CKataLOAD.Length; j++) {
//         sum = sum * 10 + (CKataLOAD.TabKata[j] - '0');
//     }
//     return sum;
// }

void printKata() {
    for(int i=1 ; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]);
    }
}


void PrintPeta(STATE S, MATRIKS M)
{    
    indeks i, j;
    IdxType idxB;
    POINT posisi;
    for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M)+2; i++) {
        printf("*");
    }
    printf("\n");
    for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
        printf("*");
        for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
            posisi = MakePOINT(i,j);
            idxB = getIdx(Buildings(S), posisi);
            // printf("%d, %d", GetFirstIdxBrs(M), GetFirstIdxKol(M));
            // printf(" %d ", idxB);
            // printf("%d", Owner(ElmtArrDin(Buildings(S), idxB)));
            // PrintInfo(OwnBuilding(P2(S)));
            // if (Search(OwnBuilding(P2(S)), 2) != NULL) printf("goblok");
            // printf("(%d %c)", idxB, Elmt(M, i, j));
            if (Elmt(M, i, j) != 'X') {
                if (Search(OwnBuilding(P1(S)), idxB) != NULL) print_magenta(Elmt(M, i, j));
                else if (Search(OwnBuilding(P2(S)), idxB) != NULL) print_green(Elmt(M, i, j));
                else printf("%c", Elmt(M, i, j));
            } else {
                printf(" ");
            }
        }
        posisi = MakePOINT(i,GetLastIdxKol(M));
        idxB = getIdx(Buildings(S), posisi);
        if (Elmt(M, i, GetLastIdxKol(M)) != 'X') {
            if (Search(OwnBuilding(P1(S)), idxB) != NULL) {
                print_magenta(Elmt(M, i, GetLastIdxKol(M))); 
                printf("*\n");
            } else if (Search(OwnBuilding(P2(S)), idxB) != NULL) {
                print_green(Elmt(M, i, GetLastIdxKol(M))); 
                printf("*\n");
            } else {
                printf("%c", Elmt(M, i, GetLastIdxKol(M))); 
                printf("*\n");
            }
        } else {
            printf(" *\n");
        }
    }
    printf("*");
    for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
        posisi = MakePOINT(GetLastIdxBrs(M),j);
        idxB = getIdx(Buildings(S), posisi);
        if (Elmt(M, GetLastIdxBrs(M), j) != 'X') {
            if (Search(OwnBuilding(P1(S)), idxB) != NULL) print_magenta(Elmt(M, GetLastIdxBrs(M), j)); 
            else if (Search(OwnBuilding(P2(S)), idxB) != NULL) print_green(Elmt(M, GetLastIdxBrs(M), j));
            else printf("%c", Elmt(M, GetLastIdxBrs(M), j));
        } else printf(" ");
    }
    if (Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)) != 'X') {
        posisi = MakePOINT(GetLastIdxBrs(M),GetLastIdxKol(M));
        idxB = getIdx(Buildings(S), posisi);
        if (Search(OwnBuilding(P1(S)), idxB) != NULL) {
            print_magenta(Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M))); 
            printf("*\n");
        } else if (Search(OwnBuilding(P2(S)), idxB)) {
            print_green(Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M))); 
            printf("*\n");
        } else {
            printf("%c", Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M))); 
            printf("*\n");
        }
    } else {
        printf(" *\n");
    }
    for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M)+2; i++) {
        printf("*");
    }
    printf("\n");
}
