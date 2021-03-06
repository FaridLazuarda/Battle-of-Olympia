#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxelStackt */
/* jadi indeksnya antara 1.. MaxelStackt+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai NilStackt */
{
    Top(*S) = NilStackt; 
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == NilStackt);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxelStackt);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmpty(*S)){
        Top(*S) = 1;
    } else {
        Top(*S)++;
    }
    CopyState(X, &InfoTop(*S));
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    CopyState(InfoTop(*S), X);
    Top(*S)--;
}
