/* Implementasi array.h */

#include <stdio.h>
#include "../include/array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabBuilding * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Semua elemen kosong diassign dengan jenis building yang U (undefined) dan owner 0*/
    BUILDING B;
    IdxType i;
    for ( i = IdxMin; i <= IdxMax; i++) {
        InitGame(&(Elmt(*T, i)), 0, 'U');
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabBuilding T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    IdxType i = IdxMin;
    boolean found = false;
    while (i <= IdxMax && !found) {
        if (Kind(Elmt(T,i)) == 'U') found = false;
        else i++;
    }
    return i-1;
}
int MaxNbEl (TabBuilding T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
    return (IdxMax-IdxMin+1);
}
IdxType GetFirstIdx (TabBuilding T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxType GetLastIdx (TabBuilding T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return (NbElmt(T) + IdxMin - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabBuilding T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= GetFirstIdx(T)) && (i <= MaxNbEl(T)));
}
boolean IsIdxEff (TabBuilding T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsArrEmpty (TabBuilding T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
    return (NbElmt(T) == 0);
}

boolean IsArrFull (TabBuilding T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NbElmt(T) == MaxNbEl(T));
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabBuilding * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (IsArrEmpty(*T)) {
        Elmt(*T, GetFirstIdx(*T)) = X;  
    } else {
        Elmt(*T, GetLastIdx(*T)+1) = X;
    }
}
void AddEli (TabBuilding * T, ElType X, IdxType i){
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
    IdxType j;
    IdxType last = GetLastIdx(*T);
    if (i > last) {
        Elmt(*T, i) = X;
    } else {
        for (j = last; j >= i; j--) {
            Elmt(*T, j+1) = Elmt(*T, j);
        }
        Elmt(*T, i) = X;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabBuilding * T, ElType * X) {
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    IdxType last = GetLastIdx(*T);
    *X = Elmt(*T, last);
    InitGame(&(Elmt(*T, last)), 0, 'U'); //assign jadi undef
}
void DelEli (TabBuilding * T, IdxType i, ElType * X){
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
    IdxType j;
    IdxType last;
    *X = Elmt(*T, i);
    if (i < last) {
        for (j = i; j <= last-1; j++) {
            Elmt(*T, j) = Elmt(*T, j+1);
        }
    }
    InitGame(&(Elmt(*T, last)), 0, 'U'); //assign jadi undef
}
