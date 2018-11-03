#ifndef EKSTERNAL_H
#define EKSTERNAL_H

#include "../../std.h"
#include "../../ADT.h"
#include "../../ADT/space/space.h"

void ParserLocate(Kata input,int *pos1, int *pos2);
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/

Kata ParseNama(Kata scanned);
/* parsing nama*/

Tile ParseTile(Kata scanned);
/* mengembalikan tipe tile dari hasil parsing kata */

Meja ParseMeja(Kata scanned);
/* mengembalikan tipe meja dari hasil parsing kata */

customer ParseCostumer(Kata scanned);
/* mengembalikan tipe customer dari hasil parsing kata */

Door ParseDoor(Kata scanned);
/* mengembalikan tipe door dari hasil parsing kata */

Ruangan ParseRuangan(Kata X);
/*CKata berada di banyak elemen ruangan/x, mengambil X kata berikutnya menjadi Ruangan*/

MatTile TakeMatTile(Kata X);
/*CKata berada di jumlah tile yg akan diambil/X, mengambil X kata berikutnya menjadi elemen MatTile*/

ArrMeja TakeArrMeja(Kata X);
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/

Restoran ParseRestoran();
/*CKata berada di kata restoran*/

GrafRuangan ParseGrafRuangan(Kata X);
/*Ckata berada di jumlah komponen rungan, mengambil X bagian berikutnya menjadi grafruangan*/

void LoadFile(char* namafile,int* status, Kata* nama,int* money, int* life, int* waktu,Restoran* restoran);
/*  F.S. status memberikan status apakah file berhasil di load atau tidak
  parameter sisanya berisi data sesuai file eksternal
  */

#endif
