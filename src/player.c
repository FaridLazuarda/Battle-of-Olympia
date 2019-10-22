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