/* NANDA AND HIS JAVANESE FRIENDS */
#include <stdio.h>
#include <stdlib.h>
#include "ADT/stackt/stackt.h"
#include "ADT/boolean/boolean.h"
#include "ADT/state/state.h"
#include "ADT/matriks/matriks.h"
#include "ADT/graph/graph.h"
#include "ADT/bacafile/bacafile.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/utils/utils.h"
#include "ADT/loadsave/loadsave.h"
#include "ADT/player_sign/player_sign.h"

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
    char p1[20];
    char p2[20];

    // inisiasi game
    endGame = false;
    WelcomeMessage();
    printf("Pilih mode\n");
    printf("1. New Game\n2. Load Game\n");
    CKata.TabKata[1] = 3;
    while (angka() != 1 && angka() != 2) {
        printf("Masukkan pilihan: ");
        STARTKATA();
    }
    if (angka() == 1) {
        ExtractConfigFile(&this, &peta, &graf);
        IsTurn(P1(this)) = true;
        IsTurn(P2(this)) = false;
        CreateEmpty(&gameState);
        InitBuildingsTurn(&this);
    } else if (angka() == 2) {
        LoadConfig(&gameState, &peta, &graf);
        // TulisIsiTab(Buildings(InfoTop(gameState)));
        Pop(&gameState, &this);
        // TulisIsiTab(Buildings(this));
        // printf("\n%d\n", Info(Next(First(OwnBuilding(P1(this))))));
    }
    printf("Masukkan Nama Player 1: ");
    STARTKATA();
    for (int i=1;i<=CKata.Length;i++)
    {
        p1[i-1] = CKata.TabKata[i];
    }
    p1[CKata.Length] = '\0';
    
    printf("Masukkan Nama Player 2: ");
    STARTKATA();
    for (int i=1;i<=CKata.Length;i++)
    {
        p2[i-1] = CKata.TabKata[i];
    }
    p2[CKata.Length] = '\0';
    while (!endGame) {
        if (IsTurn(P1(this))) OneTurn(p1);
        else TwoTurn(p2);
        PrintPeta(this, peta);
        // PrintInfoBuilding(ElmtArrDin(Buildings(this), 1));
        // printf("%d ", Info(Next(First(OwnBuilding(P1(this))))));
        PrintDaftarBangunanPlayer(this, false, false);
        printf("Skill Available: ");
        if (IsTurn(P1(this))) PrintSkill(P1(this));
        else PrintSkill(P2(this));
        
        printf("\nENTER COMMAND: ");
        // scan command
        STARTKATA();

        if (IsKataSama("ATTACK")) {
            Push(&gameState, this);
            ATTACK(&this, graf);
            if ((IsTurn(P1(this))) && (NbElmt(OwnBuilding(P1(this))) == Neff(Buildings(this)))) {
                Congrats(p1);
                // printf("Selamat Player 1 kamu telah memenangkan permainan ini!\n");
                endGame = true;
            } else if ((IsTurn(P2(this))) && (NbElmt(OwnBuilding(P2(this))) == Neff(Buildings(this)))) {
                Congrats(p2);
                // printf("Selamat Player 2 kamu telah memenangkan permainan ini!\n");
                endGame = true;
            }
        } else if(IsKataSama("MOVE")){
            Push(&gameState, this);
            MOVE(&this, graf);
        }
        else if(IsKataSama("HELP"))
        {
            Help();
        }
        else if (IsKataSama("SKILL")) {
            currentSkill = 'X';
            if (IsTurn(P1(this))) {
                if (!IsQueueEmpty(Skill(P1(this)))) Del(&Skill(P1(this)), &currentSkill);
                else printf("Anda tidak mempunyai skill!\n");
            } else {
                if (!IsQueueEmpty(Skill(P2(this)))) Del(&Skill(P2(this)), &currentSkill); // kalo turnnya P2
                else printf("Anda tidak mempunyai skill!\n");
            }
            // skill yang dijalankan
            if (currentSkill == 'U') {
                InstantUpgrade(&this);
            } else if (currentSkill == 'S') {
                Shield(&this);
            } else if (currentSkill == 'E') {
                extraTurn = true;
                if (IsTurn(P1(this))) Add(&Skill(P2(this)), 'C');
                else Add(&Skill(P1(this)), 'C');
            } else if (currentSkill == 'A') {
                AttackUp(&this);
            } else if (currentSkill == 'C') {
                CriticalHit(&this);
            } else if (currentSkill == 'R') {
                InstantReinforcement(&this);
            } else if (currentSkill == 'B') {
                Barrage(&this);
            }
            while (!IsEmpty(gameState)) {
                Pop(&gameState, &trash);
            }
        } else if (IsKataSama("LEVEL_UP")) {
            Push(&gameState, this);
            LEVEL_UP(&this);
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

                // nambahin skill install reinforcement
                if (InsReinCheck(this)) Add(&Skill(P1(this)), 'R');
            } else {
                // skill
                if (ActiveShield(P2(this)) > 1) {
                    ActiveShield(P2(this))--;
                }
                // attack up
                ActiveAttUp(P2(this)) = false;

                // critical hit
                ActiveCritHit(P2(this)) = false;

                // nambahin skill install reinforcement
                if (InsReinCheck(this)) Add(&Skill(P2(this)), 'R');
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
            extraTurn = false;
            InitBuildingsTurn(&this);

            while (!IsEmpty(gameState)) {
                Pop(&gameState, &trash);
            }
        } else if (IsKataSama("EXIT")) {
            endGame = true;
        } else if (IsKataSama("UNDO")) {
            if (!IsEmpty(gameState)) {
                Pop(&gameState, &this);
            } else {
                 printf("Kamu tidak bisa undo!\n");
            }
        } else if (IsKataSama("SAVE")) {
            Push(&gameState, this);
            SaveConfig(gameState, peta, graf);
        } else {
            printf("Anda memasukkan command yang salah!\n");
        }
        printf("Tekan enter untuk melanjutkan!");
        STARTKATA();
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
