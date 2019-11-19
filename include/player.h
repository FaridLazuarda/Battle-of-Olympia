/* ********** Definisi TYPE PLAYER ********** */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"


#define SkillMax 10

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
    int Shield; //buat command shield jadi on kalo dia ngeaktifin 
    boolean CriticalHit;
    boolean AttackUp;
} PLAYER;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Selektor *** */
#define Skill(P) (P).Skill
#define OwnBuilding(P)   (P).Own
#define IsTurn(P) (P).IsTurn
#define ActiveShield(P) (P).Shield
#define ActiveAttUp(P) (P).AttackUp
#define ActiveCritHit(P) (P).CriticalHit

/* *** Konstruktor *** */
void InitPlayer (PLAYER * P);
/* I. S. PLAYER P sembarang */
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan building sesuai konfigurasi awal */

void CopyPlayer (PLAYER In, PLAYER *Out);

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, infotypeList x);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building dengan indeks x */

void AddSkill (PLAYER * P, infotypequeue S);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki skill */

void PrintSkill(PLAYER P);
void PrintBangunanPlayer(PLAYER P);

boolean IsOwnBuilding (PLAYER P, int n);
/* mengembalikan true jika pada indeks n adalah building milik P */
#endif