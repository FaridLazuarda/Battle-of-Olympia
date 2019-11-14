/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"


// Maksimum simpul dari graph = maks bangunan
#define N  600

// Struktur data pake list of list jancok
typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	infotypeList info;
	List link;
	addressGraph next;
} ElmtGraph;
typedef struct {
	addressGraph First;
} Graph;

/* Definisi graph :
   Graph kosong : First(L) = Nil
   Setiap elemen dengan addressGraph P dapat diacu Info(P), Next(P)
   Elemen terakhir graph : jika addressnya Last, maka NextGraph(Last)=Nil */

/*	Penggunaan pada tubes:
	Graph digunakan untuk menyimpan indeks dari building pada array of building.
	contoh = graph untuk jumlah building 4
	file config =
   			0 1 1 1
   			1 0 0 0
   			1 0 0 1
   			1 0 1 0
	graph yang terjadi
		1 2->3->4
		2 1
		3 1->4
		4 1->3
*/

#define InfoGraph(P) (P)->info
#define NextGraph(P) (P)->next
#define Link(P) 	 (P)->link
#define FirstGraph(G) ((G).First)

void initGraph(Graph *G, int n);
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void AddLink(Graph *G, infotypeList n, infotypeList p);
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya (soalnya bolak balik)
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

boolean IsLinked(Graph *G, infotypeList n, infotypeList p);
/* Mengembalikan true jika pada link n ada p */

#endif