#include <stdio.h>
#include "mesinkatamodif.h"

boolean EndKataLOAD;
KataLOAD CKataLOAD;

void IgnoreBlankLOAD()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CCLOAD sembarang
   F.S. : CCLOAD ≠ BLANK atau CCLOAD = MARK */
{
    while (CCLOAD == BLANK)
    {
        ADVLOAD();
    }
}

void IgnoreEOL()
/* Mengabaikan end of line
   I.S. : CCLOAD sembarang
   F.S. : CCLOAD ≠ EOL atau CCLOAD = MARK */
{
    while (CCLOAD == EOL)
    {
        ADVLOAD();
    }
    
}

void STARTKATALOAD()
/* I.S. : CCLOAD sembarang
   F.S. : EndKataLOAD = true, dan CCLOAD = MARK;
          atau EndKataLOAD = false, CKataLOAD adalah kata yang sudah diakuisisi,
          CCLOAD karakter pertama sesudah karakter terakhir kata */
{
    STARTLOAD();
    IgnoreBlankLOAD();
    IgnoreEOL();
    if (CCLOAD == MARK) {
        EndKataLOAD = true;
    } else {
        EndKataLOAD = false;
        SalinKataLOAD();
    }
}

void ADVKATALOAD()
/* I.S. : CCLOAD adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKataLOAD adalah kata terakhir yang sudah diakuisisi,
          CCLOAD adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CCLOAD = MARK, EndKataLOAD = true.
   Proses : Akuisisi kata menggunakan procedure SalinKataLOAD */
{
    IgnoreBlankLOAD();
    IgnoreEOL();
    if (CCLOAD == MARK) EndKataLOAD = true;
    else SalinKataLOAD();
    IgnoreBlankLOAD();
    IgnoreEOL();
}

void SalinKataLOAD()
/* Mengakuisisi kata, menyimpan dalam CKataLOAD
   I.S. : CCLOAD adalah karakter pertama dari kata
   F.S. : CKataLOAD berisi kata yang sudah diakuisisi;
          CCLOAD = BLANK atau CCLOAD = MARK atau CCLOAD = EOL;
          CCLOAD adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while (CCLOAD != BLANK && CCLOAD != EOL && CCLOAD != MARK && i < NMax)
    {
        i++;
        CKataLOAD.TabKata[i] = CCLOAD;
        ADVLOAD();
    }
    CKataLOAD.Length = i;
}
