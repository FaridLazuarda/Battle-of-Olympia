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


void ATTACK(STATE *S, boolean AttUp, boolean CritHit, Graph G){
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */

    /* KAMUS LOKAL */
    PLAYER P, enemyP;
    infotypeList inputAttBuilding, inputBuildToAtt;
    IdxType idxAttBuilding, idxBuildToAtt;
    int attTroop, i , j;
    BUILDING attBuild, buildToAtt;
    addressList adrPlayer, adrEnemy;
    addressGraph adrGraphBuilding;

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
    scanf("%d", &inputAttBuilding);
    adrPlayer = First(OwnBuilding(P));
    for (i = 1; i < inputAttBuilding; i++) {
        adrPlayer = Next(adrPlayer);
    }
    idxAttBuilding = Info(adrPlayer);
    attBuild = ElmtArrDin(Buildings(*S), idxAttBuilding);
    printf("%c\n", Kind(attBuild));

    /* Pilih bangunan untuk diserang */
    printf("Daftar bangunan yang dapat diserang\n");
    PrintDaftarBangunanTerhubung(*S, Info(adrPlayer), G, true);
    printf("Bangunan yang diserang: ");
    scanf("%d", &inputBuildToAtt);
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
    buildToAtt = ElmtArrDin(Buildings(*S), idxBuildToAtt);
    printf("%c\n", Kind(buildToAtt));


    /* Menentukan jumlah pasukan */
    printf("Jumlah pasukan: ");
    scanf("%d", &attTroop);
    /************ TAMBAHIN VALIDASI ************/
    
    /* Step Attack */
    printf("Player troop before attack: %d\n", Troop(attBuild));
    printf("Enemy troop before attack: %d\n", Troop(buildToAtt));
    Troop(attBuild) = Troop(attBuild) - attTroop;
    if (attTroop >= Troop(buildToAtt)) {
        if (Search(OwnBuilding(enemyP), idxBuildToAtt)) {
            /* Kalo buildingnya belom ada yang punya */
            DelP(&OwnBuilding(enemyP), idxBuildToAtt);
        }
        InsVLast(&OwnBuilding(P), idxBuildToAtt);
        Troop(buildToAtt) = Troop(buildToAtt) - attTroop;
        if (Troop(buildToAtt) < 0) {
            Troop(buildToAtt) = 0;
        }
        Level(buildToAtt) = 1;
    } else {
        Troop(buildToAtt) = Troop(buildToAtt) - attTroop;
    }

    printf("Player troop after attack: %d\n", Troop(attBuild));
    printf("Enemy troop after attack: %d\n", Troop(buildToAtt));

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

    printf("Bangunan yang akan di level-up:");
    scanf("%d", &buildLvlUp);
    for (i = 1; i < buildLvlUp; i++) {
        Adr = Next(Adr);
    }
    if (Troop(ElmtArrDin(Buildings(*S), Info(Adr))) >= M(ElmtArrDin(Buildings(*S), Info(Adr)))/2){
        Level(ElmtArrDin(Buildings(*S), Info(Adr)))++;
        M(ElmtArrDin(Buildings(*S), Info(Adr))) = Troop(ElmtArrDin(Buildings(*S), Info(Adr))) - Troop(ElmtArrDin(Buildings(*S), Info(Adr)))/2;
    } else{
        printf("Jumlah pasukan Castle kurang untuk level up");
    }

    if (IsTurn(P1(*S))) {
        P1(*S) = P;
    } else {
        P2(*S) = P;
    }
}
void MOVE(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang menggunakan skill ini memindahkan sejumlah pasukan dari 1 bangunan ke bangunan yang lain
            yang terhubung */

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
        Level(ElmtArrDin(Buildings(*S), Info(Adr)))++;
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
    IsShieldAvailable = true;
    
    if (IsEqual(P, P2(*S))){;
        countshield++;
        if (countshield == 2){
            IsShieldAvailable = false;
        }
    } else{
        IsShieldAvailable = false;
    }
}
void ExtraTurn(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Player yang menggunakan skill ini akan mendapatkan turn tambahan */

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