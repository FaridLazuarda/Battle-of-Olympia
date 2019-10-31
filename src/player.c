/* Implementasi player.h */
#include <stdio.h>
#include "../include/player.h"

/* *** Konstruktor *** */
void InitPlayer (PLAYER * P, int n)
/* I. S. PLAYER P sembarang */
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan TIDAK memiliki building */
{

    CreateEmptyQueue(&Skill(*P), SkillMax);
    Add(&Skill(*P), 'U');
    IsTurn(*P) = false;
    CreateEmptyList(&OwnBuilding(*P));
    Nama(*P) = n;
}

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, infotypeList x)
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building B */
{
    InsVLast(&OwnBuilding(*P), x);
}

void AddSkill (PLAYER * P, infotypequeue S)
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
        printf("S");
    } else if (Head(Skill(P)) == 'E') {
        printf("ET");
    } else if (Head(Skill(P)) == 'A') {
        printf("AU");
    } else if (Head(Skill(P)) == 'C') {
        printf("CH");
    } else if (Head(Skill(P)) == 'R') {
        printf("IR");
    } else if (Head(Skill(P)) == 'B') {
        printf("B");
    } else {
        printf("Tidak ada skill");
    }
}

void PrintBangunanPlayer(PLAYER P){}

boolean IsEqual(PLAYER P1, PLAYER P2)
/* mengembalikan true jika P1 == P2 */
{
    return Nama(P1) == Nama(P2);
}