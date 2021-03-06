#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    Graph G;
    addressGraph P;

    CreateEmptyGraph(&G);
    initGraph(&G, 3);
    AddLink(&G, 1, 3);
    AddLink(&G, 1, 2);
    AddLink(&G, 1, 3);
    PrintGraph(G);
    PrintLink(G, 1);
    PrintLink(G, 2);

    if (IsLinked(G, 1, 3)) {
        printf("yay");
    } else {
        printf("loh");
    }
}
