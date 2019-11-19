#include "../include/state.h"
#include <stdio.h>


void CreateEmptyState (STATE *S)
/* State terbentuk dengan init player 1 dan 2, dan empty array building */
{
    InitPlayer(&P1(*S), 1);
    InitPlayer(&P2(*S), 2);
    MakeArrDinEmpty(&Buildings(*S), 600);
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
}

void PrintDaftarBangunanPlayer(STATE S){
/*  I. S.   P terdefinisi
    F. S.   Mencetak jenis, posisi, jumlah pasukan, dan level dari tiap bangunan yang dimiliki oleh P */

    // KAMUS LOKAL
    int i;
    addressList Adr;
    PLAYER P;

    // ALGORITMA
    P = CheckTurn(S);
    Adr = First(OwnBuilding(P));
    printf("Daftar bangunan:\n");
    // jenis, lokasi, jumlah pasukan, level
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        printf("%d. ", i);
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


void ATTACK(STATE *S, Graph G){
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */

    /* KAMUS LOKAL */
    PLAYER P, enemyP;
    infotypeList inputAttBuilding, inputBuildToAtt;
    IdxType idxAttBuilding, idxBuildToAtt;
    int attTroop, i , j, towerCount;
    addressList adrPlayer, adrEnemy, iterateTowerCount;
    addressGraph adrGraphBuilding;
    boolean CritHit, AttUp, ShieldCount;

    /* ALGORITMA */
    P = CheckTurn(*S);
    if (IsTurn(P1(*S))) {
        enemyP = P2(*S);
    } else {
        enemyP = P1(*S);
    }

    /* Pilih bangunan untuk menyerang */
    PrintDaftarBangunanPlayer(*S);
    printf("Bangunan yang digunakan untuk menyerang: ");
    STARTKATA();
    inputAttBuilding = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        inputAttBuilding = inputAttBuilding * 10 + (CKata.TabKata[j] - '0');
    }
    adrPlayer = First(OwnBuilding(P));
    for (i = 1; i < inputAttBuilding; i++) {
        adrPlayer = Next(adrPlayer);
    }
    idxAttBuilding = Info(adrPlayer);

    /* Pilih bangunan untuk diserang */
    printf("Daftar bangunan yang dapat diserang\n");
    PrintDaftarBangunanTerhubung(*S, Info(adrPlayer), G, true);
    printf("Bangunan yang diserang: ");
    STARTKATA();
    inputBuildToAtt = 0;
    for (int j = 1; j <= CKata.Length; j++) {
        inputBuildToAtt = inputBuildToAtt * 10 + (CKata.TabKata[j] - '0');
    }
    adrGraphBuilding = SearchGraph(G, Info(adrPlayer));
    adrEnemy = First(Link(adrGraphBuilding));
    /* Menangani kasus apabila pick 1, dan di link building first adalah building milik sendiri */
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
        attTroop = (attTroop * 3) / 4;
    }
    printf("Final attack troop: %d\n", attTroop);
    if (attTroop >= Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt))) {
        if (Search(OwnBuilding(enemyP), idxBuildToAtt)) {
            /* Kalo buildingnya belom ada yang punya */
            DelP(&OwnBuilding(enemyP), idxBuildToAtt);
        }
        InsVLast(&OwnBuilding(P), idxBuildToAtt);
        
        Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = attTroop - Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt));
        if (CritHit) {
            Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) /= 2;
        }

        if (NbElmt(OwnBuilding(P)) == 10) {
            printf("testing add B\n");
            AddSkill(&enemyP, 'B');
            printf("%c\n", InfoTail(Skill(enemyP)));
        }

        if (Kind(ElmtArrDin(Buildings(*S), idxBuildToAtt)) == 'T') {
            /* Kondisi untuk mendapat skill Attack Up */
            towerCount = 0;
            iterateTowerCount = First(OwnBuilding(P));
            if (!IsListEmpty(OwnBuilding(P))) {
                while (iterateTowerCount != NULL) {
                    if (Kind(ElmtArrDin(Buildings(*S), Info(iterateTowerCount))) == 'T') {
                        towerCount++;
                    }
                    iterateTowerCount = Next(iterateTowerCount);
                }
            }

            if (towerCount == 3) {
                printf("testing add A\n");
                AddSkill(&P, 'A');
                printf("%c\n", InfoTail(Skill(P)));
            }
        }

        if ((NbElmt(OwnBuilding(enemyP)) == 2) && (Search(OwnBuilding(enemyP), idxBuildToAtt))) {
            /* Kondisi untuk mendapat skill Shield */
            printf("testing add S\n");
            AddSkill(&enemyP, 'S');
            printf("%c\n", InfoTail(Skill(enemyP)));
        } 

        if (Kind(ElmtArrDin(Buildings(*S), idxBuildToAtt)) == 'F') {
            /* Kondisi untuk mendapat skill Extra Turn */
            printf("testing add E\n");
            AddSkill(&enemyP, 'E');
            printf("%c\n", InfoTail(Skill(enemyP)));
            Level(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = 1;
            printf("Bangunan menjadi milikmu!\n");
        }
    } else {
        Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) = Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)) - attTroop;
        printf("Bangunan gagal direbut\n");
    }

    printf("Player troop after attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxAttBuilding)));
    printf("Opposite Building troop after attack: %d\n", Troop(ElmtArrDin(Buildings(*S), idxBuildToAtt)));

    if (IsTurn(P1(*S))) {
        P1(*S) = P;
        P2(*S) = enemyP;
    } else {
        P2(*S) = P;
        P1(*S) = enemyP;
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
    LevelUp(&ElmtArrDin(Buildings(*S), Info(Adr)));

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
    addressList addrPlayer;
    addressGraph addrGraphBuilding;

    /* Pilih bangunan untuk move */
    PrintDaftarBangunanPlayer(*S);
    printf("Pilih bangunan: ");
    scanf("%d", &inputMoveBuilding);
    addrPlayer = First(OwnBuilding(P));
    for (i = 1; i < inputMoveBuilding; i++) {
        addrPlayer = Next(addrPlayer);
    }
    idxMoveBuilding = Info(addrPlayer);
    moveBuild = ElmtArrDin(Buildings(*S), idxMoveBuilding);
    printf("%c\n", Kind(moveBuild));

    /* Pilih bangunan tujuan move */
    printf("Daftar bangunan terdekat:\n");
    PrintDaftarBangunanTerhubung(*S, Info(addrPlayer), G, true);
    printf("Bangunan yang akan menerima: ");
    scanf("%d", &inputBuildToMove);
    addrGraphBuilding = SearchGraph(G, Info(addrPlayer));
    addrPlayer = First(Link(addrGraphBuilding));

    j = 1;
    while (j < inputBuildToMove) {
        if (Search(OwnBuilding(P), Info(addrPlayer)) != Nil) {
            /* Skip bangunan milik sendiri */
            addrPlayer = Next(addrPlayer);
        } else {
            addrPlayer = Next(addrPlayer);
            j++;
        }
    }
    idxBuildingToMove = Info(addrPlayer);
    buildToMove = ElmtArrDin(Buildings(*S), idxBuildingToMove);
    printf("%c\n", Kind(buildToMove));

    /* Menentukan jumlah pasukan */
    printf("Jumlah pasukan: ");
    scanf("%d", &movetroop);
    if(movetroop < Troop(moveBuild)){
        Troop(buildToMove) = Troop(buildToMove) + movetroop;
        Troop(moveBuild) = Troop(moveBuild) - movetroop;
    } else if(movetroop < Troop(moveBuild)){
        printf("Gacukup bray");
    }
    printf("%d", movetroop);
    printf(" pasukan dari ");
    if(Kind(moveBuild) == 'T'){
        printf("Tower ");
    }else if(Kind(moveBuild) == 'C'){
        printf("Castle ");
    }else if(Kind(moveBuild) == 'V'){
        printf("Village ");
    }else if(Kind(moveBuild) == 'F'){
        printf("Fort ");
    }
    // TulisPOINT(Pos(movetroop));
    printf(" telah berpindah ke ");
    if(Kind(buildToMove) == 'T'){
        printf("Tower ");
    }else if(Kind(buildToMove) == 'C'){
        printf("Castle ");
    }else if(Kind(buildToMove) == 'V'){
        printf("Village ");
    }else if(Kind(buildToMove) == 'F'){
        printf("Fort ");
    }
    TulisPOINT(Pos(buildToMove));
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
        LevelUp(&ElmtArrDin(Buildings(*S), Info(Adr)));
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
}


void CriticalHit(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang
            setengah dari jumlah seharusnya */

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
}