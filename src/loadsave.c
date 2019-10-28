#include "../include/loadsave.h"
#include <stdio.h>
#include <string.h>

void LoadConfig (STATE *S)
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
{
    
}

void SaveConfig (STATE S)
/* menyimpan state ke dalam sebuah file */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
   // ntaran dah ditambah graf bgst
   // sama matriks peta
{
    FILE * config;
    char namafile[20];
    printf("Masukkan nama file untuk save: ");
    scanf("%s", namafile);
    strcat(namafile, "../file/");
    config = fopen(namafile, "w");

    //print banyaknya building
    fprintf(config, "%d\n", NbElmtArr(OwnBuilding(S)));
    // print building
    for (int i = 1; i <= NbElmtArr(OwnBuilding(S)); i++) {
        fprintf(config, "%c ", Kind(Elmt(OwnBuilding(S), i)));
        fprintf(config, "%d ", Owner(Elmt(OwnBuilding(S), i)));
        fprintf(config, "%d ", Troop(Elmt(OwnBuilding(S), i)));
        fprintf(config, "%d\n", Level(Elmt(OwnBuilding(S), i)));
        // contoh:
        // C 2 40 4
        // F 0 50 1
    }

    // print player
    
}