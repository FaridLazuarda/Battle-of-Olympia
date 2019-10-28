#include "../include/loadsave.h"
#include <stdio.h>
#include <string.h>

void LoadConfig (STATE *S)
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
{
    
}

void SaveConfig (STATE S)
/* menyimpan state ke dalam sebuah file */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
   // ntaran dah ditambah graf bgst
   // sama matriks peta
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
    fprintf(config, "%d\n", NbElmtArr(NOB(S)));
    // print building
    for (int i = 1; i <= NbElmtArr(NOB(S)); i++) {
        fprintf(config, "%c ", Kind(Elmt(NOB(S), i)));
        fprintf(config, "%d ", Owner(Elmt(NOB(S), i)));
        fprintf(config, "%d ", Troop(Elmt(NOB(S), i)));
        fprintf(config, "%d\n", Level(Elmt(NOB(S), i)));
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
    fprintf(config, "\n");
    // contoh hasil print queue
    // U S E A\n
    // print list building
    CreateEmptyList(&tempL);
    while (!IsListEmpty(OwnBuilding(P1(S)))) {
        DelVFirst(&OwnBuilding(P1(S)), &p);
        InsVLast(&tempL, p);
    }
    DelVFirst(&tempL, &p);
    InsVLast(&OwnBuilding(P1(S)), p);
    fprintf(config, "%d", p);
    while (!IsListEmpty(tempL)) {
        DelVFirst(&tempL, &p);
        InsVLast(&OwnBuilding(P1(S)), p);
        fprintf(config, " %d", p);
    }
    fprintf(config, "\n");
    // contoh hasil print list building
    // 1 3 5

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
    fprintf(config, "\n");
    // contoh hasil print queue
    // U S E A\n
    // print list building
    CreateEmptyList(&tempL);
    while (!IsListEmpty(OwnBuilding(P2(S)))) {
        DelVFirst(&OwnBuilding(P2(S)), &p);
        InsVLast(&tempL, p);
    }
    DelVFirst(&tempL, &p);
    InsVLast(&OwnBuilding(P2(S)), p);
    fprintf(config, "%d", p);
    while (!IsListEmpty(tempL)) {
        DelVFirst(&tempL, &p);
        InsVLast(&OwnBuilding(P2(S)), p);
        fprintf(config, " %d", p);
    }
    fprintf(config, "\n");
    // contoh hasil print list building
    // 2 3 5
}