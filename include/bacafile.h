/* File : bacafile.h */
/* File header dari "bacafile.c" untuk mengekstraksi informasi mengenai konfigurasi bangunan dan peta dalam permainan */

#ifndef BACAFILE_H
#define BACAFILE_H

#include "boolean.h"
#include "building.h"
#include "mesinkatamodif.h"
#include "matriks.h"
#include "state.h"
#include "graph.h"

void ExtractConfigFile (STATE * S, MATRIKS * Peta, Graph * graf);


#endif