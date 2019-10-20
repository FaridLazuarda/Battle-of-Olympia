/* 
Nama	: Annisa Ayu Pramesti
NIM 	: 13518085
Tanggal	: 4 September 2019
Topik	: Array Statis
*/

#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return (Neff(T));
}
int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
    return (IdxMax-IdxMin+1);
}
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return (Neff(T) + IdxMin - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= GetFirstIdx(T)) && (i <= MaxNbEl(T)));
}
boolean IsIdxEff (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
    return (Neff(T) == 0);
}

boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (Neff(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    IdxType i, n;
    scanf("%d", &n);
    while ((n < 0) || (n > MaxNbEl(*T))){
        scanf("%d", &n);
    }
    if (n == 0) {
        MakeEmpty(T);
    } else { /* jika tabel tidak kosong */
        Neff(*T) = 0;
        for (i = IdxMin; i < n+IdxMin; i++){
            scanf("%d", &Elmt(*T, i));
        }
        Neff(*T) = n;
    }
}

void BacaIsiTab (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
    ElType n;
    IdxType i = IdxMin;
    Neff(*T) = 0;
    scanf("%d", &n);
    if (n == -9999) {
        MakeEmpty(T);
    } else {
        while (n != -9999 && i <= IdxMax) {
            Elmt(*T, i) = n;
            i++;
            Neff(*T)++;
            scanf("%d", &n);
        }
    }
}

void TulisIsi (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
    IdxType i;
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("[%d]%d\n", i, Elmt(T, i));
        }
    }
}
void TulisIsiTab (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
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
TabInt PlusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    IdxType i;
    TabInt T;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i);
    }
    Neff(T) = Neff(T1);
    return T;
}
TabInt MinusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    IdxType i;
    TabInt T;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i);
    }
    Neff(T) = Neff(T1);
    return T;
}
TabInt KaliTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
    IdxType i;
    TabInt T;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(T, i) = Elmt(T1, i) * Elmt(T2, i);
    }
    Neff(T) = Neff(T1);
    return T;
}
TabInt KaliKons (TabInt Tin, ElType c){
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
    IdxType i;
    TabInt T;
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Elmt(T, i) = Elmt(Tin, i) * c;
    }
    Neff(T) = Neff(Tin);
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
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

boolean IsLess (TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
    ElType i;
    IdxType n = GetLastIdx(T1);
    if (GetLastIdx(T2) < n) n = GetLastIdx(T2);
    for (i = GetFirstIdx(T1); i <= n; i++){
        if (Elmt(T1, i) < Elmt(T2, i)) {
            return true;
        } else if (Elmt(T1, i) > Elmt(T2, i)) {
            return false;
        }
    }
    return Neff(T1) < Neff(T2);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
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
IdxType Search2 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
    IdxType i = 1;
    boolean found = false;
    if (IsEmpty(T)) {
        return IdxUndef;
    } else { // tidak kosong
        while ((!found) && i <= GetLastIdx(T)) {
            if (Elmt(T, i) == X) {
                found = true;
            } else {
                i++;
            }
        }
    }
    if (found) return i;
    else return IdxUndef; /* kalo ga ketemu */
}
boolean SearchB (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
    IdxType i = Search2(T, X);
    return (i != IdxUndef);
    // IdxType i = 1;
    // boolean found = false;
    // if (!(IsEmpty(T))) {
    //     while ((!found) && i != GetLastIdx(T)) {
    //         if (Elmt(T, i) == X) {
    //             found = true;
    //         }
    //         i++;
    //     }
    // }
    // return found;
}
boolean SearchSentinel (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
    IdxType i = GetLastIdx(T);
    Elmt(T, 0) = X;
    while (Elmt(T,i) != X) i--;
    return (i != 0);
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
    ElType mx = Elmt(T, GetFirstIdx(T));
    IdxType i;
    for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) > mx) {
            mx = Elmt(T, i);
        }
    }
    return mx;
}

