#include "../include/graph.h"

void initGraph(Graph *G, int n){}
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void AddLink(Graph *G, infotypeList n, infotypeList p){}
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

boolean IsLinked(Graph *G, infotypeList n, infotypeList p){}
/* Mengembalikan true jika pada link n ada p */