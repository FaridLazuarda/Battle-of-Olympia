
#include "../include/bacafile.h"
#include "../include/mesinkatamodif.h"
#include "../include/state.h"
#include "../include/matriks.h"

static FILE * FileConfig;
void ExtractConfigFile (STATE * S, MATRIKS * Peta)
{
	int TPeta, LPeta;
	int NbBuilding;
	int sumT, sumL, sumB, sumBr, sumKl;
	char read;
	char file_name[25];

    /* Algoritma */
    printf("%s","Masukkan nama file: " );
    scanf(file_name);
    FileConfig = fopen(file_name,"r");
	
	STARTKATALOAD();
    for (int p = 1; p <= CKataLOAD.Length; p++) 
    {
        sumT = sumT * 10 + (CKataLOAD.TabKata[p] - '0');
    }
	TPeta = sumT;

	ADVKATALOAD;
	STARTKATALOAD();
    for (int p = 1; p <= CKataLOAD.Length; p++) {
        sumL = sumL * 10 + (CKataLOAD.TabKata[p] - '0');
    }
	LPeta = sumL;

	/* Membuat matriks untuk menampung info bangunan dalam peta */
	MakeMATRIKS(TPeta, LPeta, Peta);
	for (int p=1; p<=TPeta; p++)
	{
		for (int q=1;q<=LPeta; p++)
		{
			Elmt(Peta, p, q) = 'X';
		}
	}

	/* Membaca jumlah Building dari FileConfig*/
	ADVKATALOAD; // ENTER LINE
	for (int p = 1; p <= CKataLOAD.Length; p++) 
    {
        sumB = sumB * 10 + (CKataLOAD.TabKata[p] - '0');
    }
    NbBuilding = sumB;
	ADVKATALOAD; // ENTER LINE

	/* Untuk membaca informasi mengenai posisi Building & mencatatnya di sebuah matriks Peta */
	for (int i=1;i<=NbBuilding;i++)
	{
		char JenisB = CKata.TabKata[1];//baca jenis bangunan
		ADVKATALOAD;
		for (int p = 1; p <= CKataLOAD.Length; p++) 
	    {
	        sumBr = sumBr * 10 + (CKataLOAD.TabKata[p] - '0');
	    }
		int k = sumBr;//baca baris karakter

		ADVKATALOAD;
		for (int p = 1; p <= CKataLOAD.Length; p++) 
	    {
	        sumKl = sumKl * 10 + (CKataLOAD.TabKata[p] - '0');
	    }
		int l = sumKl;//baca kolom karakter
		ADVKATALOAD; // ENTER LINE

		Elmt(Peta, k, l) = JenisB;
	}

	/* Untuk membaca informasi informasi mengenai graf keterhubungan tiap pasang bangunan dari matriks dalam FileConfig */
	for (int i=1;i<=NbBuilding;i++)
	{
		for (int j=1;j<=NbBuilding;j++)
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

