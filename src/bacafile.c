
#include "../include/bacafile.h"
#include <stdio.h>

void ExtractConfigFile (STATE * S, MATRIKS * Peta, Graph * graf)
{
	int TPeta, LPeta;
	int NbBuilding;
	int sumT, sumL, sumB, sumBr, sumKl;
	char read;
	addressGraph addr;

	/* Algoritma */
	STARTKATALOAD();
    for (int p = 1; p <= CKataLOAD.Length; p++) 
    {
        sumT = sumT * 10 + (CKataLOAD.TabKata[p] - '0');
    }
	TPeta = sumT;
	printf("%d", TPeta);
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
			Elmt(*Peta, p, q) = 'X';
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
		char JenisB = CKataLOAD.TabKata[1];//baca jenis bangunan
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

		Elmt(*Peta, k, l) = JenisB;
	}

	/* Untuk membaca informasi informasi mengenai graf keterhubungan tiap pasang bangunan dari matriks dalam FileConfig */
	// inisialisasi graf
	initGraph(graf, NbBuilding);
	for (int i=1;i<=NbBuilding;i++)
	{
		addr = FirstGraph(*graf);
		for (int j=1;j<=NbBuilding;j++)
		{
			if (CKataLOAD.TabKata[1] == '1') {
				AddLink(graf, i, j);
			}
			ADVKATALOAD();
		}
		addr = NextGraph(addr);
	}
}


