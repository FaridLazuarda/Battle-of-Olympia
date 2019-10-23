/* File : bacafile.h */
/* File header dari "bacafile.c" untuk mengekstraksi informasi mengenai konfigurasi bangunan dan peta dalam permainan */

#ifndef BACAFILE_H
#define BACAFILE_H

#include "bacafile.h"
#include "mesinkata.h"

void ExtractConfigFile (STATE * S);
{
	int TPeta, LPeta;
	int NbBuilding;
	int i, j;
	char read;
	char file_name[25];
	FILE * FileConfig;

    /* Algoritma */
    printf("%s","Masukkan nama file: " );
    scanf(file_name);
    FileConfig = fopen(file_name,"r");
	
	TPeta = CKata;
	ADVKATA;
	LPeta = CKata;

	/* Membaca jumlah Building dari FileConfig*/
	ADVKATA; //ENTER LINE
	NbBuilding = CKata;
	ADVKATA; //ENTER LINE

	/* Untuk membaca informasi mengenai posisi Building */
	for (i=1;i<=NbBuilding;i++)
	{

	}

	/* Untuk membaca informasi informasi mengenai graf keterhubungan tiap pasang bangunan dari matriks dalam FileConfig */
	for (i=1;i<=NbBuilding;i++)
	{
		for (j=1;j<=NbBuilding;j++)
		{

		}
	}
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