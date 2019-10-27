/* ********** Definisi TYPE PLAYER ********** */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"


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
    List Own; //buat nyimpen building punya dia
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
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan building sesuai konfigurasi awal */

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, infotypeList x);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building dengan indeks x */

void AddSkill (PLAYER * P, infotype S);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki skill */

void PrintSkill(PLAYER P);

#endif