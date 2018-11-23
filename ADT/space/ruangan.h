/* Kelompok  : UAS
   Nama file : ruangan.h
   Deskripsi : ADT untuk tipe ruangan */
/* merupakan tipe data ruangan */

#ifndef RUANGAN_H
#define RUANGAN_H

#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"

/* Definisi struktur */
typedef struct {
  int id;       /* ID ruangan */
  MatTile room; /* Matriks tile ruangan */
  ArrMeja meja; /* Array meja-meja di dalam ruangan */
} Ruangan;
/*
  merupakan tipe ruangan yang akan dimasukkan ke dalam
  array of ruangan.
*/

/* SELEKTOR */
#define RoomID(R) (R).id
#define Room(R) (R).room
#define Meja(R) (R).meja

#endif
