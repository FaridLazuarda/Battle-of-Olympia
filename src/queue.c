#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

/* ********* Prototype ********* */
boolean IsQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == 0);
}
boolean IsQueueFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxelQueue */ 
{
    return (NBElmt(Q) == MaxelQueue(Q));
}
int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (Tail(Q) < Head(Q)) {
        return (MaxelQueue(Q) - (Head(Q) - Tail(Q)) + 1);
    } else if (Tail(Q) == Head(Q)) {
        if (Tail(Q) == Nil) {
            return 0;
        } else return 1;
    } else {
        return (Tail(Q) - Head(Q) + 1);
    }
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxelQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotypequeue *) malloc ((Max+1) * sizeof(infotypequeue));
    if ((*Q).T != NULL) {
        MaxelQueue(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxelQueue(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxelQueue(Q) diset 0 */
{
    MaxelQueue(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotypequeue X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else {
        if (Tail(*Q) == MaxelQueue(*Q)) {
            Tail(*Q) = 1;
        } else Tail(*Q)++;
    }
    InfoTail(*Q) = X;
}
void Del (Queue * Q, infotypequeue * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if (Head(*Q) == MaxelQueue(*Q)) {
            Head(*Q) = 1;
        } else {
            Head(*Q)++;
        }
    }
}