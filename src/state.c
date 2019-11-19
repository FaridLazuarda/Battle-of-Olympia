#include "../include/state.h"
#include <stdio.h>


void CreateEmptyState (STATE *S)
/* State terbentuk dengan init player 1 dan 2, dan empty array building */
{
    InitPlayer(&P1(*S), 1);
    InitPlayer(&P2(*S), 2);
    MakeArrDinEmpty(&Buildings(*S), 600);
}

void PrintDaftarBangunan(STATE S){
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


void ATTACK(STATE *S, boolean AttUp, boolean CritHit){
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */


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
void MOVE(STATE *S)
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang menggunakan skill ini memindahkan sejumlah pasukan dari 1 bangunan ke bangunan yang lain
            yang terhubung */
{
    //KAMUS LOKAL
    int nomorBangunan;
    addressList P;
    int iter;

    //ALGORITMA
    printf("Daftar Bangunan : \n");
    P = First(OwnBuilding(P1(*S)));


    printf("Pilih Bangunan : ");
    scanf("%d", &nomorBangunan);

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