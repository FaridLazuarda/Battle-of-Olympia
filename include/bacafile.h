/* File : bacafile.h */
/* File header dari "bacafile.c" untuk mengekstraksi informasi mengenai konfigurasi bangunan dan peta dalam permainan */

#ifndef BACAFILE_H
#define BACAFILE_H

#include "boolean.h"
#include "building.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "mesinkatamodif.h"
#include "matriks.h"
#include "state.h"

void ExtractConfigFile (STATE * S, MATRIKS * Peta);

/* *** Selektor: Untuk sebuah File "configFile" yang terdefinisi: *** */
int GetBrsPeta (STATE S);
/* Mengirimkan banyaknya baris peta permainan dari File Konfigurasi */
int GetKolPeta (STATE S);
/* Mengirimkan banyaknya kolom peta permainan dari File Konfigurasi */

/* *** Ekstraktor informasi penting mengenai Building dari sebuah File "configFile" yang terdefinisi: *** */
TabBuilding ExtractBuildingConf (STATE S);
/* Mengekstraksi konfigurasi Building di permainan dari File Konfigurasi */
MATRIKS ExtractGraphConf (STATE S);
/* Mengekstraksi graf keterhubungan tiap pasang bangunan di permainan dari File Konfigurasi */

#endif