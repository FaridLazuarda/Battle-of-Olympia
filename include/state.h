/**************** DEFINISI TYPE STATE ****************/

#ifndef STATE_H
#define STATE_H

#include "building.h"
#include "player.h"
#include "listlinier.h"
#include "arraydin.h"
#include "point.h"
#include "mesinkata.h"


/* Definisi elemen dan koleksi objek */
typedef struct {
    PLAYER Player1;
    PLAYER Player2;
    TabBuilding Buildings;
} STATE;

/* ********** SELEKTOR ********** */
#define P1(S)    (S).Player1
#define P2(S)    (S).Player2
#define Buildings(S)   (S).Buildings

void CreateEmptyState (STATE *S);
/* State terbentuk dengan init player 1 dan 2, dan empty array building */

PLAYER CheckTurn(STATE S);
/*  Mengembalikan PLAYER yang sedang menjalankan turn, yaitu yang IsTurn = true */

void PrintDaftarBangunan(STATE S);
/*  I. S.   P terdefinisi
    F. S.   Mencetak jenis, posisi, jumlah pasukan, dan level dari tiap bangunan yang dimiliki oleh P */

void ATTACK(STATE *S, boolean AttUp, boolean CritHit);
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */

void LEVEL_UP(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Apabila bangunan yang dipilih PLAYER yang sedang melaksanakan turn memiliki jumlah pasukan >= M/2,
            maka level bangunan akan bertambah 1 dan pasukan berkurang sejumlah M/2.
            Apabila bangunan tidak memiliki jumlah pasukan >= M/2, maka akan ditampilkan pesan dan I. S. = F. S. */

void MOVE(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang menggunakan skill ini memindahkan sejumlah pasukan dari 1 bangunan ke bangunan yang lain
            yang terhubung */

void InstantUpgrade(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, seluruh bangunannya akan bertambah 1 level */

void Shield(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, akan memiliki pertahanan selama 2 turn.
            Apabila digunakan 2 kali berturut-turut, durasi tidak akan bertambah namun akan menjadi nilai maksimum */

void ExtraTurn(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Player yang menggunakan skill ini akan mendapatkan turn tambahan */

void AttackUp(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Pada turn ini, bangunan PLAYER lawan yang memiliki pertahanan tidak akan mempengaruhi penyerangan */

void CriticalHit(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang
            setengah dari jumlah seharusnya */

void InstantReinforcement(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang memiliki skill ini akan mendapat tambahan 5 pasukan */

void Barrage(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Jumlah pasukan dari bangunan PLAYER lawan akan berkurang sejumlah 10 */

#endif