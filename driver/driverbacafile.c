#include "../include/bacafile.h"
#include "../include/state.h"
#include "../include/matriks.h"
#include "../include/graph.h"

int main(){
    STATE S;
    MATRIKS Peta;
    Graph graf;
    ExtractConfigFile(&S, &Peta, &graf);
    TulisPOINT(Pos(ElmtArrDin(Buildings(S), 1)));
    TulisPOINT(Pos(ElmtArrDin(Buildings(S), 2)));
}