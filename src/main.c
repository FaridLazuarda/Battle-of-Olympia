/* NANDA AND HIS JAVANESE FRIENDS */
#include <stdio.h>
#include <stdlib.h>
#include "../include/stackt.h"
#include "../include/boolean.h"
#include "../include/state.h"
#include "../include/matriks.h"
#include "../include/graph.h"
#include "../include/bacafile.h"
// void NewGame(){}

// int main() {
    
//     Stack gameState;
//     STATE this;
//     STATE trash;
//     boolean shield;
//     boolean endGame;
//     boolean extraTurn;
//     char input[20];
//     char currentSkill; 

//     // inisiasi game
//     NewGame();
//     IsTurn(P1(this)) = true;

//     while (!endGame) {
//         // ini graph

//         printf("Player ");
//         if (IsTurn(P1(this))) printf("1\n");
//         else printf("2\n");
//         PrintBangunanPlayer(P1(this));
//         printf("Skill Available: ");

//         // scan command
//         scanf("%s", input);

//         if (input == "END_TURN") {
//             if (!extraTurn) {
//                 IsTurn(P1(this)) = false;
//                 IsTurn(P2(this)) = true;
//             } else {
//                 extraTurn = false;
//             }
//             while (!IsEmpty(gameState)) {
//                 Pop(&gameState, &trash);
//             }
//         } else if (input == "SKILL") {
//             if (IsEqual(CheckTurn(this), P1(this))) Del(&Skill(P1(this)), &currentSkill);
//             else Del(&Skill(P1(this)), &currentSkill); // kalo turnnya P2

//             // skill yang dijalankan
//             if (currentSkill == 'U') InstantUpgrade(&this);
//             else if (currentSkill == 'S') Shield(&this);
//             else if (currentSkill == 'E') extraTurn = true;
//             else if (currentSkill == 'A') AttackUp(&this);
//             else if (currentSkill == 'C') CriticalHit(&this);
//             else if (currentSkill == 'R') InstantReinforcement(&this);
//             else if (currentSkill == 'B') Barrage(&this);
//         }
//     }
//     return 0;
// }

int main(){
    // STATE S;
    MATRIKS Peta;
    Graph graf;
    ExtractConfigFile(&Peta, &graf);
    TulisMATRIKS(Peta);

    return 0;
}