#include "loadsave.h"
#include <stdio.h>
#include <string.h>

int StrToInt(){
    int sum = 0;
    for (int j = 1; j <= CKataLOAD.Length; j++) {
        sum = sum * 10 + (CKataLOAD.TabKata[j] - '0');
    }
    return sum;
}

void LoadConfig (Stack *S, MATRIKS * Peta, Graph * graf)
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
    int count, countB, countS, countL, TPeta, LPeta, abs, ord;
    char * namafile;
    addressGraph addr;
    /* ALGORITMA */
    CreateEmpty(S);
    // printf("Masukkan nama file untuk diload: ");
    // STARTKATA();
    // printf("berhasil");
    // for (int i=1;i<=CKata.Length;i++)
    // {
    //     *(namafile + i-1) = CKata.TabKata[i];
    // }
    // *(namafile+CKata.Length) = '\0';
    // STARTKATALOAD2(namafile);
    STARTKATALOAD();
    count = StrToInt();
    // CreateEmptyState(&temp);
    ADVKATALOAD();
    TPeta = StrToInt();
    ADVKATALOAD();
    LPeta = StrToInt();
    /* Membuat matriks untuk menampung info bangunan dalam peta */
	MakeMATRIKS(TPeta, LPeta, Peta);
	for (int p=1; p<=TPeta; p++)
	{
		for (int q=1;q<=LPeta; q++)
		{
			Elmt(*Peta, p, q) = 'X';
		}
	}

    for (int i = 1; i <= count; i++) {
        Top(*S)++;
        MakeArrDinEmpty(&Buildings(InfoTop(*S)), 600);
        ADVKATALOAD();
        countB = StrToInt();
        Neff(Buildings(InfoTop(*S))) = countB;
        for (IdxType j = 1; j <= countB; j++) {
            ADVKATALOAD();
            Kind(ElmtArrDin(Buildings(InfoTop(*S)), j)) = CKataLOAD.TabKata[1];
            // printf("%c ", Kind(ElmtArrDin(Buildings(InfoTop(*S)), j)));
            ADVKATALOAD();
            Troop(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            Level(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            A(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            M(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            P(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            U(ElmtArrDin(Buildings(InfoTop(*S)), j)) = StrToInt();
            ADVKATALOAD();
            if (CKataLOAD.TabKata[1] == '1') {
                hasMove(ElmtArrDin(Buildings(InfoTop(*S)), j)) = true;
            } else {
                hasMove(ElmtArrDin(Buildings(InfoTop(*S)), j)) = false;
            }
            ADVKATALOAD();
            if (CKataLOAD.TabKata[1] == '1') {
                hasAttack(ElmtArrDin(Buildings(InfoTop(*S)), j)) = true;
            } else {
                hasAttack(ElmtArrDin(Buildings(InfoTop(*S)), j)) = false;
            }
            ADVKATALOAD();
            abs = StrToInt();
            Absis(Pos(ElmtArrDin(Buildings(InfoTop(*S)), j))) = abs;
            ADVKATALOAD();
            ord = StrToInt();
            Ordinat(Pos(ElmtArrDin(Buildings(InfoTop(*S)), j))) = ord;
            Elmt(*Peta, abs, ord) = Kind(ElmtArrDin(Buildings(InfoTop(*S)), j));
        }
        // TulisIsiTab(Buildings(InfoTop(*S)));
        // player 1
        // skill
        ADVKATALOAD();
        countS = StrToInt();
        CreateEmptyQueue(&Skill(P1(InfoTop(*S))), SkillMax);
        for (int j = 1; j <= countS; j++) {
            ADVKATALOAD();
            Add(&Skill(P1(InfoTop(*S))), CKataLOAD.TabKata[1]);
        }
        //ownbuilding
        ADVKATALOAD();
        countL = StrToInt();
        CreateEmptyList(&OwnBuilding(P1(InfoTop(*S))));
        for (int j = 1; j <= countL; j++) {
            ADVKATALOAD();
            InsVLast(&OwnBuilding(P1(InfoTop(*S))), StrToInt());
        }
        // lain lain
        ADVKATALOAD();
        if (StrToInt() == 1) {
            IsTurn(P1(InfoTop(*S))) = true;
        } else {
            IsTurn(P1(InfoTop(*S))) = false;
        }
        ADVKATALOAD();
        ActiveShield(P1(InfoTop(*S))) = StrToInt();
        ADVKATALOAD();
        if (StrToInt() == 1) {
            ActiveCritHit(P1(InfoTop(*S))) = true;
        } else {
            ActiveCritHit(P1(InfoTop(*S))) = false;
        }
        ADVKATALOAD();
        if (StrToInt() == 1) {
            ActiveAttUp(P1(InfoTop(*S))) = true;
        } else {
            ActiveAttUp(P1(InfoTop(*S))) = false;
        }

        // player 2
        // skill
        ADVKATALOAD();
        countS = StrToInt();
        CreateEmptyQueue(&Skill(P2(InfoTop(*S))), SkillMax);
        for (int j = 1; j <= countS; j++) {
            ADVKATALOAD();
            Add(&Skill(P2(InfoTop(*S))), CKataLOAD.TabKata[1]);
        }
        //ownbuilding
        ADVKATALOAD();
        countL = StrToInt();
        CreateEmptyList(&OwnBuilding(P2(InfoTop(*S))));
        for (int j = 1; j <= countL; j++) {
            ADVKATALOAD();
            InsVLast(&OwnBuilding(P2(InfoTop(*S))), StrToInt());
        }
        // lain lain
        ADVKATALOAD();
        if (StrToInt() == 1) {
            IsTurn(P2(InfoTop(*S))) = true;
        } else {
            IsTurn(P2(InfoTop(*S))) = false;
        }
        ADVKATALOAD();
        ActiveShield(P2(InfoTop(*S))) = StrToInt();
        ADVKATALOAD();
        if (StrToInt() == 1) {
            ActiveCritHit(P2(InfoTop(*S))) = true;
        } else {
            ActiveCritHit(P2(InfoTop(*S))) = false;
        }
        ADVKATALOAD();
        if (StrToInt() == 1) {
            ActiveAttUp(P2(InfoTop(*S))) = true;
        } else {
            ActiveAttUp(P2(InfoTop(*S))) = false;
        }

        // PrintInfoBuilding(ElmtArrDin(Buildings(temp), 1));
        // PrintInfoBuilding(ElmtArrDin(Buildings(InfoTop(*S)), 1));

    }
    // ADVKATALOAD();
    initGraph(graf, countB);
	for (int i=1;i<=countB;i++)
	{
		addr = FirstGraph(*graf);
		for (int j=1;j<=countB;j++)
		{
			if (CKataLOAD.TabKata[1] == '1') {
				AddLink(graf, i, j);
			}
			ADVKATALOAD();
		}
		/* "Makasih memeeeeeeeeeeeeeeeesssss" - edo */
		addr = NextGraph(addr);
	}
    
    EOPLOAD = true;
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
    char namafile[40];
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
    namafile[0] = '.';
    namafile[1] = '.';
    namafile[2] = '/';
    namafile[3] = 't';
    namafile[4] = 'e';
    namafile[5] = 's';
    namafile[6] = 't';
    namafile[7] = '/';
    for (int i=1;i<=CKata.Length;i++)
    {
        namafile[i+7] = CKata.TabKata[i];
    }
    namafile[CKata.Length+8] = '\0';
    // printf("%c %c\n", namafile[CKata.Length-1], namafile[CKata.Length]);
    config = fopen(namafile, "w");
    // printf("berhasil");
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
            fprintf(config, "%d    ", attack);
            fprintf(config, "%d ", (int)Absis(Pos(ElmtArrDin(Buildings(sTemp), i))));
            fprintf(config, "%d\n", (int)Ordinat(Pos(ElmtArrDin(Buildings(sTemp), i))));
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
            // printf("%d\n", p);
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
