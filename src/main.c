/* NANDA AND HIS JAVANESE FRIENDS */
#include <stdio.h>
#include <stdlib.h>
#include "../include/stackt.h"
#include "../include/boolean.h"
#include "../include/state.h"
#include "../include/matriks.h"
#include "../include/graph.h"
#include "../include/bacafile.h"
#include "../include/mesinkata.h"
#include "../include/utils.h"
#include "../include/loadsave.h"

int main() {
    
    Stack gameState;
    STATE this;
    STATE trash;
    boolean shield;
    boolean endGame;
    boolean extraTurn;
    char currentSkill; 
    MATRIKS peta;
    Graph graf;

    // inisiasi game
    ExtractConfigFile(&this, &peta, &graf);
    IsTurn(P1(this)) = true;
    endGame = false;
    CreateEmpty(&gameState);
    
    while (!endGame) {
        PrintPeta(this, peta);
        printf("Player ");
        if (IsTurn(P1(this))) printf("1\n");
        else printf("2\n");
        PrintDaftarBangunanPlayer(this);
        printf("Skill Available: ");
        if (IsTurn(P1(this))) PrintSkill(P1(this));
        else PrintSkill(P2(this));
        printf("\nENTER COMMAND: ");
        // scan command
        STARTKATA();

        if (IsKataSama("ATTACK")) {
            ATTACK(&this, graf);
            Push(&gameState, this);
        } else if (IsKataSama("SKILL")) {
            currentSkill = 'X';
            if (IsTurn(P1(this))) {
                if (!IsQueueEmpty(Skill(P1(this)))) Del(&Skill(P1(this)), &currentSkill);
                else printf("Anda tidak mempunyai skill!\n");
            } else {
                if (!IsQueueEmpty(Skill(P2(this)))) Del(&Skill(P2(this)), &currentSkill); // kalo turnnya P2
                else printf("Anda tidak mempunyai skill!\n");
            }
            // skill yang dijalankan
            if (currentSkill == 'U') InstantUpgrade(&this);
            else if (currentSkill == 'S') Shield(&this);
            else if (currentSkill == 'E') extraTurn = true;
            else if (currentSkill == 'A') AttackUp(&this);
            else if (currentSkill == 'C') CriticalHit(&this);
            else if (currentSkill == 'R') InstantReinforcement(&this);
            else if (currentSkill == 'B') Barrage(&this);
            while (!IsEmpty(gameState)) {
                Pop(&gameState, &trash);
            }
        } else if (IsKataSama("LEVEL_UP")) {
            LEVEL_UP(&this);
            Push(&gameState, this);
        } else if (IsKataSama("END_TURN")) {
            
            //buat nonaktifin skill
            if (IsTurn(P1(this))) {
                // skill
                if (ActiveShield(P1(this)) > 1) {
                    ActiveShield(P1(this))--;
                }
                // attack up
                ActiveAttUp(P1(this)) = false;

                // critical hit
                ActiveCritHit(P1(this)) = false;
            } else {
                // skill
                if (ActiveShield(P2(this)) > 1) {
                    ActiveShield(P2(this))--;
                }
                // attack up
                ActiveAttUp(P2(this)) = false;

                // critical hit
                ActiveCritHit(P2(this)) = false;
            }
            // mengakhiri turn
            if (!extraTurn) {
                if (IsTurn(P1(this))) {
                    IsTurn(P1(this)) = false;
                    IsTurn(P2(this)) = true;
                } else { // kalo p2 yang lagi main
                    IsTurn(P2(this)) = false;
                    IsTurn(P1(this)) = true;
                }
            }
            while (!IsEmpty(gameState)) {
                Pop(&gameState, &trash);
            }
        } else if (IsKataSama("EXIT")) {
            endGame = true;
        } else if (IsKataSama("UNDO")) {
            Pop(&gameState, &this);
        } else if (IsKataSama("SAVE")) {
            SaveConfig(this);
        } else if (IsKataSama("LOAD")) {
            LoadConfig(&this);
        }

        
        
    }
    return 0;
}

// int main(){
//     // STATE S;
//     MATRIKS Peta;
//     Graph graf;
//     ExtractConfigFile(&Peta, &graf);
//     TulisMATRIKS(Peta);

//     return 0;
// }