/**************** DEFINISI TYPE STATE ****************/

#ifndef STATE_H
#define STATE_H

#include "building.h"
#include "player.h"
#include "listlinier.h"
#include "arraydin.h"
#include "point.h"
#include "graph.h"
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

void CopyState (STATE In, STATE * Out);

PLAYER CheckTurn(STATE S);
/*  Mengembalikan PLAYER yang sedang menjalankan turn, yaitu yang IsTurn = true */

void PrintDaftarBangunanTerhubung(STATE S, infotypeList X, Graph G, boolean attack, boolean move);

void PrintDaftarBangunanPlayer(STATE S, boolean attack, boolean move);
/*  I. S.   P terdefinisi
    F. S.   Mencetak jenis, posisi, jumlah pasukan, dan level dari tiap bangunan yang dimiliki oleh P */

boolean canAttack(STATE S);
    /*  Mengembalikan apakah PLAYER yang sedang menjalankan turn dapat menggunakan command ATTACK,
        yaitu apabila semua bangunan telah melancarkan attack atau jumlah troop = 0.
        Apabila ada satu bangunan saja yang tidak memenuhi kedua bangunan tersebut, akan dikembalikan true. 
        Jika tidak ada, maka false */

boolean canMove(STATE S);
    /*  Mengembalikan apakah PLAYER yang sedang menjalankan turn dapat menggunakan command MOVE,
        yaitu apabila semua bangunan telah melancarkan move atau jumlah troop = 0.
        Apabila ada satu bangunan saja yang tidak memenuhi kedua bangunan tersebut, akan dikembalikan true. 
        Jika tidak ada, maka false */

void ATTACK(STATE *S, Graph G);
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */

void LEVEL_UP(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Apabila bangunan yang dipilih PLAYER yang sedang melaksanakan turn memiliki jumlah pasukan >= M/2,
            maka level bangunan akan bertambah 1 dan pasukan berkurang sejumlah M/2.
            Apabila bangunan tidak memiliki jumlah pasukan >= M/2, maka akan ditampilkan pesan dan I. S. = F. S. */

void MOVE(STATE *S, Graph G);
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

boolean InsReinCheck (STATE S);
/* mengembalikan true jika seluruh bangunan player memiliki level 4 */

void InstantReinforcement(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang memiliki skill ini akan mendapat tambahan 5 pasukan */

void Barrage(STATE *S);
/*  I. S.   S terdefinisi
    F. S.   Jumlah pasukan dari bangunan PLAYER lawan akan berkurang sejumlah 10 */

void InitBuildingsTurn (STATE *S);
/* I. S. S terdefinisi
    F. S. Semua Buildings player yang sedang bermain akan bertambah sesuai ketentuan penambahan pada awal turn */

#endif