#include "../include/loadsave.h"
#include <stdio.h>
#include <string.h>

void LoadConfig (STATE *S)
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
/* contoh file hasil save
   6
   C 1 40 4
   F 2 30 1
   V 0 30 3
   T 2 30 3
   C 2 40 2
   V 1 10 2
   U S E A ?
   S E R A. */
{
    /* KAMUS LOKAL */
    int countB;
    int sum;

    /* ALGORITMA */
    CreateEmptyState(S);
    STARTKATALOAD();
    for (int p = 1; p <= CKataLOAD.Length; p++) {
        sum = sum * 10 + (CKataLOAD.TabKata[p] - '0');
    }
    countB = sum;
    for (int i = 1; i <= countB; i++) {
        ADVKATALOAD();
        Kind(ElmtArr(Buildings(*S), i)) = CKataLOAD.TabKata[1];
        ADVKATALOAD();
        Owner(ElmtArr(Buildings(*S), i)) = (int) (CKataLOAD.TabKata[1]);
        ADVKATALOAD();
        sum = 0;
        for (int j = 1; j <= CKataLOAD.Length; j++) {
            sum = sum * 10 + (CKataLOAD.TabKata[j] - '0');
        }
        Troop(ElmtArr(Buildings(*S), i)) = sum;
        ADVKATALOAD();
        Level(ElmtArr(Buildings(*S), i)) = (int) (CKataLOAD.TabKata[1]);

        // masukin list building player
        if (Owner(ElmtArr(Buildings(*S), i)) == 1) {
            InsVLast(&OwnBuilding(P1(*S)), i);
        } else if (Owner(ElmtArr(Buildings(*S), i)) == 2) {
            InsVLast(&OwnBuilding(P2(*S)), i);
        }
    }
    while (CKataLOAD.TabKata[1] != '?') {
        ADVKATALOAD();
        Add(&Skill(P1(*S)), CKataLOAD.TabKata[1]);
    }
    while (!EndKataLOAD) {
        ADVKATALOAD();
        Add(&Skill(P1(*S)), CKataLOAD.TabKata[1]);
    }
}

void SaveConfig (STATE S)
/* menyimpan state ke dalam sebuah file */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
   // ntaran dah ditambah graf bgst
   // sama matriks peta
/* contoh file hasil save
   6
   C 1 40 4
   F 2 30 1
   V 0 30 3
   T 2 30 3
   C 2 40 2
   V 1 10 2
   U S E A
   1 6
   S E R A
   2 4 5. */
{
    /* KAMUS LOKAL */
    FILE * config;
    char namafile[20];
    Queue temp;
    infotypequeue x;
    List tempL;
    infotypeList p;

    /* ALGORITMA */
    printf("Masukkan nama file untuk save: ");
    scanf("%s", namafile);
    strcat(namafile, "../file/");
    config = fopen(namafile, "w");

    //print banyaknya building
    fprintf(config, "%d\n", NbElmtArr(Buildings(S)));
    // print building
    for (int i = 1; i <= NbElmtArr(Buildings(S)); i++) {
        fprintf(config, "%c ", Kind(ElmtArr(Buildings(S), i)));
        fprintf(config, "%d ", Owner(ElmtArr(Buildings(S), i)));
        fprintf(config, "%d ", Troop(ElmtArr(Buildings(S), i)));
        fprintf(config, "%d\n", Level(ElmtArr(Buildings(S), i)));
        // contoh:
        // C 2 40 4\n
        // F 0 50 1\n
    }

    // print player 1
    CreateEmptyQueue(&temp, MaxelQueue(Skill(P1(S)))); //bgst panjang bet
    while (!IsQueueEmpty(Skill(P1(S)))) {
        Del(&Skill(P1(S)), &x);
        Add(&temp, x);
    }
    // print elemen pertama
    Del(&temp, &x);
    Add(&Skill(P1(S)), x);
    fprintf(config, "%c", x);
    // print elemen selanjutnya
    while (!IsQueueEmpty(temp)) {
        Del(&temp, &x);
        Add(&Skill(P1(S)), x);
        fprintf(config, " %c", x);
    }
    fprintf(config, " ?\n"); // buat nandain kalo end of queue
    // contoh hasil print queue
    // U S E A ?\n
    // // print list building
    // CreateEmptyList(&tempL);
    // while (!IsListEmpty(OwnBuilding(P1(S)))) {
    //     DelVFirst(&OwnBuilding(P1(S)), &p);
    //     InsVLast(&tempL, p);
    // }
    // DelVFirst(&tempL, &p);
    // InsVLast(&OwnBuilding(P1(S)), p);
    // fprintf(config, "%d", p);
    // while (!IsListEmpty(tempL)) {
    //     DelVFirst(&tempL, &p);
    //     InsVLast(&OwnBuilding(P1(S)), p);
    //     fprintf(config, " %d", p);
    // }
    // fprintf(config, "\n");
    // // contoh hasil print list building
    // // 1 3 5

    // print player 2
    CreateEmptyQueue(&temp, MaxelQueue(Skill(P2(S)))); //bgst panjang bet
    while (!IsQueueEmpty(Skill(P2(S)))) {
        Del(&Skill(P2(S)), &x);
        Add(&temp, x);
    }
    // print elemen pertama
    Del(&temp, &x);
    Add(&Skill(P2(S)), x);
    fprintf(config, "%c", x);
    // print elemen selanjutnya
    while (!IsQueueEmpty(temp)) {
        Del(&temp, &x);
        Add(&Skill(P2(S)), x);
        fprintf(config, " %c", x);
    }
    fprintf(config, "."); //buat mark
    // contoh hasil print queue
    // U S E A.
    // // print list building
    // CreateEmptyList(&tempL);
    // while (!IsListEmpty(OwnBuilding(P2(S)))) {
    //     DelVFirst(&OwnBuilding(P2(S)), &p);
    //     InsVLast(&tempL, p);
    // }
    // DelVFirst(&tempL, &p);
    // InsVLast(&OwnBuilding(P2(S)), p);
    // fprintf(config, "%d", p);
    // while (!IsListEmpty(tempL)) {
    //     DelVFirst(&tempL, &p);
    //     InsVLast(&OwnBuilding(P2(S)), p);
    //     fprintf(config, " %d", p);
    // }
    // fprintf(config, "."); // buat mark
    // // contoh hasil print list building
    // // 2 3 5.
    fclose(config);
}