#ifndef loadsave_H
#define loadsave_H

#include "state.h"
#include "mesinkata.h"

void LoadConfig (STATE *S);
/* untuk load config yang sudah disave sebelumnya */

void SaveConfig (STATE S);
/* menyimpan state ke dalam sebuah file */

#endif