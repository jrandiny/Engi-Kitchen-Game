//File : door.h
/* merupakan tipe data ruangan */

#ifndef DOOR_H
#define DOOR_H

#include "../point/point.h"

typedef struct{
  Point lokasi;
  int direction; //Atas 1, kanan 2, bawah 3, kiri 4
  int roomId;
} Door;

#define DoorDirection(D) (D).direction
#define DoorLocation(D) (D).lokasi
#define DoorRoomID(D) (D).roomId

#endif
