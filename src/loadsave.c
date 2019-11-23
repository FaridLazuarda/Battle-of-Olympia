#include "../include/loadsave.h"
#include <stdio.h>
#include <string.h>

void LoadConfig (Stack *S)
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Troop, Level, A, M, P, U, hasMove, hasAttack, Pos
   2. Player: queue skill, list building, isturn, shield, critical hit, attack up
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
/* contoh file hasil save
   1 (menandakan banyaknya elemen stack)
   6
   C 40 4    25 100 0 0   0 0   1 1
   F 30 1    10 20 0 80   1 0   1 5
   V 30 3    15 40 0 0    0 0   2 7
   T 30 3    20 40 1 0    0 0   2 2
   C 40 2    15 60 0 0    0 0   5 8
   V 10 2    10 30 0 0    0 0   8 4
   4 U S E A    4  1 2 3 4      1 0 0 0
   4 S E R A    2  5 6          0 1 0 0*/
{
    /* KAMUS LOKAL */
    int countB;
    int sum;

    /* ALGORITMA */
    // CreateEmptyState(S);
    // STARTKATALOAD();
    // for (int p = 1; p <= CKataLOAD.Length; p++) {
    //     sum = sum * 10 + (CKataLOAD.TabKata[p] - '0');
    // }
    // countB = sum;
    // for (int i = 1; i <= countB; i++) {
    //     ADVKATALOAD();
    //     Kind(ElmtArrDin(Buildings(*S), i)) = CKataLOAD.TabKata[1];
    //     ADVKATALOAD();
    //     // Owner(ElmtArrDin(Buildings(*S), i)) = (int) (CKataLOAD.TabKata[1]);
    //     ADVKATALOAD();
    //     sum = 0;
    //     for (int j = 1; j <= CKataLOAD.Length; j++) {
    //         sum = sum * 10 + (CKataLOAD.TabKata[j] - '0');
    //     }
    //     Troop(ElmtArrDin(Buildings(*S), i)) = sum;
    //     ADVKATALOAD();
    //     Level(ElmtArrDin(Buildings(*S), i)) = (int) (CKataLOAD.TabKata[1]);

    //     // masukin list building player
    //     // if (Owner(ElmtArrDin(Buildings(*S), i)) == 1) {
    //     //    InsVLast(&OwnBuilding(P1(*S)), i);
    //     // } else if (Owner(ElmtArrDin(Buildings(*S), i)) == 2) {
    //     //    InsVLast(&OwnBuilding(P2(*S)), i);
    //     // }
    // }
    // while (CKataLOAD.TabKata[1] != '?') {
    //     ADVKATALOAD();
    //     Add(&Skill(P1(*S)), CKataLOAD.TabKata[1]);
    // }
    // while (!EndKataLOAD) {
    //     ADVKATALOAD();
    //     Add(&Skill(P1(*S)), CKataLOAD.TabKata[1]);
    // }
}

void SaveConfig (Stack S)
/* menyimpan state ke dalam sebuah file */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Troop, Level, A, M, P, U, hasMove, hasAttack, Pos
   2. Player: queue skill, list building, isturn, shield, critical hit, attack up
