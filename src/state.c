#include "../include/state.h"
#include <stdio.h>


void CreateEmptyState (STATE *S)
/* State terbentuk dengan init player 1 dan 2, dan empty array building */
{
    InitPlayer(&P1(*S));
    InitPlayer(&P2(*S));
    MakeArrDinEmpty(&Buildings(*S), 600);
}

void CopyState (STATE In, STATE *Out) {
    CopyPlayer(P1(In), &P1(*Out));
    CopyPlayer(P2(In), &P2(*Out));
    CopyArrBuilding(Buildings(In), &Buildings(*Out));
}

void PrintDaftarBangunanTerhubung(STATE S, infotypeList X, Graph G, boolean attack){
    // KAMUS LOKAL
    int i, num;
    PLAYER P;
    addressList adrL;
    addressGraph adrG;

    // ALGORITMA
    P = CheckTurn(S);
    adrG = SearchGraph(G, X);
    if (!IsListEmpty(Link(adrG))) {
        adrL = First(Link(adrG));
        num = 1;
        for (i = 1; i <= NbElmt(Link(adrG)); i++) {
            if ((!attack) || ((attack) && (Search(OwnBuilding(P), Info(adrL)) == Nil))) {
                printf("%d. ", num);
            if (Kind(ElmtArrDin(Buildings(S), Info(adrL))) == 'C') {
                printf("Castle ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(adrL))) == 'T') {
                printf("Tower ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(adrL))) == 'F') {
                printf("Fort ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(adrL))) == 'V') {
                printf("Village ");
            }

            // Print POINT (posisi dari bangunan belum ada point di building.h)
            TulisPOINT(Pos(ElmtArrDin(Buildings(S), Info(adrL))));

            printf(" %d ", Troop(ElmtArrDin(Buildings(S), Info(adrL)))); // Jumlah Pasukan
            printf("lv. %d\n", Level(ElmtArrDin(Buildings(S), Info(adrL))));
            num++;
            }
            adrL = Next(adrL);
        }
    } else {
        printf("Tidak ada bangunan yang terhubung!");
    }
    
}

void PrintDaftarBangunanPlayer(STATE S, boolean attack){
/*  I. S.   P terdefinisi
    F. S.   Mencetak jenis, posisi, jumlah pasukan, dan level dari tiap bangunan yang dimiliki oleh P */

    // KAMUS LOKAL
    int i, num;
    addressList Adr;
    PLAYER P;

    // ALGORITMA
    P = CheckTurn(S);
    Adr = First(OwnBuilding(P));
    num = 1;
    printf("Daftar bangunan:\n");
    // jenis, lokasi, jumlah pasukan, level
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        if ((!attack) || ((attack) && (Troop(ElmtArrDin(Buildings(S), Info(Adr))) > 0) && (!hasAttack(ElmtArrDin(Buildings(S), Info(Adr)))))) {
            printf("%d. ", num);
            if (Kind(ElmtArrDin(Buildings(S), Info(Adr))) == 'C') {
                printf("Castle ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(Adr))) == 'T') {
                printf("Tower ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(Adr))) == 'F') {
                printf("Fort ");
            } else if (Kind(ElmtArrDin(Buildings(S), Info(Adr))) == 'V') {
                printf("Village ");
            }

            // Print POINT (posisi dari bangunan belum ada point di building.h)
            TulisPOINT(Pos(ElmtArrDin(Buildings(S), Info(Adr))));

            printf(" %d ", Troop(ElmtArrDin(Buildings(S), Info(Adr)))); // Jumlah Pasukan
            printf("lv. %d\n", Level(ElmtArrDin(Buildings(S), Info(Adr))));

            num++;
        }
        Adr = Next(Adr);
    }
}



PLAYER CheckTurn(STATE S){
    /*  Mengembalikan PLAYER yang sedang menjalankan turn, yaitu apabila IsTurn = true */
    // KAMUS LOKAL
    PLAYER P;

    // ALGORITMA
    if (IsTurn(P1(S))) {
        P = P1(S);
    } else {
        P = P2(S);
    }
    return P;
}

boolean canAttack(STATE S) {
    /*  Mengembalikan apakah PLAYER yang sedang menjalankan turn dapat menggunakan command ATTACK,
        yaitu apabila semua bangunan telah melancarkan attack atau jumlah troop = 0.
        Apabila ada satu bangunan saja yang tidak memenuhi kedua bangunan tersebut, akan dikembalikan true. 
        Jika tidak ada, maka false */
    /* KAMUS LOKAL */
    boolean attack;
    PLAYER P;
    addressList adrL;
    IdxType idxBuilding;
    BUILDING B;

    /* ALGORITMA */
    P = CheckTurn(S);
    attack = false;
    adrL = First(OwnBuilding(P));
    while ((adrL != Nil) && (!attack)) {
        idxBuilding = Info(adrL);
        B = ElmtArrDin(Buildings(S), idxBuilding);
        if ((hasAttack(B)) || (Troop(B) == 0)) {
            adrL = Next(adrL);
        } else {
            attack = true;
        }
    }

    return attack;
}

int attBuildCount(STATE S) {
    /* KAMUS LOKAL */
    int countBuilding;
    PLAYER P;
    addressList adrL;
    IdxType idxBuilding;
    BUILDING B;

    /* ALGORITMA */
    P = CheckTurn(S);
    countBuilding = 0;
    adrL = First(OwnBuilding(P));
    while (adrL != Nil) {
        idxBuilding = Info(adrL);
        B = ElmtArrDin(Buildings(S), idxBuilding);
        if ((!hasAttack(B)) && (Troop(B) > 0)) {
            countBuilding++;
        }
        adrL = Next(adrL);
    }

    return countBuilding;
}

int buildToAttCount(STATE S, infotypeList X, Graph G) {
    // KAMUS LOKAL
    int i, countBuilding;
    addressList adrL;
    addressGraph adrG;
    IdxType IdxBuilding;
    BUILDING B;

    // ALGORITMA
    countBuilding = 0;
    adrG = SearchGraph(G, X);
    if (!IsListEmpty(Link(adrG))) {
        adrL = First(Link(adrG));
        while (adrL != Nil) {
            IdxBuilding = Info(adrL);
            B = ElmtArrDin(Buildings(S), IdxBuilding);
            if ((!hasAttack(B)) && (Troop(B) > 0)) {
                countBuilding++;
            }
            adrL = Next(adrL);
        }
    }

    return countBuilding;
}

void ATTACK(STATE *S, Graph G){
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */

    /* KAMUS LOKAL */
    PLAYER P, enemyP;
    infotypeList inputAttBuilding, inputBuildToAtt;
    IdxType idxAttBuilding, idxBuildToAtt;
    int attTroop, i , j, ShieldCount, towerCount;
    addressList adrPlayer, adrEnemy, iterateTower;
    addressGraph adrGraphBuilding;
    boolean CritHit, AttUp;

    /* ALGORITMA */
    P = CheckTurn(*S);
    if (IsTurn(P1(*S))) {
        enemyP = P2(*S);
    } else {
        enemyP = P1(*S);
    }

    if (attBuildCount(*S) > 0) {
        /* Pilih bangunan untuk menyerang */
        printf("Jumlah bangunan attack : %d\n", attBuildCount(*S));
        PrintDaftarBangunanPlayer(*S, true);
        do {
            printf("Bangunan yang digunakan untuk menyerang: ");  
            STARTKATA();
            inputAttBuilding = 0;
            for (int j = 1; j <= CKata.Length; j++) {
                inputAttBuilding = inputAttBuilding * 10 + (CKata.TabKata[j] - '0');
            }
        } while ((inputAttBuilding < 1) || (inputAttBuilding > attBuildCount(*S)));
        
        i = 1;
        adrPlayer = First(OwnBuilding(P));

        while ((Troop(ElmtArrDin(Buildings(*S), Info(adrPlayer))) == 0) || (hasAttack(ElmtArrDin(Buildings(*S), Info(adrPlayer))))) {
            /* skip bangunan di awal list yang gabisa attack (troop = 0 atau udah nyerang) */
            adrPlayer = Next(adrPlayer);
        }
        
        
        while (i < inputAttBuilding) {
            if (Troop(ElmtArrDin(Buildings(*S), Info(adrPlayer))) == 0) {
                /* Skip bangunan yang jumlah troop 0 */
                adrPlayer = Next(adrPlayer);
            } else if(hasAttack(ElmtArrDin(Buildings(*S), Info(adrPlayer)))) {
                /* Skip bangunan yang udah attack */
                adrPlayer = Next(adrPlayer);
            } else {
                adrPlayer = Next(adrPlayer);
                i++;
            }
        }
        idxAttBuilding = Info(adrPlayer);
        // printf("%c\n", Kind(ElmtArrDin(Buildings(*S), idxAttBuilding)));

        /* Pilih bangunan untuk diserang */
        printf("Jumlah bangunan attack : %d\n", buildToAttCount(*S, Info(adrPlayer), G));
        printf("Daftar bangunan yang dapat diserang\n");
        PrintDaftarBangunanTerhubung(*S, Info(adrPlayer), G, true);
        do {
            printf("Bangunan yang diserang: ");
            STARTKATA();
            inputBuildToAtt = 0;
            for (int j = 1; j <= CKata.Length; j++) {
                inputBuildToAtt = inputBuildToAtt * 10 + (CKata.TabKata[j] - '0');
            }
        } while ((inputBuildToAtt < 1) || (inputBuildToAtt > buildToAttCount(*S, Info(adrPlayer), G)));
        


        adrGraphBuilding = SearchGraph(G, Info(adrPlayer));
        adrEnemy = First(Link(adrGraphBuilding));
        if (Search(OwnBuilding(P), Info(adrEnemy)) != Nil) {
            /* Menangani kasus apabila pick 1, dan di link building first adalah building milik sendiri */
            adrEnemy = Next(adrEnemy);
        }
        j = 1;
        while (j < inputBuildToAtt) {
            if (Search(OwnBuilding(P), Info(adrEnemy)) != Nil) {
                /* Skip bangunan milik sendiri */
                adrEnemy = Next(adrEnemy);
            } else {
                adrEnemy = Next(adrEnemy);
                j++;
            }
        }
        idxBuildToAtt = Info(adrEnemy);
        // printf("%c\n", Kind(ElmtArrDin(Buildings(*S), idxBuildToAtt)));


        /* Menentukan jumlah pasukan */
        printf("Pasukan dalam bangunan: %d\n", Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)));
        printf("Jumlah pasukan untuk attack: ");
        STARTKATA();
        attTroop = 0;
        for (int j = 1; j <= CKata.Length; j++) {
            attTroop = attTroop * 10 + (CKata.TabKata[j] - '0');
        }
        while ((attTroop <= 0) || (attTroop > Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)))) {
            printf("Jumlah pasukan untuk attack: ");
            STARTKATA();
            attTroop = 0;
            for (int j = 1; j <= CKata.Length; j++) {
                attTroop = attTroop * 10 + (CKata.TabKata[j] - '0');
            }
        }
        /************ TAMBAHIN VALIDASI ************/
        
        /* Step Attack */
        CritHit = ActiveCritHit(P);
        AttUp = ActiveAttUp(P);
        ShieldCount = ActiveShield(enemyP);
        
        printf("Player troop before attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)));
        printf("Opposite building troop before attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)));
        Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)) = Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)) - attTroop;
        /* Check Critical Hit */
        if (CritHit) {
            attTroop = attTroop * 2;
        }
        /* Check Shield apabila tidak terdapat Attack Up dan Critical Hit */
        if ((!AttUp) && (!CritHit) && ((P(ElmtArrDin(Buildings(*S), idxBuildToAtt))) || (ShieldCount > 0) )) {
            /* Apabila bangunan yang diserang memiliki pertahanan saat tidak ada Critical Hit dan AttackUp */
            attTroop = (attTroop * 3) / 4;
        }
        printf("Final attack troop: %d\n\n", attTroop);
        if (attTroop >= Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt))) {
            if (Search(OwnBuilding(enemyP), idxBuildToAtt) != Nil) {
                /* Kalo buildingnya udah ada yang punya */
                DelP(&OwnBuilding(enemyP), idxBuildToAtt);
                if (NbElmt(OwnBuilding(enemyP)) == 2) {
                    /* Kondisi untuk perolehan skill Shield */
                    printf("Testing perolehan skill shield :");
                    Add(&Skill(enemyP), 'S');
                    printf(" %c masuk tail skill\n", InfoTail(Skill(enemyP)));
                }

                if (Kind(ElmtArrDin(Buildings(*S), idxBuildToAtt)) == 'F') {
                    /* Kondisi untuk perolehan skill Extra Turn */
                    printf("Testing perolehan skill Extra Turn :");
                    Add(&Skill(enemyP), 'E');
                    printf(" %c masuk tail skill\n", InfoTail(Skill(enemyP)));
                }

                if (Kind(ElmtArrDin(Buildings(*S), idxBuildToAtt)) == 'T') {
                    /* Kondisi untuk perolehan skill Attack Up */
                    towerCount = 0;
                    iterateTower = First(OwnBuilding(P));
                    if (!IsListEmpty(OwnBuilding(P))) {
                        while (iterateTower != NULL) {
                            if (Kind(ElmtArrDin(Buildings(*S), Info(iterateTower))) == 'T') {
                                towerCount++;
                            }
                            iterateTower = Next(iterateTower);
                        }
                    }

                    if (towerCount == 2) { /* Berjumlah 2 karena yang baru dikalahin belum masuk */
                        printf("Testing perolehan skill Attack Up :");
                        Add(&Skill(P), 'A');
                        printf(" %c masuk tail skill\n", InfoTail(Skill(P)));
                    }
                }
            }
            InsVLast(&OwnBuilding(P), idxBuildToAtt);
            
            Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = attTroop - Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt));
            if (CritHit) {
                Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) /= 2;
            }

            if ((!AttUp) && (!CritHit) && ((P(ElmtArrDin(Buildings(*S), idxBuildToAtt))) || (ShieldCount > 0) )) {
                /* Apabila bangunan yang diserang memiliki pertahanan saat tidak ada Critical Hit dan AttackUp */
                Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = (Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) * 4) / 3;
            }

            if (ActiveAttUp(P)) {
                ActiveAttUp(P) = false;
            }
            Level(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = 1;

            if (NbElmt(OwnBuilding(P)) == 10) {
                /* Kondisi untuk perolehan skill Barrage */
                printf("Testing perolehan skill Barrage :");
                Add(&Skill(enemyP), 'B');
                printf(" %c masuk tail skill\n", InfoTail(Skill(enemyP)));
            }

            hasAttack(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = false;
        } else {
            Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) - attTroop;
            printf("Bangunan gagal direbut\n");
        }

        hasAttack(ElmtArrDin(Buildings(*S), idxAttBuilding)) = true; /* Supaya ga bisa attack lagi */

        printf("Player troop after attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)));
        printf("Opposite Building troop after attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)));

        if (IsTurn(P1(*S))) {
            P1(*S) = P;
            P2(*S) = enemyP;
        } else {
            P2(*S) = P;
            P1(*S) = enemyP;
        }
    } else {
        printf("Anda tidak memiliki bangunan yang dapat melancarkan ATTACK!\n");
        printf("Keterangan: Apabila sebuah bangunan telah menyerang pada giliran yang sama atau jumlah troopnya adalah 0,\nmaka bangunan tersebut tidak dapat melancarkan ATTACK\n");
    }

    

}
void LEVEL_UP(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Apabila bangunan yang dipilih PLAYER yang sedang melaksanakan turn memiliki jumlah pasukan >= M/2,
            maka level bangunan akan bertambah 1 dan pasukan berkurang sejumlah M/2.
            Apabila bangunan tidak memiliki jumlah pasukan >= M/2, maka akan ditampilkan pesan dan I. S. = F. S. */
    //AKAMUS LOKAL
    PLAYER P;
    int i, buildLvlUp;
    addressList Adr;

    // ALGORITMA
    P = CheckTurn(*S);
    Adr = First(OwnBuilding(P));
    buildLvlUp = 0;
    printf("Bangunan yang akan di level-up:");
    STARTKATA();
    for (int j = 1; j <= CKata.Length; j++) {
        buildLvlUp = buildLvlUp * 10 + (CKata.TabKata[j] - '0');
    }
    for (i = 1; i < buildLvlUp; i++) {
        Adr = Next(Adr);
    }
    LevelUp(&ElmtArrDin(Buildings(*S), Info(Adr)), false);

    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}

