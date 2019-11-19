/* ********** Definisi TYPE PLAYER ********** */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"


#define SkillMax 10

typedef struct {
    int n; // buat nama doang si hehe
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
} PLAYER;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Selektor *** */
#define Skill(P) (P).Skill
#define OwnBuilding(P)   (P).Own
#define IsTurn(P) (P).IsTurn
#define Nama(P) (P).n
#define ActiveShield(P) (P).Shield

/* *** Konstruktor *** */
void InitPlayer (PLAYER * P, int n);
/* I. S. PLAYER P sembarang */
/* F. S. PLAYER P terdefinisi dengan skill instant upgrade dan building sesuai konfigurasi awal */

/* *** Fungsi Lain *** */
void AddBuilding (PLAYER * P, infotypeList x);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki building dengan indeks x */

void AddSkill (PLAYER * P, infotypequeue S);
/* I. S. PLAYER P terdefinisi */
/* F. S. PLAYER P memiliki skill */

void PrintSkill(PLAYER P);
void PrintBangunanPlayer(PLAYER P);

boolean IsEqual(PLAYER P1, PLAYER P2);
/* mengembalikan true jika P1 == P2 */

boolean IsOwnBuilding (PLAYER P, int n);
/* mengembalikan true jika pada indeks n adalah building milik P */
#endif