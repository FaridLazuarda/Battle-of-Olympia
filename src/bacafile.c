
#include "../include/bacafile.h"
#include "../include/mesinkata.h"
#include "../include/state.h"
#include "../include/matriks.h"

static FILE * FileConfig;
void ExtractConfigFile (STATE * S, MATRIKS * Peta)
{
	int TPeta, LPeta;
	int NbBuilding;
	int i, j;
	char read;
	char file_name[25];

    /* Algoritma */
    printf("%s","Masukkan nama file: " );
    scanf(file_name);
    FileConfig = fopen(file_name,"r");
	
	TPeta = CKata;
	ADVKATA;
	LPeta = CKata;
	MakeMATRIKS(TPeta, LPeta, Peta);

	/* Membaca jumlah Building dari FileConfig*/
	ADVKATA; // ENTER LINE
	NbBuilding = CKata;
	ADVKATA; // ENTER LINE

	/* Untuk membaca informasi mengenai posisi Building & mencatatnya di sebuah matriks Peta */
	for (i=1;i<=NbBuilding;i++)
	{
		char JenisB = CKata;//baca jenis bangunan
		ADVKATA;
		int k = CKata;//baca baris karakter
		ADVKATA;
		int l = CKata;//baca kolom karakter
		ADVKATA; // ENTER LINE

		Elmt(Peta, k, l) = JenisB;
	}

	/* Untuk membaca informasi informasi mengenai graf keterhubungan tiap pasang bangunan dari matriks dalam FileConfig */
	for (i=1;i<=NbBuilding;i++)
	{
		for (j=1;j<=NbBuilding;j++)
		{

		}
	}
}

void NewGame (File * FileConfig, STATE * S)
{

}

/* *** Selektor: Untuk sebuah File "configFile" yang terdefinisi: *** */
int GetBrsPeta (STATE S){}
/* Mengirimkan banyaknya baris peta permainan dari File Konfigurasi */
int GetKolPeta (STATE S){}
/* Mengirimkan banyaknya kolom peta permainan dari File Konfigurasi */

/* *** Ekstraktor informasi penting mengenai Building dari sebuah File "configFile" yang terdefinisi: *** */
TabBuilding ExtractBuildingConf (STATE S){}
/* Mengekstraksi konfigurasi Building di permainan dari File Konfigurasi */
MATRIKS ExtractGraphConf (STATE S){}
/* Mengekstraksi graf keterhubungan tiap pasang bangunan di permainan dari File Konfigurasi */

