/* Kelompok  : UAS
   Nama file : restoran.h
   Deskripsi : ADT untuk tipe restoran */
/* merupakan tipe data restoran */

#ifndef RESTORAN_H
#define RESTORAN_H

#include "grafRuangan/grafRuangan.h"

typedef struct {
  int roomNow;
  GrafRuangan ruangan; /* array yang berisi ruangan */
} Restoran;
/* tipe Restoran dengan 4 ruangan berukuran 8x8
   dengan terdapat 4 pintu yang menghubungkan keempat ruangan tersebut
*/
/*
  room1 (5,8) -> (2,1) room2
  room1 (8,5) -> (1,5) room4
  room2 (8,5) -> (1,5) room3
  room3 (2,1) -> (5,8) room4
*/
#define RoomNow(R) (R).roomNow
#define Ruangan(R) (R).ruangan

#endif
