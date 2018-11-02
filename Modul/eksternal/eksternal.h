#ifndef EKSTERNAL_H
#define EKSTERNAL_H

#include "../../std.h"
#include "../../ADT.h"
#include "../../ADT/space/space.h"

void ParserLocate(Kata input,int *pos1, int *pos2, int *pos3);
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/
Tile ParseTile(Kata scanned);
/* mengembalikan tipe tile dari hasil parsing kata */

Meja ParseMeja(Kata scanned);
/* mengembalikan tipe meja dari hasil parsing kata */

customer ParseCostumer(Kata scanned);
/* mengembalikan tipe customer dari hasil parsing kata */

Ruangan ParseRuangan(Kata X);
/*CKata berada di banyak elemen ruangan/x, mengambil X kata berikutnya menjadi Ruangan*/

MatTile TakeMatTile(Kata X);
/*CKata berada di jumlah tile yg akan diambil/X, mengambil X kata berikutnya menjadi elemen MatTile*/

ArrMeja TakeArrMeja(Kata X);
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/

ArrRuangan TakeArrRuangan(Kata X);
/*CKata berada di jumlah ruangan yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrRuangan*/

#endif
