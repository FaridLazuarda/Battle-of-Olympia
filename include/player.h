/* ********** Definisi TYPE PLAYER ********** */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "array.h"

#define SkillMax 100

typedef struct {
    Queue Skill;
    /* Skill direpresentasikan ke dalam char:
       U = Instant Upgrade
       S = Shield
       E = Extra Turn
       A = Attack Up
       C = Critical Hit
       R = Instant Reinforcement
       B = Barrage */
    TabBuilding Own; //buat nyimpen building punya dia
    boolean IsTurn;
} PLAYER;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Selektor *** */
#define Skill(P) (P).Skill
#define OwnBuilding(P)   (P).Own
#define IsTurn(P) (P).IsTurn

/* *** Konstruktor *** */
void InitPlayer (PLAYER * P);
/* I. S. PLAYER P sembarang */
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan tidak memiliki building */

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, BUILDING B);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building B */

void AddSkill (PLAYER * P, infotype S);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki skill */



#endif