/* contoh file hasil save
   1 (menandakan banyaknya elemen stack)
   6
   C 40 4    25 100 0 0   0 0   1 1
   F 30 1    10 20 0 80   1 0   1 5
   V 30 3    15 40 0 0    0 0   2 7
   T 30 3    20 40 1 0    0 0   2 2
   C 40 2    15 60 0 0    0 0   5 8
   V 10 2    10 30 0 0    0 0   8 4
   4 U S E A    4  1 2 3 4      1 0 0 0
   4 S E R A    2  5 6          0 1 0 0*/
{
    /* KAMUS LOKAL */
    FILE * config;
    char namafile[20];
    Queue Qtemp;
    infotypequeue x;
    List tempL;
    infotypeList p;
    int move, attack, count, countSkill, countList;
    int isturn, crithit, attup;
    Stack temp;
    STATE sTemp;

    /* ALGORITMA */
    // pindahin semua isi stack sekaligus itung jumlahnya
    count = 0;
    // printf("gila aku");
    // if (IsEmpty(S)) printf("galauu");
    CreateEmpty(&temp);
    while (!IsEmpty(S)) {
        Pop(&S, &sTemp);
        Push(&temp, sTemp);
        count++;
    }
    // printf("%d", count);
    printf("Masukkan nama file untuk save: ");
    STARTKATA();
    // config = fopen("../test/hayolo.txt","w");

    // scanf("%s", namafile);
    //strcat(namafile, "../file/");
    for (int i=1;i<=CKata.Length;i++)
    {
        namafile[i-1] = CKata.TabKata[i];
    }
    namafile[CKata.Length] = '\0';
    printf("%c %c\n", namafile[CKata.Length-1], namafile[CKata.Length]);
    config = fopen(namafile, "w");
    printf("berhasil");
    // print banyaknya state
    fprintf(config, "%d\n", count);

    while (!IsEmpty(temp)) {
        Pop(&temp, &sTemp);
        Push(&S, sTemp);
        //print banyaknya building
        fprintf(config, "%d\n", Neff(Buildings(sTemp)));
        // print building
        for (int i = 1; i <= Neff(Buildings(sTemp)); i++) {
            fprintf(config, "%c ", Kind(ElmtArrDin(Buildings(sTemp), i)));
            // fprintf(config, "%d ", Owner(ElmtArrDin(Buildings(S), i)));
            fprintf(config, "%d ", Troop(ElmtArrDin(Buildings(sTemp), i)));
            fprintf(config, "%d    ", Level(ElmtArrDin(Buildings(sTemp), i)));
            fprintf(config, "%d ", A(ElmtArrDin(Buildings(sTemp), i)));
            fprintf(config, "%d ", M(ElmtArrDin(Buildings(sTemp), i)));
            fprintf(config, "%d ", P(ElmtArrDin(Buildings(sTemp), i)));
            fprintf(config, "%d    ", U(ElmtArrDin(Buildings(sTemp), i)));
            if (hasMove(ElmtArrDin(Buildings(sTemp), i))) {
                move = 1;
            } else {
                move = 0;
            }
            fprintf(config, "%d ", move);
            if (hasAttack(ElmtArrDin(Buildings(sTemp), i))) {
                attack = 1;
            } else {
                attack = 0;
            }
            fprintf(config, "%d\n", attack);
        }
        // print player 1
        countSkill = 0;
        CreateEmptyQueue(&Qtemp, MaxelQueue(Skill(P1(sTemp)))); //bgst panjang bet
        while (!IsQueueEmpty(Skill(P1(sTemp)))) {
            Del(&Skill(P1(sTemp)), &x);
            Add(&Qtemp, x);
            countSkill++;
        }
        // print banyaknya queue
        fprintf(config, "%d  ", countSkill);
        // print elemen queue
        while (!IsQueueEmpty(Qtemp)) {
            Del(&Qtemp, &x);
            Add(&Skill(P1(sTemp)), x);
            fprintf(config, "%c ", x);
        }

        // list ownbuilding
        countList = 0;
        CreateEmptyList(&tempL);
        while (!IsListEmpty(OwnBuilding(P1(sTemp)))) {
            DelVFirst(&OwnBuilding(P1(sTemp)), &p);
            InsVLast(&tempL, p);
            countList++;
        }
        // print banyaknya list
        fprintf(config, "  %d  ", countList);
        // print elemen list
        while (!IsListEmpty(tempL)) {
            DelVFirst(&tempL, &p);
            InsVLast(&OwnBuilding(P1(sTemp)), p);
            fprintf(config, "%d ", p);
        }
        if (IsTurn(P1(sTemp))) {
            isturn = 1;
        } else {
            isturn = 0;
        }
        fprintf(config, " %d ", isturn);
        fprintf(config, " %d ", ActiveShield(P1(sTemp)));
        if (ActiveCritHit(P1(sTemp))) {
            crithit = 1;
        } else {
            crithit = 0;
        }
        fprintf(config, " %d ", crithit);

        if (ActiveAttUp(P1(sTemp))) {
            attup = 1;
        } else {
            attup = 0;
        }
        fprintf(config, " %d\n", attup);

        // print player 2
        countSkill = 0;
        CreateEmptyQueue(&Qtemp, MaxelQueue(Skill(P2(sTemp)))); //bgst panjang bet
        while (!IsQueueEmpty(Skill(P2(sTemp)))) {
            Del(&Skill(P2(sTemp)), &x);
            Add(&Qtemp, x);
            countSkill++;
        }
        // print banyaknya queue
        fprintf(config, "%d  ", countSkill);
        // print elemen queue
        while (!IsQueueEmpty(Qtemp)) {
            Del(&Qtemp, &x);
            Add(&Skill(P2(sTemp)), x);
            fprintf(config, "%c ", x);
        }

        // list ownbuilding
        countList = 0;
        CreateEmptyList(&tempL);
        while (!IsListEmpty(OwnBuilding(P2(sTemp)))) {
            DelVFirst(&OwnBuilding(P2(sTemp)), &p);
            InsVLast(&tempL, p);
            countList++;
        }
        // print banyaknya list
        fprintf(config, "  %d  ", countList);
        // print elemen list
        while (!IsListEmpty(tempL)) {
            DelVFirst(&tempL, &p);
            InsVLast(&OwnBuilding(P2(sTemp)), p);
            fprintf(config, "%d ", p);
        }
        if (IsTurn(P2(sTemp))) {
            isturn = 1;
        } else {
            isturn = 0;
        }
        fprintf(config, " %d ", isturn);
        fprintf(config, " %d ", ActiveShield(P2(sTemp)));
        if (ActiveCritHit(P2(sTemp))) {
            crithit = 1;
        } else {
            crithit = 0;
        }
        fprintf(config, " %d ", crithit);

        if (ActiveAttUp(P2(sTemp))) {
            attup = 1;
        } else {
            attup = 0;
        }
        fprintf(config, " %d\n\n", attup);
    }
   
    fclose(config);
}