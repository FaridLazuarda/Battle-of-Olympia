/* File : bacafile.h */
/* File header dari "bacafile.c" untuk mengekstraksi informasi mengenai konfigurasi bangunan dan peta dalam permainan */

#ifndef BACAFILE_H
#define BACAFILE_H

#include "../boolean/boolean.h"
#include "../building/building.h"
#include "../mesinkatamodif/mesinkatamodif.h"
#include "../matriks/matriks.h"
#include "../state/state.h"
#include "../graph/graph.h"
#include "../utils/utils.h"

void ExtractConfigFile (STATE *S, MATRIKS * Peta, Graph * graf);


#endif
