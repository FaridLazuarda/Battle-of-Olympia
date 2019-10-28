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

    /* Algoritma */
    char namafile[20];
    printf("Masukkan nama file game sebelumnya: ");
    scanf("%s", namafile);
    pita = fopen(namafile,"r");
    ADV();
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