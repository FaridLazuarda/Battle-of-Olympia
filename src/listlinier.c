#include <stdio.h>
#include <stdlib.h>
#include "../include/listlinier.h"
<<<<<<< HEAD
=======

>>>>>>> 7d50062bb2519e6529a3ed0d790d4e1599594444
/* Definisi list : */
/* List kosong : First(L) = NULL */
/* Setiap elemen dengan addressList P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=NULL */

// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X)
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    addressList P;
    P = NULL;
    P = (ElmtList *) malloc (sizeof(ElmtList));
    if (P != NULL) {
        Info(P) = X;
        Next(P) = NULL;
    }
    return P;
}
void Dealokasi (addressList *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
{
    free(*P);
    *P = NULL;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotypeList X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    // addressList P = First(L);
    // boolean found = false;
    // while (P != NULL && !found) {
    //     if (Info(P) == X) found = true;
    //     else P = Next(P);
    // }
    // return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressList P;
    if (IsListEmpty(*L)) {
        First(*L) = Alokasi(X);
    } else {
        P = Alokasi(X);
        if (P != NULL) {
            Next(P) = First(*L);
            First(*L) = P;
        }
    }
}
void InsVLast (List *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressList P, c;
    if (IsListEmpty(*L)) {
        First(*L) = Alokasi(X);
    } else {
        P = First(*L);
        while (Next(P) != NULL){
            P = Next(P);            
        }
        // kalo udah nemu yang nil
        c = Alokasi(X);
        Next(P) = c;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressList P = First(*L);
    *X = Info(First(*L));
    First(*L) = Next(First(*L));
    Dealokasi(&P);
}

void DelVLast (List *L, infotypeList *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressList P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
{
    if (IsListEmpty(*L)) {
        First(*L) = P;
        Next(First(*L)) = NULL;
    } else {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsertAfter (List *L, addressList P, addressList Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    addressList c = First(*L);
    while (c != Prec) {
        c = Next(c);
    }
    // c = Prec
    Next(P) = Next(c);
    Next(c) = P;
}
void InsertLast (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{   
    addressList c = First(*L);
    if (c == NULL) {
        First(*L) = P;
        Next(First(*L)) = NULL;
    } else {
        while (Next(c) != NULL) {
            c = Next(c);
        }
        Next(c) = P;
        Next(P) = NULL;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}
void DelP (List *L, infotypeList X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // addressList N;
    // addressList P = First(*L);
    // boolean found = false;
    // while (P != NULL && !found) {
    //     if (Info(P) == X) found = true;
    //     else P = Next(P);
    // }
    // if (found) {
    //     if (P == First(*L)) {
    //         First(*L) = Next(First(*L));
    //     } else {
    //         N = First(*L);
    //         while (Next(N) != P) {
    //             N = Next(N);
    //         }
    //         Next(N) = Next(P);
    //     }
    //     Dealokasi(&P);
    // }
}
void DelLast (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    addressList c = First(*L);
    addressList last = First(*L);
    while (Next(c) != NULL) {
        c = Next(c);
    }
    *P = c;
    if (c == First(*L)) {
        First(*L) = NULL;
    } else {
        while (Next(last) != c)
        {
            last = Next(last);
        }
        Next(last) = NULL;
    }
}
void DelAfter (List *L, addressList *Pdel, addressList Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    addressList P = First(L);
    printf("[");
    if (!IsListEmpty(L)) {
        printf("%d", Info(P));
        P = Next(P);
        while (P != NULL) {
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    addressList P = First(L);
    if (!IsListEmpty(L)) {
        while (P != NULL) {
            count++;
            P = Next(P);
        }
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeList Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    // infotypeList max = Info(First(L));
    // addressList P = First(L);
    // while (P != NULL) {
    //     if (max < Info(P)) max = Info(P);
    //     P = Next(P);
    // }
    // return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    addressList P = First(*L1);
    if (P == NULL) {
        First(*L3) = First(*L2);
    } else {
        while (Next(P) != NULL) {
            P = Next(P);
        }
        First(*L3) = First(*L1);
        Next(P) = First(*L2);
    }
    First(*L1) = NULL;
    First(*L2) = NULL;
}