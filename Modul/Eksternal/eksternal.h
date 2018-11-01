#ifndef EKSTERNAL_H
#define EKSTERNAL_H

#include "../../header/std.h"
#include "../Map + Movement/space.h"

void ParserLocate(Kata input,int *pos1, int *pos2, int *pos3);
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/
Tile ParseTile(Kata scanned);
/* mengembalikan tipe tile dari hasil parsing kata */

//customer ParseCostumer(Kata buffer);

#endif
