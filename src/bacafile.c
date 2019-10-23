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
#include "mesinkar.h"
#include "matriks.h"

void ExtractConfigFile (MATRIKS M);
{
	START();
}

/* *** Selektor: Untuk sebuah File "configFile" yang terdefinisi: *** */
int GetBrsPeta (FILE * configFile);
/* Mengirimkan banyaknya baris peta permainan dari File Konfigurasi */
int GetKolPeta (FILE * configFile);
/* Mengirimkan banyaknya kolom peta permainan dari File Konfigurasi */

/* *** Ekstraktor informasi penting mengenai Building dari sebuah File "configFile" yang terdefinisi: *** */
void ExtractBuildingConf (FILE * configFile);
/* Mengekstraksi konfigurasi Building di permainan dari File Konfigurasi */
void ExtractGraphConf (FILE * configFile);
/* Mengekstraksi graf keterhubungan tiap pasang bangunan di permainan dari File Konfigurasi */

#endif