/* Kelompok  : UAS
   Nama file : door.h
   Deskripsi : ADT untuk tipe pintu */
/* merupakan tipe data ruangan */

#ifndef DOOR_H
#define DOOR_H

#include "../point/point.h"

/* Definisi struktur */
typedef struct{
  Point lokasi; /* Lokasi pintu */
  int direction; /* Atas 1, kanan 2, bawah 3, kiri 4 */
  int roomId; /* ID ruangan pintu tersebut ada */
} Door;

/* SELEKTOR */
#define DoorDirection(D) (D).direction
#define DoorLocation(D) (D).lokasi
#define DoorRoomID(D) (D).roomId

#endif
