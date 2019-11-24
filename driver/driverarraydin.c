#include "../include/arraydin.h"
#include <stdio.h>

int main() {
    TabBuilding Tab1, Tab2;
    BUILDING B;
    IdxType idxFirst, idx3, idxLast;

    MakeArrDinEmpty(&Tab1, 5);
    InitGame(&B, 1, 'C', MakePOINT(1,1));
    AddAsLastEl(&Tab1, B);
    InitGame(&B, 2, 'F', MakePOINT(2,2));
    AddAsLastEl(&Tab1, B);
    InitGame(&B, 3, 'V', MakePOINT(3,3));
    AddAsLastEl(&Tab1, B);
    InitGame(&B, 4, 'T', MakePOINT(4,4));
    AddAsLastEl(&Tab1, B);
    AddAsLastEl(&Tab1, B);
    printf("/*************  ISI ARRAY *****************/\n");
    TulisIsiTab(Tab1);
    CopyArrBuilding(Tab1, &Tab2);
    printf("/************* HASIL COPY ARRAY *****************/\n");
    TulisIsiTab(Tab2);

    if(IsArrDinEmpty(Tab1)) {
        printf("Array kosong\n");
    } else {
        printf("Array tidak kosong\n");
    }

    if(IsArrDinFull(Tab1)) {
        printf("Array penuh\n");
    } else {
        printf("Array tidak penuh\n");
    }
    
    idx3 = getIdx(Tab1, MakePOINT(1,1));
    printf("Indeks(1,1) adalah %d\n", idx3);

    idxFirst = GetFirstIdx(Tab1);
    printf("Indeks pertama adalah %d\n", idxFirst);

    idxLast = GetLastIdx(Tab1);
    printf("Indeks pertama adalah %d\n", idxLast);
    
    if (IsIdxValidArrDin(Tab1, 7)) {
        printf("7 indeks yang valid\n");
    } else {
        printf("7 bukan indeks yang valid\n");
    }

    if (IsIdxEffArrDin(Tab1, 5)) {
        printf("5 indeks yang efektif\n");
    } else {
        printf("5 bukan indeks yang efektif\n");
    }
    
    
    return 0;
}