ElType ValMin (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
    ElType mn = Elmt(T, GetFirstIdx(T));
    IdxType i;
    for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) < mn) {
            mn = Elmt(T, i);
        }
    }
    return mn;
}
IdxType IdxMaxTab (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
    IdxType i = GetFirstIdx(T);
    while (Elmt(T, i) != ValMax(T)) i++;
    return i;
}
IdxType IdxMinTab (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
    IdxType i = GetFirstIdx(T);
    while (Elmt(T, i) != ValMin(T)) i++;
    return i;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
    IdxType i;
    Neff(*Tout) = Neff(Tin);
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}
TabInt InverseTab (TabInt T){
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
    IdxType i = GetFirstIdx(T);
    IdxType j = GetLastIdx(T);
    TabInt k;
    if (Neff(T) > 1) {
        while (i <= GetLastIdx(T)){
            Elmt(k, i) = Elmt(T, j);
            i++;
            j--;
        }
    } else if (Neff(T) == 1){
        Elmt(k,i) = Elmt(T, i);
    }
    Neff(k) = Neff(T);
    return k;
}
boolean IsSimetris (TabInt T){
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
    IdxType i = GetFirstIdx(T);
    IdxType j = GetLastIdx(T);
    if (Neff(T) <= 1){
        return true;
    } else {
        while (i <= (Neff(T)/2)){
            if (Elmt(T, i) != Elmt(T, j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
    IdxType i, j, imax;
    ElType temp;
    if (Neff(*T) > 1) {
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
    }
}
void InsSortAsc (TabInt * T){
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
    ElType temp;
    IdxType i,j;
    if (Neff(*T) > 1) {
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

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (IsEmpty(*T)) {
        Elmt(*T, GetFirstIdx(*T)) = X;  
    } else {
        Elmt(*T, GetLastIdx(*T)+1) = X;
    }
    Neff(*T)++;
}
void AddEli (TabInt * T, ElType X, IdxType i){
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
    IdxType j;
    if (i > GetLastIdx(*T)) {
        Elmt(*T, i) = X;
    } else {
        for (j = GetLastIdx(*T); j >= i; j--) {
            Elmt(*T, j+1) = Elmt(*T, j);
        }
        Elmt(*T, i) = X;
    }
    Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}
void DelEli (TabInt * T, IdxType i, ElType * X){
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
    IdxType j;
    *X = Elmt(*T, i);
    if (i < GetLastIdx(*T)) {
        for (j = i; j <= GetLastIdx(*T)-1; j++) {
            Elmt(*T, j) = Elmt(*T, j+1);
        }
    }
    Neff(*T)--;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
    if (SearchSentinel(*T, X)) {
        printf("nilai sudah ada\n");
    } else {
        if (IsEmpty(*T)) {
            Elmt(*T, GetFirstIdx(*T)) = X;
        } else {
            Elmt(*T, GetLastIdx(*T)+1) = X;
        }
        Neff(*T)++;
    }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
    boolean found = false;
    IdxType i = GetFirstIdx(T);
    if (IsEmpty(T)) {
        return IdxUndef;
    } else {
        while (!found && (i <= GetLastIdx(T))) {
            if (Elmt(T, i) == X) found = true;
            else i++;
        }
        if (found) return i;
        else return IdxUndef;
    }
    
}
ElType MaxUrut (TabInt T){
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
    return Elmt(T, GetLastIdx(T));
}
ElType MinUrut (TabInt T){
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
    return Elmt(T, GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X){
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
    IdxType i = GetFirstIdx(*T);
    if (!(IsFull(*T))) {
        while (Elmt(*T,i) < X) i++;
        AddEli(T, X, i);
    }
}
void Del1Urut (TabInt * T, ElType X){
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
    IdxType i = Search1(*T, X);
    if (i != IdxUndef) DelEli(T, i, &X);
}