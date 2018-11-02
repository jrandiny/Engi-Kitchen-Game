//File : ruangan.h
/* merupakan tipe data ruangan */

#ifndef RUANGAN_H
#define RUANGAN_H

#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"

typedef struct {
  int id;
  MatTile room; //peta matriks ruangan
  ArrMeja meja; //array of meja
} Ruangan;
/*
  merupakan tipe ruangan yang akan dimasukkan ke dalam
  array of ruangan.
*/

#define RoomID(R) (R).id
#define Room(R) (R).room
#define Meja(R) (R).meja

#endif
