#include <stdio.h>
#include <stdlib.h>
#include "../include/arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
    TI(*T) = (ElType *) malloc((maxel+1) * sizeof(ElType));    
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    Neff(*T) = 0;
    MaxEl(*T) = 0;
    free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T) + IdxMin - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= GetFirstIdx(T)) && (i <= MaxElement(T)));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxElement(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    IdxType i, n;
    scanf("%d", &n);
    while ((n < 0) || (n > MaxElement(*T))){
        scanf("%d", &n);
    }
    if (n == 0) { /* jika tabel kosong */
        Neff(*T) = 0;
    } else { /* jika tabel tidak kosong */
        Neff(*T) = 0;
        for (i = IdxMin; i < n+IdxMin; i++){
            scanf("%d", &Elmt(*T, i));
        }
        Neff(*T) = n;
    }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i;
    printf("[");
    if (!(IsEmpty(T))) {
        /* print dulu sebelum last element */
        for (i = GetFirstIdx(T); i < GetLastIdx(T); i++){
            printf("%d,", Elmt(T,i));
        }
        // print last element
        printf("%d", Elmt(T, GetLastIdx(T)));
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    IdxType i;
    TabInt T;
    MakeEmpty(&T, MaxEl(T1));
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        if (plus) Elmt(T,i) = Elmt(T1, i) + Elmt(T2, i);
        else Elmt(T,i) = Elmt(T1, i) - Elmt(T2, i);
    }
    Neff(T) = Neff(T1);
    return T;
    Dealokasi(&T);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    ElType i;
    if (Neff(T1) != Neff(T2)) { // jika jumlah elemennya gak sama
        return false;
    } else { /* jika jumlah elemennya sama, cek isinya */
        for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
            if (Elmt(T1, i) != Elmt(T2, i)) {
                return false;
            }
        }
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType i;
    if (IsEmpty(T)) {
        return IdxUndef;
    } else { /* tabel T tidak kosong */
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            if (Elmt(T, i) == X) {
                return i;
            }
        }
        return IdxUndef;
    }
}
boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    IdxType i = Search1(T, X);
    return (i != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    IdxType i;
    ElType mx = Elmt(T, GetFirstIdx(T));
    ElType mn = Elmt(T, GetFirstIdx(T)); 
    for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) > mx) {
            mx = Elmt(T, i);
        }
    }
    for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) < mn) {
            mn = Elmt(T, i);
        }
    }
    *Max = mx;
    *Min = mn;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    IdxType i;
    MakeEmpty(Tout, MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    ElType sum;
    IdxType i;
    if (IsEmpty(T)) {
        return 0;
    } else {
        sum = 0;
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            sum += Elmt(T, i);
        }
        return sum;
    }
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i;
    int count;
    if (IsEmpty(T)) {
        return 0;
    } else {
        count = 0;
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            if (Elmt(T, i) == X) count++;
        }
        return count;
    }
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    IdxType i;
    if (IsEmpty(T)) {
        return false;
    } else {
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            if (Elmt(T, i) % 2 == 1) return false;
        }
    }
    return true;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    IdxType i, j, imax;
    ElType temp;
    if (Neff(*T) > 1) {
        if (!asc) {
            for (i = GetFirstIdx(*T); i <= GetLastIdx(*T)-1; i++) {
                imax = i;
                for (j = i+1; j <= GetLastIdx(*T); j++) {
                    if (Elmt(*T, j) > Elmt(*T, imax)) {
                        imax = j;
                    }
                }
                temp = Elmt(*T, i);
                Elmt(*T, i) = Elmt(*T, imax);
                Elmt(*T, imax) = temp;
            }
        } else {
            for (i = GetFirstIdx(*T)+1; i <= GetLastIdx(*T); i++){
                temp = Elmt(*T, i);
                j = i-1;
                while ((temp < Elmt(*T, j)) && (j >= 1)){
                    Elmt(*T, j+1) = Elmt(*T, j);
                    j--;
                } 
                Elmt(*T, j+1) = temp;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (IsEmpty(*T)) {
        Elmt(*T, GetFirstIdx(*T)) = X;  
    } else {
        Elmt(*T, GetLastIdx(*T)+1) = X;
    }
    Neff(*T)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    TI(*T) = (ElType *) realloc(TI(*T), (MaxEl(*T)+1+num) * sizeof(ElType));
    MaxEl(*T) = MaxEl(*T) + num;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    TI(*T) = (ElType *) realloc(TI(*T), (MaxEl(*T)+1-num) * sizeof(ElType));
    MaxEl(*T) = MaxEl(*T) - num;
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    TI(*T) = (ElType *) realloc(TI(*T), (Neff(*T)+1) * sizeof(ElType));
    MaxEl(*T) = Neff(*T);
}