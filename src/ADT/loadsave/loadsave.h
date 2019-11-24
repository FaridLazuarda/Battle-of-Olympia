#ifndef loadsave_H
#define loadsave_H

#include "../stackt/stackt.h"
#include "../mesinkatamodif/mesinkatamodif.h"

void LoadConfig (Stack *S, MATRIKS * Peta, Graph * graf);
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Troop, Level, A, M, P, U, hasMove, hasAttack, Pos
   2. Player: queue skill, list building, isturn, shield, critical hit, attack up
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
/* contoh file hasil save
   1 (menandakan banyaknya elemen stack)
   6
   C 40 4    25 100 0 0   0 0   1 1
   F 30 1    10 20 0 80   1 0   1 5
   V 30 3    15 40 0 0    0 0   2 7
   T 30 3    20 40 1 0    0 0   2 2
   C 40 2    15 60 0 0    0 0   5 8
   V 10 2    10 30 0 0    0 0   8 4
   4 U S E A    4  1 2 3 4      1 0 0 0
   4 S E R A    2  5 6          0 1 0 0*/

void SaveConfig (Stack S);
/* menyimpan state ke dalam sebuah file */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Troop, Level, A, M, P, U, hasMove, hasAttack, Pos
   2. Player: queue skill, list building, isturn, shield, critical hit, attack up
   3. Turn: 1 kalo player 1, 2 kalo player 2 */
/* contoh file hasil save
   1 (menandakan banyaknya elemen stack)
   6
   C 40 4    25 100 0 0   0 0   1 1
   F 30 1    10 20 0 80   1 0   1 5
   V 30 3    15 40 0 0    0 0   2 7
   T 30 3    20 40 1 0    0 0   2 2
   C 40 2    15 60 0 0    0 0   5 8
   V 10 2    10 30 0 0    0 0   8 4
   4 U S E A    4  1 2 3 4      1 0 0 0
   4 S E R A    2  5 6          0 1 0 0*/

#endif
