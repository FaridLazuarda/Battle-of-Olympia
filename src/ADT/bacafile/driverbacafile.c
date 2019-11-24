#include "bacafile.h"
#include "../state/state.h"
#include "../matriks/matriks.h"
#include "../graph/graph.h"
#include "../player/player.h"
#include "../queue/queue.h"
#include <stdio.h>

int main(){
    STATE S;
    MATRIKS Peta;
    Graph graf;
    PLAYER P;
    infotypequeue info;
    InitPlayer(&P, 2);
    InfoHead(Skill(P)) = 'U';
    Add(&Skill(P), 'S');
    ExtractConfigFile(&S, &Peta, &graf);
    TulisPOINT(Pos(ElmtArrDin(Buildings(S), 1)));
    TulisPOINT(Pos(ElmtArrDin(Buildings(S), 2)));
    printf("\n%c\n", InfoHead(Skill(P1(S))));
    printf("%c\n", InfoHead(Skill(P)));
    Del(&Skill(P), &info);
    printf("%c\n", InfoHead(Skill(P)));
}
