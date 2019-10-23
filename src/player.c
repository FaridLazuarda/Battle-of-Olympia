/* Implementasi player.h */
#include <stdio.h>
#include "../include/player.h"

/* *** Konstruktor *** */
void InitPlayer (PLAYER * P)
/* I. S. PLAYER P sembarang */
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan tidak memiliki building */
{
    CreateEmpty(&Skill(*P), SkillMax);
    Add(&Skill(*P), 'U');
    MakeEmpty(&OwnBuilding(*P));
    IsTurn(*P) = False;
}

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, BUILDING B)
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building B */
{
    AddAsLastEl(&OwnBuilding(*P), B);
}

void AddSkill (PLAYER * P, infotype S)
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki skill */
{
    Add(&Skill(*P), S);
}

void PrintSkill(PLAYER P){
    /* Skill direpresentasikan ke dalam char:
       U = Instant Upgrade
       S = Shield
       E = Extra Turn
       A = Attack Up
       C = Critical Hit
       R = Instant Reinforcement
       B = Barrage */

    if (Head(Skill(P)) == 'U') {
        printf("IU");
    } else if (Head(Skill(P)) == 'S') {
        pritnf("S");
    } else if (Head(Skill(P)) == 'E') {
        pritnf("ET");
    } else if (Head(Skill(P)) == 'A') {
        pritnf("AU");
    } else if (Head(Skill(P)) == 'C') {
        pritnf("CH");
    } else if (Head(Skill(P)) == 'R') {
        pritnf("IR");
    } else if (Head(Skill(P)) == 'B') {
        pritnf("B");
    } else {
        printf("Tidak ada skill");
    }
}