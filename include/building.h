/* ********** Definisi TYPE BUILDING ********** */

#ifndef BUILDING_H
#define BUILDING_H

#include "boolean.h"
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define LvlMin 1
#define LvlMax 4
#define TroopsMax 1000000

typedef struct {
    char Kind; /* C untuk castle, T untuk Tower, F untuk Fort, V untuk Village */
    int Troop; /* banyaknya pasukan yang menempati bangunan, tidak lebih dari TroopsMax */
    int Level; /* menandakan level dari bangunan [1..4] */
    int A; /* penambahan pasukan pada awal giliran */
    int M; /* maksimal penambahan pasukan */
    boolean P; /* true jika bangunan memiliki pertahanan, false jika tidak */
    boolean hasMove;
    boolean hasAttack; /* true jika bangunan telah attack pada turn yang sama, false jika belum */
    int U; /* jumlah pasukan awal yang harus dikalahkan untuk menjadikan bangunan ini milik pemain */
    POINT Pos; /* posisi bangunan di peta */
} BUILDING;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Selektor *** */
#define Kind(B) (B).Kind
#define Troop(B) (B).Troop
#define Level(B) (B).Level
#define A(B) (B).A
#define M(B) (B).M
#define P(B) (B).P
#define U(B) (B).U
#define Pos(B) (B).Pos
#define hasMove(B) (B).hasMove
#define hasAttack(B) (B).hasAttack

/* ********* Prototype ********* */
boolean IsOwned (BUILDING B);
/* Mengembalikan true jika B dimiliki oleh suatu pemain */
boolean IsTroopFull (BUILDING B); 
/* Mengembalikan true jika jumlah pasukan sudah sama dengan M */

/* *** Konstruktor *** */
void InitGame (BUILDING * B, int X, char K, POINT position);
/* I. S. BUILDING B sembarang */
/* F. S. BUILDING B terdefinisi dengan Owner X dan jenis K seperti level 1 */

/* *** Fungsi Lain *** */
void InitTurn (BUILDING * B);
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B akan bertambah pasukannya sebanyak A pada awal giliran */
/* Penambahan tidak dilakukan jika pasukan sudah lebih dari atau sama dengan M */
/* Penambahan disesuaikan dengan jenis BUILDING */
void LevelUp (BUILDING * B);
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B levelnya naik */
/* Deskripsi level (sesui jenis building) ada di spek tubes */
/* untuk naik level harus ada minimal pasukan sebanyak M/2 untuk dikurangi sebagai ganti naik level */

void PrintInfoBuilding (BUILDING B);
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B diprint dengan format:
   jenis :
   pemilik :
   banyak pasukan :
   level :
   penambahan pasukan :
   maks penambahan pasukan :
   pertahanan : ada/tidak
   jml pasukan untuk ambil alih :
*/




#endif