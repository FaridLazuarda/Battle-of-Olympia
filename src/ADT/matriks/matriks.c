#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */ 
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return BrsMin + NBrsEff(M) - 1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return KolMin + NKolEff(M) - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M, i, i);
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
    for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M)+2; i++) {
        printf("*");
    }
    printf("\n");
    for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
        printf("*");
        for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) != 'X') printf("%c", Elmt(M, i, j));
            else printf(" ");
        }
        if (Elmt(M, i, GetLastIdxKol(M)) != 'X') printf("%c*\n", Elmt(M, i, GetLastIdxKol(M)));
        else printf(" *\n");
    }
    printf("*");
    for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
        if (Elmt(M, GetLastIdxBrs(M), j) != 'X') printf("%c", Elmt(M, GetLastIdxBrs(M), j));
        else printf(" ");
    }
    if (Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)) != 'X') printf("%c*\n", Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)));
    else printf(" *\n");
    for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M)+2; i++) {
        printf("*");
    }
    printf("\n");
}

