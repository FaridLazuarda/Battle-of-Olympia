/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "../include/mesinkarmodif.h"
#include <stdio.h>

char CCLOAD;
boolean EOPLOAD;

static FILE * pita;
static int retval;

void STARTLOAD() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CCLOAD adalah karakter pertama pada pita. Jika CCLOAD != MARK maka EOPLOAD akan padam (false).
          Jika CCLOAD = MARK maka EOPLOAD akan menyala (true) */
/* nama file tidak boleh lebih dari 20 karakter */

    /* KAMUS LOKAL */
    char namafile[100];
    /* Algoritma */
<<<<<<< HEAD
    // printf("Masukkan nama file config: ");
    // STARTKATA();
    pita = fopen("yes.txt","r");
=======
    printf("Masukkan nama file config: ");
    STARTKATA();
    namafile[0] = '.';
    namafile[1] = '.';
    namafile[2] = '/';
    namafile[3] = 't';
    namafile[4] = 'e';
    namafile[5] = 's';
    namafile[6] = 't';
    namafile[7] = '/';
    for (int i=1;i<=CKata.Length;i++)
    {
        namafile[i+7] = CKata.TabKata[i];
    }
    namafile[CKata.Length+8] = '\0';
    printf("%s", namafile);
    pita = fopen(namafile,"r");
>>>>>>> 2ce26c7b31f32089489de93fd7cc0da092ad289d
    ADVLOAD();
}

void ADVLOAD() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CCLOAD, CCLOAD != MARK
   F.S. : CCLOAD adalah karakter berikutnya dari CCLOAD yang lama,
          CCLOAD mungkin = MARK.
          Jika  CCLOAD = MARK maka EOPLOAD akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CCLOAD);
    EOPLOAD = (CCLOAD == MARK);
    if (EOPLOAD) {
       fclose(pita);
    }
}