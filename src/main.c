/* NANDA AND HIS JAVANESE FRIENDS */

#include "../include/stackt.h"
#include "../include/boolean.h"
#include "../include/state.h"

int main() {
    
    Stack gameState;
    STATE this;
    boolean shield;
    boolean endGame;
    boolean extraTurn;
    char input[20];
    char currentSkill; 

    // inisiasi game
    NewGame(this, arrOfBuilding, building1, building2);
    IsTurn(P1(this)) = true;

    while (!endGame) {
        // ini graph

        printf("Player ");
        if (IsTurn(P1(this))) printf("1\n");
        else printf("2\n");
        PrintDaftarBangunan(P1(this));
        printf("Skill Available: ");

        // scan command
        scanf("%s", input);

        if (input == "END_TURN") {
            if (!extraTurn) {
                IsTurn(P1(this)) = false;
                IsTurn(P2(this)) = true;
            } else {
                extraTurn = false;
            }
            while (!IsEmpty(gameState)) {
                Pop(gameState);
            }
        } else if (input == SKILL) {
            if (CheckTurn(this) == P1(this)) Del(&Skill(P1(this)), &currentSkill);
            else Del(&Skill(P1(this)), &currentSkill); // kalo turnnya P2

            // skill yang dijalankan
            if (currentSkill == 'U') InstantUpgrade(this);
            else if (currentSkill == 'S') Shield(this);
            else if (currentSkill == 'E') extraTurn = true;
            else if (currentSkill == 'A') AttackUp(this);
            else if (currentSkill == 'C') CriticalHit(this);
            else if (currentSkill == 'R') InstantReinforcement(this);
            else if (currentSkill == 'B') Barrage(this);
    }
    return 0;
}