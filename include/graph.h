/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

// Maksimum simpul dari graph = maks bangunan
#define N  600

// Struktur data pake list of list jancok
typedef List infotypeGraph;
typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	infotypeGraph info;
	addressGraph next;
} ElmtGraph;
typedef struct {
	addressGraph FirstGraph;
} Graph;



#endif