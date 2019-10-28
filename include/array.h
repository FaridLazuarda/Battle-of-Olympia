/* MODUL TABEL BUILDING */
/* Berisi definisi dan semua primitif pemrosesan tabel bangunan */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, 
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "building.h"

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef BUILDING ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabBuilding;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabBuilding, cara deklarasi dan akses: */
/* Deklarasi : T : TabBuilding */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff 
  Elemen dari arraynya selalu kontigu rata kiri ya biar ga ribet*/
  
/* ********** SELEKTOR ********** */
#define Neff(T)     (T).Neff
#define TI(T)       (T).TI
#define Elmt(T,i)   (T).TI[(i)]


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabBuilding * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Semua elemen kosong diassign dengan jenis building yang U (undefined) dan owner 0*/

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabBuilding T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabBuilding T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabBuilding T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabBuilding T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabBuilding T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabBuilding T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsArrEmpty (TabBuilding T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsArrFull (TabBuilding T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabBuilding * T, ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabBuilding * T, ElType X, IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabBuilding * T, ElType * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabBuilding * T, IdxType i, ElType * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

#endif