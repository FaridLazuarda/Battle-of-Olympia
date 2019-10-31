#ifndef loadsave_H
#define loadsave_H

#include "state.h"
#include "mesinkatamodif.h"
#include "queue.h"

void LoadConfig (STATE *S);
/* untuk load config yang sudah disave sebelumnya */
/* State itu isinya:
   1. TabBuilding : array of building isinya Kind, Owner, Troop, Level
   2. Player: queue skill sama list building
   3. Turn: 1 kalo player 1, 2 kalo player 2 */

void SaveConfig (STATE S);
/* menyimpan state ke dalam sebuah file */

#endif