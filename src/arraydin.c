/* 
Nama	: Annisa Ayu Pramesti
NIM 	: 13518085
Tanggal	: 10 September 2019
Topik	: Array Dinamik
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeArrDinEmpty(TabBuilding *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    Neff(*T) = 0;
    MaxElement(*T) = maxel;
    TI(*T) = (ElTypeArrDin *) malloc((maxel+1) * sizeof(ElTypeArrDin));    
}

void DealokasiArrDin(TabBuilding *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElement(T)=0; Neff(T)=0 */
{
    Neff(*T) = 0;
    MaxElement(*T) = 0;
    free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrDIn(TabBuilding T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}


/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBuilding T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabBuilding T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T) + IdxMin - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrDin(TabBuilding T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= GetFirstIdx(T)) && (i <= MaxElement(T)));
}

boolean IsIdxEffArrDin(TabBuilding T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsArrDinEmpty(TabBuilding T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsArrDinFull(TabBuilding T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxElement(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void TulisIsiTab(TabBuilding T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    printf("Daftar bangunan yang ada: \n");
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        printf("%d. ", i);
        switch (Kind(ElmtArrDin(T, i)))
        {
        case 'C':
            printf("Castle ");
            break;
        case 'T':
            printf("Tower ");
            break;
        case 'F':
            printf("Fort ");
            break;
        case 'V':
            printf("Village ");
            break;
        default:
            break;
        } 
        TulisPOINT(Pos(ElmtArrDin(T, i)));
        printf(" %d lv. %d", Troop(ElmtArrDin(T, i)), Level(ElmtArrDin(T, i)));
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabBuilding *T, ElTypeArrDin X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (IsArrDinEmpty(*T)) {
        Kind(ElmtArrDin(*T, GetFirstIdx(*T))) = Kind(X);
        Owner(ElmtArrDin(*T, GetFirstIdx(*T))) = Owner(X);
        Troop(ElmtArrDin(*T, GetFirstIdx(*T))) = Troop(X);
        Level(ElmtArrDin(*T, GetFirstIdx(*T))) = Level(X);
        A(ElmtArrDin(*T, GetFirstIdx(*T))) = A(X);
        M(ElmtArrDin(*T, GetFirstIdx(*T))) = M(X);
        P(ElmtArrDin(*T, GetFirstIdx(*T))) = P(X);
        U(ElmtArrDin(*T, GetFirstIdx(*T))) = U(X);
        Absis(Pos(ElmtArrDin(*T, GetFirstIdx(*T)))) = Absis(Pos(X));
        Ordinat(Pos(ElmtArrDin(*T, GetFirstIdx(*T)))) = Ordinat(Pos(X));

    } else {
        Kind(ElmtArrDin(*T, GetLastIdx(*T)+1)) = Kind(X);
        Owner(ElmtArrDin(*T, GetLastIdx(*T)+1)) = Owner(X);
        Troop(ElmtArrDin(*T, GetLastIdx(*T)+1)) = Troop(X);
        Level(ElmtArrDin(*T, GetLastIdx(*T)+1)) = Level(X);
        A(ElmtArrDin(*T, GetLastIdx(*T)+1)) = A(X);
        M(ElmtArrDin(*T, GetLastIdx(*T)+1)) = M(X);
        P(ElmtArrDin(*T, GetLastIdx(*T)+1)) = P(X);
        U(ElmtArrDin(*T, GetLastIdx(*T)+1)) = U(X);
        Absis(Pos(ElmtArrDin(*T, GetLastIdx(*T)+1))) = Absis(Pos(X));
        Ordinat(Pos(ElmtArrDin(*T, GetLastIdx(*T)+1))) = Ordinat(Pos(X));
    }
    Neff(*T)++;
}

IdxType getIdx(TabBuilding T, POINT P)
/* mengembalikan indeks X berdasarkan posisi, P pasti ada di TabBuilding */
{
    boolean found = false;
    IdxType i = 1;
    while (!found && i <= MaxElement(T)) {
        if (EQPoint(Pos(ElmtArrDin(T, i)), P)) found = true;
        else i++;
    }
    return i;
}