void MOVE(STATE *S, Graph G)
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang menggunakan skill ini memindahkan sejumlah pasukan dari 1 bangunan ke bangunan yang lain
            yang terhubung */
{
    PLAYER P;
    infotypeList inputMoveBuilding, inputBuildToMove;
    IdxType idxMoveBuilding, idxBuildingToMove;
    int movetroop, i, j;
    BUILDING moveBuild, buildToMove;
    addressList addrPlayer,addrTujuan;
    addressGraph addrGraphBuilding;

    /* Pilih bangunan untuk move */
    P = CheckTurn(*S);
    PrintDaftarBangunanPlayer(*S, false);
    printf("Pilih bangunan: ");
    STARTKATA();
    inputMoveBuilding = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        inputMoveBuilding = inputMoveBuilding * 10 + (CKata.TabKata[j] - '0');
        
    }
    i = 1;
    addrPlayer = First(OwnBuilding(P));
    if (Troop(ElmtArrDin(Buildings(*S), Info(addrPlayer))) == 0){
        addrPlayer = Next(addrPlayer);
    }else if (hasMove(ElmtArrDin(Buildings(*S), Info(addrPlayer)))){
        addrPlayer = Next(addrPlayer);
    }
    
    while (i < inputMoveBuilding) {
        if (Troop(ElmtArrDin(Buildings(*S), Info(addrPlayer))) == 0) {
            /* Skip bangunan yang jumlah troop 0 */
            addrPlayer = Next(addrPlayer);
        } else if(hasAttack(ElmtArrDin(Buildings(*S), Info(addrPlayer)))) {
            /* Skip bangunan yang udah attack */
            addrPlayer = Next(addrPlayer);
        } else {
            addrPlayer = Next(addrPlayer);
            i++;
        }
    }
    idxMoveBuilding = Info(addrPlayer);

    /* Pilih bangunan tujuan move */
    printf("Daftar bangunan terdekat:\n");
    PrintDaftarBangunanTerhubung(*S, Info(addrPlayer), G, false);
    printf("Bangunan yang akan menerima: ");
    STARTKATA();
    inputBuildToMove = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        inputBuildToMove = inputBuildToMove * 10 + (CKata.TabKata[j] - '0');
    }
    addrGraphBuilding = SearchGraph(G, Info(addrPlayer));
    addrTujuan = First(Link(addrGraphBuilding));
    if (Search(OwnBuilding(P), Info(addrTujuan)) == Nil) {
        /* Menangani kasus apabila pick 1, dan di link building first adalah building milik sendiri */
        addrTujuan = Next(addrTujuan);
    }
    j = 1;
    while (j < inputBuildToMove) {
        if (Search(OwnBuilding(P), Info(addrPlayer)) == Nil) {
            /* Skip bangunan milik sendiri */
            addrPlayer = Next(addrPlayer);
        } else {
            addrPlayer = Next(addrPlayer);
            j++;
        }
    }
    idxBuildingToMove = Info(addrTujuan);

    /* Menentukan jumlah pasukan */
    printf("Jumlah pasukan untuk move: ");
    STARTKATA();

    for (int j = 1; j <= CKata.Length; j++) {
        movetroop = movetroop * 10 + (CKata.TabKata[j] - '0');
    }
    if ((movetroop < 0) || (movetroop > Troop(ElmtArrDin(Buildings(*S), idxMoveBuilding)))) {
        printf("Pasukan tidak cukup untuk move.\n");
    }

    /* MOVE */
    if(movetroop > Troop(ElmtArrDin(Buildings(*S), idxMoveBuilding))){
        printf("Gacukup bray.\n");
    }else if (hasMove(ElmtArrDin(Buildings(*S), idxMoveBuilding)) == true){
        printf("Bangunan sudah pernah melakukan MOVE pada turn ini.\n");
    } else{
        Troop(ElmtArrDin(Buildings(*S), idxMoveBuilding)) = Troop(ElmtArrDin(Buildings(*S), idxMoveBuilding)) - movetroop;
        Troop(ElmtArrDin(Buildings(*S), idxBuildingToMove)) = Troop(ElmtArrDin(Buildings(*S), idxBuildingToMove)) + movetroop;
        hasMove(ElmtArrDin(Buildings(*S), idxMoveBuilding)) = true;

        printf("%d", movetroop);
        printf(" pasukan dari ");
        if(Kind(ElmtArrDin(Buildings(*S), idxMoveBuilding)) == 'T'){
            printf("Tower ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxMoveBuilding)));
        }else if(Kind(ElmtArrDin(Buildings(*S), idxMoveBuilding)) == 'C'){
            printf("Castle ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxMoveBuilding)));
        }else if(Kind(ElmtArrDin(Buildings(*S), idxMoveBuilding)) == 'V'){
            printf("Village ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxMoveBuilding)));
        }else if(Kind(ElmtArrDin(Buildings(*S), idxMoveBuilding)) == 'F'){
            printf("Fort ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxMoveBuilding)));
        }
        
        printf(" telah berpindah ke ");
        if(Kind(ElmtArrDin(Buildings(*S), idxBuildingToMove)) == 'T'){
            printf("Tower ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxBuildingToMove)));
            printf("\n");
        }else if(Kind(ElmtArrDin(Buildings(*S), idxBuildingToMove)) == 'C'){
            printf("Castle ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxBuildingToMove)));
            printf("\n");
        }else if(Kind(ElmtArrDin(Buildings(*S), idxBuildingToMove)) == 'V'){
            printf("Village ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxBuildingToMove)));
            printf("\n");
        }else if(Kind(ElmtArrDin(Buildings(*S), idxBuildingToMove)) == 'F'){
            printf("Fort ");
            TulisPOINT(Pos(ElmtArrDin(Buildings(*S), idxBuildingToMove)));
            printf("\n");
        }
    }
}

void InstantUpgrade(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, seluruh bangunannya akan bertambah 1 level */

    // KAMUS LOKAL
    PLAYER P;
    int i;
    addressList Adr;

    // ALGORITMA
    P = CheckTurn(*S);
    Adr = First(OwnBuilding(P));
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        LevelUp(&ElmtArrDin(Buildings(*S), Info(Adr)), true);
        Adr = Next(Adr);
    }

    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}


void Shield(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, akan memiliki pertahanan selama 2 turn.
            Apabila digunakan 2 kali berturut-turut, durasi tidak akan bertambah namun akan menjadi nilai maksimum */
    // KAMUS LOKAL
    boolean IsShieldAvailable;
    PLAYER P;
    int countshield;

    // ALGORITMA
    countshield = 0;
    P = CheckTurn(*S);
    if (ActiveShield(P) == 0) {
        ActiveShield(P) += 2;
    }
    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}
void ExtraTurn(STATE *S)
/*  I. S.   S terdefinisi
    F. S.   Player yang menggunakan skill ini akan mendapatkan turn tambahan */
{

}
void AttackUp(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Pada turn ini, bangunan PLAYER lawan yang memiliki pertahanan tidak akan mempengaruhi penyerangan */

    // KAMUS LOKAL 
    PLAYER P;

    //ALGORITMA
    P = CheckTurn(*S);
    ActiveAttUp(P) = true;
    if(IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}


void CriticalHit(STATE *S)
/*  I. S.   S terdefinisi
    F. S.   Setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang
            setengah dari jumlah seharusnya */
{
    //KAMUS LOKAL
    PLAYER P;
    //ALGORITMA
    P = CheckTurn(*S);
    ActiveCritHit(P) = true;
    if(IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}

boolean InsReinCheck (STATE S)
/* mengembalikan true jika seluruh bangunan player memiliki level 4 */
{
    // Kamus
    PLAYER P;
    addressList Adr;
    boolean flag;
    int i;
    // Algoritma
    P = CheckTurn(S);
    flag = true;
    Adr = First(OwnBuilding(P));
    i = 1;

    while (flag && i <= NbElmt(OwnBuilding(P))) {
        if (Level(ElmtArrDin(Buildings(S), Info(Adr))) < 4) flag = false;
        else i++;
    }
    return flag;
}

void InstantReinforcement(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang memiliki skill ini akan mendapat tambahan 5 pasukan */
    
    // KAMUS LOKAL
    PLAYER P;
    int i;
    addressList Adr;

    // ALGORITMA
    P = CheckTurn(*S);
    Adr = First(OwnBuilding(P));
    
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        Troop(ElmtArrDin(Buildings(*S), Info(Adr))) += 5;
        Adr = Next(Adr);
    }

    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}
void Barrage(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Jumlah pasukan dari bangunan PLAYER lawan akan berkurang sejumlah 10 */

    // KAMUS LOKAL
    PLAYER P;
    int i;
    addressList Adr;

    // ALGORITMA
    P = CheckTurn(*S);
    Adr = First(OwnBuilding(P));
    
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        Troop(ElmtArrDin(Buildings(*S), Info(Adr))) = Troop(ElmtArrDin(Buildings(*S), Info(Adr))) - 10;
        Adr = Next(Adr);
    }
    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}

void InitBuildingsTurn (STATE *S)
/* I. S. S terdefinisi
    F. S. Semua Buildings player yang sedang bermain akan bertambah sesuai ketentuan penambahan pada awal turn */
{
    // KAMUS LOKAL
    PLAYER P;
    int i;
    addressList Adr;

    // ALGORITMA
    P = CheckTurn(*S);
    Adr = First(OwnBuilding(P));
    
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        InitTurn(&ElmtArrDin(Buildings(*S), Info(Adr)));
        Adr = Next(Adr);
    }
    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}
