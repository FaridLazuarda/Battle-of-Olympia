/* Buat fungsi ynag gatau mau ditaro di mana */

#include "../boolean/boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkatamodif/mesinkatamodif.h"
#include "../state/state.h"
#include "../matriks/matriks.h"
#include "../pcolor/pcolor.h"
boolean IsKataSama (const char * b);
/* mengembalikan true jika string ckata = string b*/

int angka();
/* mengembalikan angka dari CKata, bukan CKataLOAD */

// int angkaLOAD();
/* mengembalikan angka dari CKataLOAD, bukan CKata */

void printKata();
/* I. S. CKata terdefinisi */
/* F. S. CKata diprint di layar */

void NewGame();
/* I. S. Game belum dimulai *?
/* F. S. Game dimulai dengan config yang sudah diekstrak */

void PrintPeta(STATE S, MATRIKS M);
/* Untuk print peta */
